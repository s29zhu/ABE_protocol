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

simple Owner
{
    parameters:
        //double timeout1 @unit(s) @prompt("Connection timeout for 1-2 rounds");
        //double timeout2 @unit(s) @prompt("Connection timeout for 6 rounds");
        //double timeout3 @unit(s) @prompt("Connection timeout for 10 rounds");
        volatile double connIaTime @unit(s) @prompt("Connection interarrival time") = default(10s);
        double graTime @unit(s) @prompt("g^(ra) computing time");
        @display("i=device/pc2");
        // statistic property for exploring statistic of "responTime" signal
        @signal[latency](type="simtime_t");
        @statistic[latency](title="Latency time of file print"; record=stats; unit=s; interpolationmode=none);
    gates:
        inout port;
}


