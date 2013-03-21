/*
 * ConsumerProcess.cc
 *
 *  Created on: Mar 8, 2013
 *      Author: s29zhu
 */
#include "UCACPacket_m.h"
#include <iostream>
#include "grs.h"

using namespace std;

class ConsumerProcess : public cSimpleModule
{
  private:
    Token *sk_token;
    pairing_t pairing;
    element_t g, h, f, owner_pub, nounce;
    int consumerAddr ;
    int masterAddr;
    int attributeAddr;
    int resourceAddr;
    cGate *parentOutGate;
 //   int procId;
  public:
    ConsumerProcess() : cSimpleModule(0) {}
    virtual void handleMessage(cMessage *m);
    virtual void initialize();
};

Define_Module( ConsumerProcess );

void ConsumerProcess::initialize(){
/*    UCACPacket *starter = new UCACPacket("consumer starts message", 100);
    simtime_t current_time = simTime();
    scheduleAt(current_time + 0.01, starter);*/
    // retrieve parent's parameters
    cModule *parentMod = getParentModule();
    // retrieve parent's out gate
    parentOutGate = parentMod->gate("port$o");

    // assign server address: index of Switch's gate to which servers are connected
    //parentOutGate->getNextGate() gives us the cloud gate vector
    int maxIndex = parentOutGate->getNextGate()->size()-1;
    consumerAddr = maxIndex-3; WATCH(consumerAddr);
    masterAddr = maxIndex-2; WATCH(masterAddr);
    attributeAddr = maxIndex-1; WATCH(attributeAddr);
    resourceAddr = maxIndex; WATCH(resourceAddr);
 //   procId = 0;
    //declaration for file transfer

    FILE *fp;
    char s[16384];
    fp = fopen("public/a.param", "r");
    if (!fp) {
        pbc_die("error opening parameter file");
    }
    size_t count = fread(s, 1, 16384, fp);

    if(!count){
        pbc_die("read parameter failure\n");
    }
    fclose(fp);
    pairing_init_set_buf(pairing, s, count);

    if(pairing_init_set_buf(pairing, s, count)){
        pbc_die("pairing init failed\n");
    }

    if(!pairing_is_symmetric(pairing)) pbc_die("pairing is not symmetric\n");

    element_init_G1(g, pairing);
    element_init_G1(h, pairing);
    element_init_G1(f, pairing);
    element_init_GT(owner_pub, pairing);
    element_init_Zr(nounce, pairing);
//    element_set(g, (*(curve_data_ptr) (*(*(a_pairing_data_ptr) (*pairing).data).Eq).data).gen);
    char str_g[512] = "[2080247391869362085132539778201998483380874841515454429046327131439543677740031077799512395854029182308535916504326748475626106457866048357583741668275635, 3462536684798900385254814488714127044393463459789164641468572493723203953888500069097792605858951898418781245583533869595156169194014075269175495278137832]";
    element_set_str(g, str_g, 10);
    //read out the public key h of authorizer
    char *str_read, *str1;
    str_read = (char *)malloc(sizeof(char)*500);
    str1 = (char *)malloc(sizeof(char)*500);
    fp = fopen("public/authorizer_public_keys.txt", "r");
    if(!fp)
        pbc_die("open authorizer public key file failed");
    else{
        while(true){
            fgets(str_read, 500, fp);
            strncpy(str1, str_read, 2);
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
            strncpy(str1, str_read, 2);
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
    //read out owner public key
    fp = fopen("public/owner_public_key.txt", "r");
    if(!fp)
        pbc_die("open authorizer public key file failed");
    else{
        while(true){
            fgets(str_read, 500, fp);
            strncpy(str1, str_read, 11);
            if(strstr(str_read, "public key:")){
                fgets(str1, 500, fp);
                strcat(str_read, str1);
              // printf("%s\n", str_read);
                break;
            }
        }
        element_set_str(owner_pub, str_read + 11, 10);
        fclose(fp);
    }
    sk_token = new Token;
    int i = 0;
    element_init_G1(sk_token->D, pairing);
    for(i = 0; i < NUM_SHARE; i++){
        element_init_G1(sk_token->Di[i], pairing);
        element_init_G1(sk_token->Di_prime[i], pairing);
    }
}
void ConsumerProcess::handleMessage(cMessage *msg)
{
    UCACPacket *m = check_and_cast<UCACPacket *>(msg);
    // receive the CONN_REQ we were created to handle
    for(;;){
        //when consumer get connect request from owner
        if (m->getKind()==CONN_REQ) {
            // respond with CONN_ACK
            UCACPacket *res = new UCACPacket("consumer process connect ack to owner process", CONN_ACK);
            res->setSrcAddress(consumerAddr);
            res->setDestAddress(m->getSrcAddress());
            res->setDestProcId(m->getSrcProcId());
            res->setSrcProcId(getId());
            //send the packet through parent out gate
            //since there is no explicit connection between consumerProcess module, we must use sendDirect() function
            sendDirect(res, parentOutGate);
            EV << "consumerProc: sent CONN_ACK to client addr = " << m->getSrcAddress() << endl;
            delete m;
            break;
        }
        if(m->getKind() == PRNT_REQ){
            UCACRedirectPacket *redirect_packet = new UCACRedirectPacket("consumer direct owner to authorizer", REDIRECT);
            redirect_packet->setSrcAddress(consumerAddr);
            redirect_packet->setDestAddress(m->getSrcAddress());
            redirect_packet->setDestProcId(m->getSrcProcId());
            redirect_packet->setSrcProcId(getId());
            redirect_packet->setID("printer@printing.com");
            //consumer redirect owner to authenticate itself by send this redirect command
            //own must send something other than merely printing request, so consumer can tell where must the owner to authenticate owner itself
            redirect_packet->setRedirect_URI("www.facebook.com");
            //do not use the accurate access policy, we will see how is going to affect the next
            redirect_packet->setAccess_policy("access policy");
            sendDirect(redirect_packet, parentOutGate);
            delete m;
            break;
        }

        if(m->getKind() == TOKEN){
            UCACTokenPacket *token_packet = check_and_cast<UCACTokenPacket *>(msg)->dup();
            //get everything out from the packet and save the info in sk_token
            element_set(sk_token->D, token_packet->getSk_token().D);
            int i = 0;
            for(i = 0; i < NUM_SHARE; i++){
                element_set(sk_token->Di[i], token_packet->getSk_token().Di[i]);
                element_set(sk_token->Di_prime[i], token_packet->getSk_token().Di_prime[i]);
            }
            element_t temp;
            //element_init_Zr(temp, pairing);
            temp[0] = token_packet->getNounce();
            element_set(nounce, temp);

            //do come verigication abou the nounce
            //...
            //...

            UCACPacket *conn = new UCACPacket("consumer send connect request to authority", CONN_REQ);
            conn->setSrcAddress(consumerAddr);
            conn->setDestAddress(attributeAddr);
            //get authority's procId
            conn->setDestProcId(token_packet->getProcId());
            conn->setSrcProcId(getId());
            sendDirect(conn, parentOutGate);
            delete token_packet;
            delete m;
            break;
        }

        if(m->getKind() == CONN_ACK ){
            if(m->getSrcAddress() == attributeAddr){
                UCACAuthenticatePacket *authen = new UCACAuthenticatePacket("consumer send credential to authoriy", AUTN_REQ);
                authen->setID("printer@printing.com");
                authen->setCredential("consumer credential");
                authen->setSrcAddress(consumerAddr);
                authen->setDestAddress(attributeAddr);
                authen->setDestProcId(m->getSrcProcId());
                authen->setSrcProcId(getId());
                sendDirect(authen, parentOutGate);
            }
            else if(m->getSrcAddress() == resourceAddr){
                UCACDataPacket *data_req = new UCACDataPacket("consumer request data from resource server", FILE_REQ);
                data_req->setSrcAddress(consumerAddr);
                data_req->setDestAddress(resourceAddr);
                data_req->setDestProcId(m->getSrcProcId());
                data_req->setSrcProcId(getId());
                //will be completed later, file location is given by resource owner?
                data_req->setPayload("http://facebook/julia_b/photofile.jpg");
                sendDirect(data_req, parentOutGate);
            }
            delete m;
            break;
        }
        if(m->getKind() == AUTN_RES && m->getSrcAddress() == attributeAddr){
            UCACTokenPacket *req_des2 = new UCACTokenPacket("consumer request descriptive part2 from authority", DES2_REQ);
            req_des2->setSrcAddress(consumerAddr);
            req_des2->setDestAddress(attributeAddr);
            req_des2->setDestProcId(m->getSrcProcId());
            req_des2->setSrcProcId(getId());
            sendDirect(req_des2, parentOutGate);
            delete m;
            break;
        }
        if(m->getKind() == DES2_RES){
            UCACTokenPacket *des2 = check_and_cast<UCACTokenPacket *>(msg)->dup();
            element_set(sk_token->Di_prime[NUM_SHARE - 1], des2->getSk_token().Di_prime[NUM_SHARE - 1]);
            //Consumer holds complete secret token and begin to require for encrypted file
            UCACPacket *conn = new UCACPacket("consumer connection request to resource server", CONN_REQ);
            conn->setSrcAddress(consumerAddr);
            conn->setDestAddress(resourceAddr);
            conn->setSrcProcId(getId());
            sendDirect(conn, parentOutGate);
            delete des2;
            delete m;
            break;
        }
        if(m->getKind() == FILE_RES){
            element_t C_tilde, C;
            element_t Cy[NUM_SHARE];
            element_t Cy_prime[NUM_SHARE];
            unsigned int position = 0;

            element_init_GT(C_tilde, pairing);
            element_init_G1(C, pairing);
            int i = 0, j = 0;
            for(i = 0; i < NUM_SHARE; i++){
                element_init_G1(Cy[i], pairing);
                element_init_G1(Cy_prime[i], pairing);
            }
            UCACDataPacket *file = check_and_cast<UCACDataPacket *>(msg)->dup();
            string data(file->getPayload());
            //cout<<"data size = "<<data.size()<<endl;

            position = data.find("]", 0);
            if(position != string::npos){
                string temp = data.substr(0, position + 1);
                data = data.substr(position + 1);
                element_set_str(C_tilde, temp.c_str(), 10);
                //element_printf("C_tilde = \n%B", C_tilde);
            }
            position = data.find("]", 0);
            if(position != string::npos){
                string temp = data.substr(0, position + 1);
                data = data.substr(position + 1);
                element_set_str(C, temp.c_str(), 10);
                //element_printf("\nC = \n%B\n", C);
            }
            position = data.find("]", 0);
            i = 0;
            while(data.size() != 0){
                string temp = data.substr(0, position + 1);
                data = data.substr(position + 1);
                element_set_str(Cy[i], temp.c_str(), 10);
                position = data.find("]", 0);
                temp = data.substr(0, position + 1);
                data = data.substr(position + 1);
                element_set_str(Cy_prime[i], temp.c_str(), 10);
                position = data.find("]", 0);
                //cout<<data<<endl;
                i++;
            }
            delete file;
            delete m;

            //decryption starts
            //without error
            element_t pairing_nominator[NUM_SHARE];
            element_t pairing_denominator[NUM_SHARE];
            element_t division_result[NUM_SHARE];
            //print out to check whether the shares are correct compared to owner's shares
            printf("consumer shares\n");
            for(i = 0; i < NUM_SHARE; i++){
                element_init_GT(pairing_nominator[i], pairing);
                element_init_GT(pairing_denominator[i], pairing);
                element_init_GT(division_result[i], pairing);
                element_pairing(pairing_nominator[i], sk_token->Di[i], Cy[i]);
                element_pairing(pairing_denominator[i], sk_token->Di_prime[i], Cy_prime[i]);
                element_div(division_result[i], pairing_nominator[i], pairing_denominator[i]);
                element_printf("%B\n", division_result[i]);
            }

            element_t pre_parity_check_matrix[M][N];
            element_t parity_check_matrix[N - K][N];
            element_t generator_matrix[K][N];
            element_t multipliers[N];
            element_t add_vector[N];
            element_t add_temp[N];
            element_t syndrome[N];
            element_t elimination, temp;
            element_init_Zr(elimination, pairing);
            element_init_GT(temp, pairing);
            for(i = 0; i < N; i++){
                element_init_Zr(multipliers[i], pairing);
                element_init_Zr(add_vector[i], pairing);
                element_init_Zr(add_temp[i], pairing);
                element_init_GT(syndrome[i], pairing);
            }
            for(i = 0; i < M; i++){
                for(j = 0; j < N; j++){
                    element_init_Zr(pre_parity_check_matrix[i][j], pairing);
                }
            }
            for(i = 0; i < N - K; i++){
                for(j = 0; j < N; j++){
                    element_init_Zr(parity_check_matrix[i][j], pairing);
                }
            }
            for(i = 0; i < K; i++){
                for(j = 0; j < N; j++){
                    element_init_Zr(generator_matrix[i][j], pairing);
                }
            }
            ComputeParityCheckMatrix(parity_check_matrix,
                                     pre_parity_check_matrix,
                                     multipliers,
                                     elimination,
                                     add_vector,
                                     add_temp);
            GeneratorMatrix(generator_matrix);
            cout<<"double check parity check matrix in consumer"<<endl;
            for(i = 0; i < K; i++){
                element_set0(elimination);
                for(j = 0; j < N; j++){
                     element_mul(generator_matrix[i][j], generator_matrix[i][j], parity_check_matrix[1][j]);
                     element_add(elimination, elimination, generator_matrix[i][j]);
                }
                element_printf("%B  ", elimination);
                cout<<endl;
            }
            element_t qR[8];
            for(i = 0; i < 8; i++){
                element_init_Zr(qR[i], pairing);
            }

            element_set_str(qR[0], "494542596917689980177291032045340379312922546410", 10);
            element_set_str(qR[1], "550456852650019989461932316551165113387472936381", 10);
            element_set_str(qR[2], "255435593911985800828918153843387137418087958984", 10);
            element_set_str(qR[3], "506790265821512726869645046657520957981459259195", 10);
            element_set_str(qR[4], "26161295240287151776813985579009552137202455232", 10);
            element_set_str(qR[5], "350999477911451345367381868157712940017855360550", 10);
            element_set_str(qR[6], "476826817569542602028522600501875145454021506528", 10);
            element_set_str(qR[7], "468644838297277138073529150403714111309750859143", 10);
            element_set0(elimination);
            cout<<"codeword check, should be 0\n";
            for(j = 0; j < N; j++){
                 element_mul(qR[j], qR[j], parity_check_matrix[1][j]);
                 element_add(elimination, elimination, qR[j]);
            }
            element_printf("%B  ", elimination);
            cout<<endl;
            ComputeSyndrome(parity_check_matrix,
                            division_result,
                            syndrome,
                            temp);

            finish();
            break;
        }
    }
}