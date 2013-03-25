/*
 * MasterProcess.cc
 *
 *  Created on: Mar 8, 2013
 *      Author: s29zhu
 */

#include "UCACPacket_m.h"
#include <iostream>
#include <fstream>

using namespace std;

class ResourceProcess : public cSimpleModule
{
  public:
    ResourceProcess() : cSimpleModule(0) {}
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module( ResourceProcess );
void ResourceProcess::initialize(){

}
void ResourceProcess::handleMessage(cMessage *msg)
{
    // retrieve parent's parameters
	cModule *parentMod = getParentModule();
    UCACPacket *m = check_and_cast<UCACPacket *>(msg);
    // retrieve parent's out gate
    cGate *parentOutGate = parentMod->gate("port$o");

    // assign server address: index of Switch's gate to which servers are connected
    int maxIndex = parentOutGate->getNextGate()->size()-1;
    int consumerAddr = maxIndex-3; WATCH(consumerAddr);
    int masterAddr = maxIndex-2; WATCH(masterAddr);
    int attributeAddr = maxIndex-1; WATCH(attributeAddr);
    int resourceAddr = maxIndex; WATCH(resourceAddr);

    // assign myself address and process ID
    int myAddr = resourceAddr; WATCH(myAddr);
    int myProcId = getId(); WATCH(myProcId);

    // connection information for client side
    int clientAddr = 0; WATCH(clientAddr);
    int clientProcId=0; WATCH(clientProcId);

    int type; WATCH(type);
    for(;;){
        if(m->getKind() == CONN_REQ){
            UCACPacket *res = new UCACPacket("Resource sever reponse to consumer", CONN_ACK);
            res->setSrcAddress(resourceAddr);
            res->setDestAddress(m->getSrcAddress());
            res->setDestProcId(m->getSrcProcId());
            res->setSrcProcId(getId());
            sendDirect(res, parentOutGate);
            delete m;
            break;
        }

        if(m->getKind() == FILE_REQ){
            UCACDataPacket *temp = check_and_cast<UCACDataPacket *>(msg);
            //get the file location and try to get the file
            temp->getPayload();
            ifstream inputfile;
            char data[512];
            inputfile.open("resource_server/encryption_header.txt", ifstream::in);
            if(inputfile.fail())
                cout<<"resource server open data file failed\n";
            inputfile.getline(data, 512);
            string payload(data);
            unsigned int pos = payload.find(":", 0);
            if(pos != string::npos)
                payload.replace(0, pos+1, "");
            while(!inputfile.eof()){
                int i = 0;
                for(i = 0; i < 512; i++)
                    data[i] = '\0';
                inputfile.getline(data, 512);
                string temp(data);
                unsigned int pos = temp.find(":", 0);
                if(pos != string::npos)
                    temp.replace(0, pos+1, "");
                payload += temp;
            }
           // cout<<"the header content\n"<<payload<<endl;
            UCACDataPacket *file = new UCACDataPacket("resource server respond file to consumer", FILE_RES);
            file->setDestAddress(consumerAddr);
            file->setSrcAddress(resourceAddr);
            file->setDestProcId(m->getSrcProcId());
            file->setSrcProcId(getId());
            file->setPayload(payload.c_str());
            sendDirect(file, parentOutGate);
            delete m;
            break;
        }
    }
}
