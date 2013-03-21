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

simple Master
{
    parameters:
        //double timeout @unit(s) @prompt("Connection timeout");
        double conf1Time @unit(s) @prompt("Confined set-1 computing time");
        double conf2Time @unit(s) @prompt("Confined set-2 computing time");
        @display("i=device/server");
    gates:
        inout port;
}
