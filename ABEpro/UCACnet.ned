//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

network UCACnet
{
    parameters:
        int numOwners @prompt("Number of clients") = default(4);
    submodules:
        owner[numOwners]: Owner {
            parameters:
                //timeout1 = 5s;
                //timeout2 = 20s;
                //timeout3 = 40s;
                @display("p=210,341,m,10,80");
        }

        consumer: Consumer {
            parameters:
                //timeout = 5s;
                @display("p=394,112");
        }

        master: Master {
            parameters:
                //timeout = 5s;
                @display("p=37,112");
        }

        attribute: Attribute {
            parameters:
                @display("p=132,31");
        }

        resource: Resource {
            parameters:
                @display("p=283,31");
        }

        cloud: Cloud {
            parameters:
                //pkRate should be >= numOwners, otherwise cloud will become the bottleneck
                pkRate = numOwners;
                //queueMaxLen should be >= numOwners, otherwise cloud will drop the overfolw packet
                queueMaxLen = 2*numOwners;
                @display("p=210,160");
            gates:
                port[numOwners+4];
        }

    connections:
        for i=0..numOwners-1 {
            //owner[i].port <--> { delay = 10ms; } <--> cloud.port[i];
            owner[i].port <--> {  delay = 20ms; } <--> cloud.port[i];
        }

        consumer.port <--> {  delay = 5ms; } <--> cloud.port[numOwners];
        master.port <--> {  delay = 5ms; } <--> cloud.port[numOwners+1];
        attribute.port <--> {  delay = 5ms; } <--> cloud.port[numOwners+2];
        resource.port <--> {  delay = 5ms; } <--> cloud.port[numOwners+3];
}


