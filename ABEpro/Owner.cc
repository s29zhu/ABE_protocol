/*
 * Owner.cc
 *
 *  Feb 28 2013
 *  Author: Shasha Zhu
 *
 */
#include "UCACPacket_m.h"
#include "pbc/pbc.h"
#include <iostream>
#include <cstring>
using namespace std;
class Owner : public cSimpleModule
{
  private:
    cModuleType *srvProcType;
    pairing_t pairing;
    element_t g, h, f, owner_pub;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    cModule *mod;
};

Define_Module(Owner);


void Owner::initialize()
{
    int max = gate("port$o")->getNextGate()->size()-1;
    int consumerAddr;
    int ownerAddr;
    consumerAddr = max - 3;
    ownerAddr = gate("port$o")->getNextGate()->getIndex();
    UCACPacket *starter = new UCACPacket("owner start message", 100);
    simtime_t current_time = simTime();
    scheduleAt(current_time + 0.01, starter);
}

void Owner::handleMessage(cMessage *msg)
{
    UCACPacket *m = check_and_cast<UCACPacket *>(msg);
    if(m->isSelfMessage()){
        EV<<"owner caught selfmessage\n";
        srvProcType = cModuleType::find("OwnerProcess");
        mod = srvProcType->createScheduleInit("ownerProc",this);
        delete msg;
    } else{
        sendDirect(msg, mod, "in");
    }
}
