/*
 * MasterProcess.cc
 *
 *  Created on: Mar 8, 2013
 *      Author: s29zhu
 */

#include "UCACPacket_m.h"
#include "pbc/pbc.h"
#include "time.h"

using namespace std;
class MasterProcess : public cSimpleModule
{
  private:
    UCACRedirectPacket *msg_temp;
    pairing_t pairing;
    element_t g, h, f, beta, nounce;
    UCACTokenPacket *token_packet;
    bool attr_received;
    string attr[NUM_SHARE];
    Token *sk_token;
    int consumerAddr;
    int masterAddr;
    int attributeAddr;
    int resourceAddr;
    int ownerAddr;
    int authorityProcId;
    cGate *parentOutGate;
  public:
    MasterProcess() : cSimpleModule(0) {}
    virtual void handleMessage(cMessage *msg);
    virtual void initialize();
};

Define_Module( MasterProcess );

void MasterProcess::initialize(){
    cModule *parentMod = getParentModule();
    // retrieve parent's out gate
    parentOutGate = parentMod->gate("port$o");
    msg_temp = new UCACRedirectPacket("", REDIRECT);
    attr_received = false;
    int i = 0;
    // assign server address: index of Switch's gate to which severs are connected
    int maxIndex = parentOutGate->getNextGate()->size()-1;
    consumerAddr = maxIndex-3; WATCH(consumerAddr);
    masterAddr = maxIndex-2; WATCH(masterAddr);
    attributeAddr = maxIndex-1; WATCH(attributeAddr);
    resourceAddr = maxIndex; WATCH(resourceAddr);
    token_packet = NULL;
    /*cMessage *starter = new cMessage("authorizer start message", 100);
    simtime_t current_time = simTime();
    scheduleAt(current_time + 0.01, starter);*/

    element_t  beta_inverse;
    /*generate private and public keys of owner*/
    char s[16384];
    char *str_read, *str1;
   //signed long int temp_share;
    FILE *fp = stdin;

    fp = fopen("public/a.param", "r");
    if (!fp)
        pbc_die("error opening parameter file");
    size_t count = fread(s, 1, 16384, fp);
    if(!count)
        pbc_die("read parameter failure\n");
    fclose(fp);
    if(pairing_init_set_buf(pairing, s, count))
        pbc_die("pairing init failed\n");
    if(!pairing_is_symmetric(pairing)) pbc_die("pairing is not symmetric\n");

    element_init_G1(g, pairing);
    element_init_G1(h, pairing);
    element_init_G1(f, pairing);
    element_init_Zr(beta, pairing);
    element_init_Zr(beta_inverse, pairing);
    element_init_Zr(nounce, pairing);
    sk_token = new Token;
    element_init_G1(sk_token->D, pairing);
      for(i = 0; i < NUM_SHARE; i++){
        element_init_G1(sk_token->Di[i], pairing);
        element_init_G1(sk_token->Di_prime[i], pairing);
    }
    str_read = (char *)malloc(sizeof(char)*500);
    str1 = (char *)malloc(sizeof(char)*500);
    //(G1, g, h, f) is the public key of authorizer
    //find the generator of the group
//    element_set(g, (*(curve_data_ptr) (*(*(a_pairing_data_ptr) (*pairing).data).Eq).data).gen);
    char str_g[512] = "[2080247391869362085132539778201998483380874841515454429046327131439543677740031077799512395854029182308535916504326748475626106457866048357583741668275635, 3462536684798900385254814488714127044393463459789164641468572493723203953888500069097792605858951898418781245583533869595156169194014075269175495278137832]";
    element_set_str(g, str_g, 10);

    fp = fopen("authorizer/authorizer_secret_key.txt", "r");
    //read the secret key beta
     if(!fp)
         pbc_die("open authorizer secret key file failed");
     else{
         while(true){
             fgets(str_read, 500, fp);
             if(strstr(str_read, "beta:"))
                 break;
         }
         element_set_str(beta, str_read + 5, 10);
         fclose(fp);
     }
     //free and allocte memory again to avoid the effect of previous data
     free(str_read);
     free(str1);
     str_read = (char *)malloc(sizeof(char)*500);
     str1 = (char *)malloc(sizeof(char)*500);
     fp = fopen("public/authorizer_public_keys.txt", "r");
     if(!fp)
         pbc_die("open authorizer public key file failed");
     else{
         while(true){
             fgets(str_read, 500, fp);
            // strncpy(str1, str_read, 2);
             if(strstr(str_read, "h:")){
                 fgets(str1, 500, fp);
                 strcat(str_read, str1);
               // printf("%s\n", str_read);
                 break;
             }
         }
         element_set_str(h, str_read + 2, 10);
         //free and allocte memory again to avoid the effect of previous data
         free(str_read);
         free(str1);
         str_read = (char *)malloc(sizeof(char)*500);
         str1 = (char *)malloc(sizeof(char)*500);
         while(true){
             fgets(str_read, 500, fp);
           //  strncpy(str1, str_read, 2);
             if(strstr(str_read, "f:")){
                 fgets(str1, 500, fp);
                 strcat(str_read, str1);
               // printf("%s\n", str_read);
                 break;
             }
         }
         element_set_str(f, str_read + 2, 10);
         fclose(fp);
     }
}

