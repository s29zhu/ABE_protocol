/*
 * Cloud.cc
 *
 *  Created on: Mar 8, 2013
 *      Author: s29zhu
 */

#include "UCACPacket_m.h"


/**
 * Simulates a Cloud between clients and server; see NED file for more info
 */
class Cloud : public cSimpleModule
{
  public:
    Cloud() : cSimpleModule(0) {}
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Cloud);

void Cloud::initialize(){
/*    simtime_t current_time = simTime();
    UCACPacket *starter = new UCACPacket("starter message for cloud", 100);
    scheduleAt(current_time + 0.001, starter);*/
}
void Cloud::handleMessage(cMessage *msg)
{
    UCACPacket *m = check_and_cast<UCACPacket *>(msg);
    for(;;)
    {
        if(msg->isSelfMessage()){
            EV<<"cloud caught self message\n";
            delete msg;
            break;
        }else{
            int dest = m->getDestAddress();
            EV << "cloud: Relaying msg to addr = " << dest << "\n";
            send(msg, "port$o", dest);
            break;
        }
        break;
    }
}



