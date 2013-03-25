/*
 * MasterProcess.cc
 *
 *  Created on: Mar 8, 2013
 *      Author: s29zhu
 */

#include "UCACPacket_m.h"
#include <iostream>
#include "pbc/pbc.h"
#include "grs.h"
using namespace std;
class AttributeProcess : public cSimpleModule
{
    private:
        pairing_t pairing;
        element_t g;
        Token *sk_token;
        element_t des_p2, nounce;
        UCACTokenPacket *token_packet;
    public:
        AttributeProcess() : cSimpleModule(0) {}
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module( AttributeProcess );

void AttributeProcess::initialize(){
    /*cMessage *starter = new cMessage("consumer start message");
    scheduleAt(5.0, starter);*/
    sk_token = new Token;
    FILE *fp;
    char s[16384];
/*    UCACPacket *starter = new UCACPacket("consumer starts message", 100);
    simtime_t current_time = simTime();
    scheduleAt(current_time + 0.004, starter);*/
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
    element_init_Zr(nounce, pairing);
    element_init_G1(des_p2, pairing);
//    element_set(g, (*(curve_data_ptr) (*(*(a_pairing_data_ptr) (*pairing).data).Eq).data).gen);
    char str_g[512] = "[2080247391869362085132539778201998483380874841515454429046327131439543677740031077799512395854029182308535916504326748475626106457866048357583741668275635, 3462536684798900385254814488714127044393463459789164641468572493723203953888500069097792605858951898418781245583533869595156169194014075269175495278137832]";
    element_set_str(g, str_g, 10);
    //read out the public key h of authorizer
}
void AttributeProcess::handleMessage(cMessage *msg)
{
    UCACPacket *m = check_and_cast<UCACPacket *>(msg);
    // retrieve parent's parameters
	cModule *parentMod = getParentModule();

    // retrieve parent's out gate
    cGate *parentOutGate = parentMod->gate("port$o");

    // assign server address: index of Switch's gate to which servers are connected
    int maxIndex = parentOutGate->getNextGate()->size()-1;
    int consumerAddr = maxIndex-3; WATCH(consumerAddr);
    int masterAddr = maxIndex-2; WATCH(masterAddr);
    int attributeAddr = maxIndex-1; WATCH(attributeAddr);
    int resourceAddr = maxIndex; WATCH(resourceAddr);

    // assign myself address and process ID
    int myAddr = attributeAddr; WATCH(myAddr);
    int myProcId = getId(); WATCH(myProcId);

    // connection information for client side
    int clientAddr = 0; WATCH(clientAddr);
    int clientProcId = 0; WATCH(clientProcId);
    int type; WATCH(type);

    for(;;){
        //received
        if(m->getKind() == CONN_REQ){
            if(m->getSrcAddress() == masterAddr){
                UCACPacket *res = new UCACPacket("authority response ack to authorizer", CONN_ACK);
                res->setSrcAddress(attributeAddr);
                res->setDestAddress(m->getSrcAddress());
                res->setDestProcId(m->getSrcProcId());
                res->setSrcProcId(getId());
                sendDirect(res, parentOutGate);
                delete m;
            }else if(m->getSrcAddress() == consumerAddr){
                UCACPacket *res = new UCACPacket("authority send conn ACK to consumer", CONN_ACK);
                res->setSrcAddress(attributeAddr);
                res->setDestAddress(consumerAddr);
                //first set destProcId, then srcProcId, other wise the original srcProcId will be overwritten
                res->setDestProcId(m->getSrcProcId());
                res->setSrcProcId(getId());
                sendDirect(res, parentOutGate);
                delete m;
            }
            break;
        }
        if(m->getKind() == DES1_REQ){
            element_t D_hat_descriptive, rj,D_prime_descriptive;
            UCACRedirectDesPacket *redirect_packet = check_and_cast<UCACRedirectDesPacket *>(msg)->dup();
            element_init_G1(D_hat_descriptive, pairing);
            element_init_G1(D_prime_descriptive, pairing);
            element_init_Zr(rj, pairing);
            string attr;
            //get consumer's ID, ie attribute
            attr = redirect_packet->getID();
            cout<<attr<<endl;
            element_random(rj);
            //save nounce for later verification, future work to add
            element_t temp;//declare a element pointer
            temp[0] = redirect_packet->getNounce();
            //element_printf("attribute temp = %B\n", temp);
            element_set(nounce, temp);
            element_from_hash(D_hat_descriptive, (void *)attr.c_str(), attr.size());
            element_pow_zn(D_hat_descriptive, D_hat_descriptive, rj);
            element_pow_zn(D_prime_descriptive, g, rj);
            token_packet = new UCACTokenPacket("descriptive part from authority", DES1_RES);
            int i = 0;
            element_init_G1(sk_token->D, pairing);
            for(i = 0; i < NUM_SHARE; i++){
                element_init_G1(sk_token->Di[i], pairing);
                element_init_G1(sk_token->Di_prime[i], pairing);
            }
            //the last position is for descriptive attributes
            element_set(sk_token->Di[NUM_SHARE - 1], D_hat_descriptive);
            token_packet->setSrcAddress(attributeAddr);
            token_packet->setDestAddress(m->getSrcAddress());
            token_packet->setDestProcId(m->getSrcProcId());
            token_packet->setSrcProcId(getId());
            token_packet->setSk_token(*sk_token);
/*            printf("*************************************************************************************\n");
            element_printf("authority send des2 token to authorizer.\nD = %B\n", token_packet->getSk_token().D);
            for(i = 0; i < NUM_SHARE; i++){
                element_printf("D[i] = %B\n", token_packet->getSk_token().Di[i]);
                element_printf("D[i]_prime = %B\n", token_packet->getSk_token().Di_prime[i]);
            }*/
            sendDirect(token_packet , parentOutGate);
            //now save the g^ri
            element_set(des_p2, D_prime_descriptive);
            element_clear(D_hat_descriptive);
            element_clear(rj);
            element_clear(D_prime_descriptive);
            delete redirect_packet;
            delete m;
            break;
        }
        //if authorizer received the part1 of descriptive attributes, and reponsed back, authority just ignore the packet
        if(m->getKind() == DES1_RES){
            delete m;
            break;
        }
        if(m->getKind() == AUTN_REQ){
            UCACAuthenticatePacket *authen = check_and_cast<UCACAuthenticatePacket *>(msg)->dup();
            authen->getID();
            authen->getCredential();
            //authority do authentication of consumer
            //...
            //...
            //if consumer is legitimate, then reply the following message

            UCACPacket *res_authen = new UCACPacket("authority reply consumer's authentication", AUTN_RES);
            res_authen->setSrcAddress(attributeAddr);
            res_authen->setDestAddress(consumerAddr);
            res_authen->setDestProcId(m->getSrcProcId());
            res_authen->setSrcProcId(getId());
            sendDirect(res_authen, parentOutGate);
            delete m;
            break;
        }
        if(m->getKind() == DES2_REQ){
            UCACTokenPacket *req_des2 = new UCACTokenPacket("authority replies des part 2 to consumer", DES2_RES);
            Token des2;
            int i = 0;
            element_init_G1(des2.D, pairing);
              for(i = 0; i < NUM_SHARE; i++){
                element_init_G1(des2.Di[i], pairing);
                element_init_G1(des2.Di_prime[i], pairing);
            }
            element_set(des2.Di_prime[NUM_SHARE - 1], des_p2);
            req_des2->setSrcAddress(attributeAddr);
            req_des2->setDestAddress(m->getSrcAddress());
            req_des2->setDestProcId(m->getSrcProcId());
            req_des2->setSrcProcId(getId());
            req_des2->setSk_token(des2);
            sendDirect(req_des2, parentOutGate);
            delete m;
            break;
        }

    }
}