void MasterProcess::handleMessage(cMessage *msg)
{
    UCACPacket *m = check_and_cast<UCACPacket *>(msg);

    // assign myself address and process ID
    int myAddr = masterAddr; WATCH(myAddr);
    int myProcId = getId(); WATCH(myProcId);

    // information connection for client side
    int clientAddr = 0; WATCH(clientAddr);
    //int clientProcId = 0; WATCH(clientProcId);

    // information connection for server side
    int attributeProcId = 0; WATCH(attributeProcId);

    for(;;){
        if(m->isSelfMessage()){
            EV<<"master process caught selfmessage\n";
            delete m;
            break;
        }
        //received the connection request message from owner along with consumer's redirecting packet
        if(m->getKind() == CONN_REQ){
            ownerAddr = m->getSrcAddress();
            //save the redirect packet that contains consumer's attribute
            msg_temp = check_and_cast<UCACRedirectPacket *>(msg)->dup();
            UCACPacket *res = new UCACPacket("authorizer process response ack to owner", CONN_ACK);
            res->setSrcAddress(masterAddr);
            res->setDestAddress(ownerAddr);
            res->setDestProcId(m->getSrcProcId());
            res->setSrcProcId(getId());
            sendDirect(res, parentOutGate);
            UCACPacket *conn = new UCACPacket("connection request from authorizer to authority", CONN_REQ);
            conn->setSrcAddress(masterAddr);
            conn->setDestAddress(attributeAddr);
            conn->setSrcProcId(getId());
            sendDirect(conn, parentOutGate);
            delete m;
            break;
        }
        //send descriptive attribute to authority
        if(m->getKind() == CONN_ACK && m->getSrcAddress() == attributeAddr){
            UCACRedirectDesPacket *redirect_packet = new UCACRedirectDesPacket("authorizer request DES part1 from authority", DES1_REQ);
            //normally, we use a nounce to avoid replay attack.
            //However, in this simulation, we ignore the MAC and verification.
            //We still keep nounce in our structure for future expansion
            element_random(nounce);
            authorityProcId = m->getSrcProcId();
            //set consumer's ID
            redirect_packet->setID(msg_temp->getID());
            //redirect_packet->setRedirect_URI(msg_temp->getRedirect_URI());
            redirect_packet->setNounce(nounce[0]);
            redirect_packet->setSrcAddress(masterAddr);
            redirect_packet->setDestAddress(attributeAddr);
            redirect_packet->setDestProcId(m->getSrcProcId());
            redirect_packet->setSrcProcId(getId());
            sendDirect(redirect_packet, parentOutGate);
            delete m;
            break;
        }

        if(m->getKind() == AUTN_REQ){
            UCACAuthenticatePacket *m_final = check_and_cast<UCACAuthenticatePacket *>(msg)->dup();
            m_final->getCredential();
            m_final->getID();
            //do some work and check whether these information are correct
            //......
            //......
            //if correct then send back the following packet
           UCACPacket *auth_success = new UCACPacket("authorizer authenticated owner successful", AUTN_RES);
            auth_success->setSrcAddress(masterAddr);
            auth_success->setDestAddress(ownerAddr);
            auth_success->setDestProcId(m->getSrcProcId());
            auth_success->setSrcProcId(getId());
            sendDirect(auth_success, parentOutGate);
            delete m_final;
            delete m;
            break;
        }
        //send part of token to owner
        if(m->getKind() == CONFINED_D_REQ){
            int i = 0;
            UCACAttrPacket  *attr_packet = check_and_cast<UCACAttrPacket *>(msg)->dup();
            //we have to declare NUM_ATTR G1 elements, not just one
            element_t ri, d, r;
            element_init_G1(d, pairing);
            element_init_Zr(ri, pairing);
            element_init_Zr(r, pairing);
            //compute the premature D<---g^r
            element_random(r);
            element_pow_zn(d, g, r);
            element_set(sk_token->D, d);
            //initialize the descriptive part to be 0
            element_init_G1(sk_token->Di[NUM_SHARE - 1], pairing);
            element_init_G1(sk_token->Di_prime[NUM_SHARE - 1], pairing);
            //set the first part of descriptive attribute as previously got from authoriy
            element_set(sk_token->Di[NUM_SHARE - 1], token_packet->getSk_token().Di[NUM_SHARE - 1]);
           // printf("authorizer hash value\n");
            for(i = 0; i < NUM_CONFINE; i++){
                attr[i] = attr_packet->getAttr(i);
                element_random(ri);
                element_from_hash(sk_token->Di[i], (void *)attr[i].c_str(), attr[i].size());
               // element_printf("%B\n", sk_token->Di[i]);
                element_pow_zn(sk_token->Di[i], sk_token->Di[i], ri);
                element_pow_zn(sk_token->Di_prime[i], g, ri);
            }
            /*printf("*************************************************************************************\n");
            element_printf("master sk_token from authority.\nD = %B\n", token_packet->getSk_token().D);
            for(i = 0; i < NUM_ATTR; i++){
                element_printf("D[i] = %B\n", sk_token->Di[i]);
                element_printf("D[i]_prime = %B\n", sk_token->Di_prime[i]);
            }*/
           token_packet->setSrcAddress(masterAddr);
           token_packet->setDestAddress(ownerAddr);
           token_packet->setDestProcId(m->getSrcProcId());
           token_packet->setSrcProcId(getId());
           token_packet->setKind(CONFINED_D_RES);
           token_packet->setName("authorizer response of owner confined attr");
           token_packet->setSk_token(*sk_token);
           sendDirect(token_packet, parentOutGate);
           /*printf("*************************************************************************************\n");
           element_printf("master packet token from authority.\nD = %B\n", token_packet->getSk_token().D);
           for(i = 0; i < NUM_ATTR; i++){
               element_printf("D[i] = %B\n", token_packet->getSk_token().Di[i]);
               element_printf("D[i]_prime = %B\n", token_packet->getSk_token().Di_prime[i]);
           }*/
           element_clear(ri);
           element_clear(d);
           element_clear(r);
           delete m;
           delete attr_packet;
           break;
        }
        if(m->getKind() == DES1_RES && m->getSrcAddress() == attributeAddr){
            //make a copy of the received message
            token_packet = check_and_cast<UCACTokenPacket *>(msg)->dup();
            UCACPacket *res = new UCACPacket("authorizer response back for receiving descriptive part", DES1_RES);
            res->setSrcAddress(masterAddr);
            res->setDestAddress(attributeAddr);
            res->setDestProcId(m->getSrcProcId());
            res->setSrcProcId(getId());
            sendDirect(res, parentOutGate);
            delete m;
            break;
        }
        //interact with owner about the D part in the token
        if(m->getKind() == D_REQ){
            token_packet = check_and_cast<UCACTokenPacket *>(msg)->dup();
            element_set(sk_token->D, token_packet->getSk_token().D);
            element_t beta_inverse;
            element_init_Zr(beta_inverse, pairing);
            element_invert(beta_inverse, beta);
            element_pow_zn(sk_token->D, sk_token->D, beta_inverse);
            token_packet->setSrcAddress(masterAddr);
            token_packet->setDestAddress(ownerAddr);
            token_packet->setDestProcId(m->getSrcProcId());
            token_packet->setSrcProcId(getId());
            token_packet->setKind(D_RES);
            token_packet->setSk_token(*sk_token);
            //nounce for later expansion
            element_random(nounce);
            token_packet->setNounce(nounce[0]);
            token_packet->setName("authorizer complishes D and return it to owner");
            //set corresponding authority process
            //consumer must interact with the same authority process that generated partial key of descriptive attributes
            token_packet->setProcId(authorityProcId);
            sendDirect(token_packet, parentOutGate);
            element_clear(beta_inverse);
            delete m;
            break;
        }
        break;
    }
}

