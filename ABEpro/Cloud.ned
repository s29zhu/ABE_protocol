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

//package dyna;
simple Cloud
{
    parameters:
        // pkRate should be >= numClients, otherwise cloud will become the bottleneck
        double pkRate @prompt("Packet rate of cloud (queue)") = default(1.5*numOwners);
        // buffer max 20 packets
        int queueMaxLen @prompt("Maximum size of cloud (queue)") = default(20);
        @display("i=misc/cloud_vl;q=queue");
    gates:
        inout port[];
}


