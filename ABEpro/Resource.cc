/*
 * Owner.cc
 *
 *  Feb 28 2013
 *  Author: Shasha Zhu
 *
 */

#include "UCACPacket_m.h"

class Resource : public cSimpleModule
{
  private:
    cModuleType *srvProcType;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Resource);


void Resource::initialize()
{
    srvProcType = cModuleType::find("ResourceProcess");
}

void Resource::handleMessage(cMessage *msg)
{
    UCACPacket *pk = check_and_cast<UCACPacket *>(msg);

    // if receive connection request, create a new process (module)
    if (pk->getKind()==CONN_REQ)
    {
        cModule *mod = srvProcType->createScheduleInit("resourceProc",this);
        EV << "CONN_REQ: Resource created process ID = " << mod->getId() << endl;
        sendDirect(pk, mod, "in");
    }
    else
    // otherwise the process has already created, so redirect to that process.
    {
        int serverProcId = pk->getDestProcId();
        EV << "Resource is redirecting msg to process ID = " << serverProcId << endl;
        cModule *mod = simulation.getModule(serverProcId);
        // unless cannot find the destination process, destroy the packet
        if (!mod) {
            EV << " That process already exited, deleting msg\n";
            delete pk;
        } else {
            sendDirect(pk, mod, "in");
        }
    }
}

