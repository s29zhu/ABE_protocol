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

cplusplus {{
    #include "pbc/pbc.h"
	#include "grs.h"
    typedef struct{
        element_t D;
        element_t Di[NUM_SHARE];
        element_t Di_prime[NUM_SHARE];
    }Token;
}};

enum UCACPacketType
{
    // establish connection
    CONN_REQ = 0;
    CONN_ACK = 1;
    // tear off connection
    DISC_REQ = 2;
    DISC_ACK = 3;
    // carry playload
    REDIRECT = 4;
	//owner send confined attributes to authorizer and request the confined part and initial D=g^r
    CONFINED_D_REQ = 5;	
	CONFINED_D_RES = 6;	
	//owner send g^(alpha+ra) to authorizer
    D_REQ = 7;
    //authorizer return g^[(alpha+ra)/beta] to owner
    D_RES = 8;
    // print service request-response between owner and consumer
    PRNT_REQ = 9;
    PRNT_RES = 10;
    // file request-response between consumer and resource
    FILE_REQ = 11;
    FILE_RES = 12;
    // authorize request-response between consumer and master via owner
    AUTZ_REQ = 13;
    AUTZ_RES = 14;
    // owner authenticate to master
    AUTN_REQ = 15;
    AUTN_RES = 16;
    // owner submit allowed attributes to master
    ATTR_REQ = 17;
    ATTR_RES = 18;
    // master request Descritive part-1 from authority
    DES1_REQ = 19;
    DES1_RES = 20;
    // consumer request Descriptive part-2 from authority
    DES2_REQ = 21;
    DES2_RES = 22;
    //a message that send from the parent module to childen modules in order to initialize
    INI_REQ = 23;
    INI_RES = 24;
    //token that owner sended to consumer
    TOKEN = 25;
    DES1_RES_FAILED = 26;   
};

// packet header
packet UCACPacket
{
    int srcAddress;
    int destAddress;
    int srcProcId;
    int destProcId;
};
//use pairing_s instead of pairing_t, becasue pairing_t is an array, it is difficult to assign value(s)
struct Token;
// And due to the reason that all the members declared here are private, they must be accessed by get and set function.
//If we use pairing_t or element_t(they are all arrays), there will be array assignment errors inside the set functions.
struct pairing_s;
struct element_s;
// packet with payload
packet UCACAttrPacket extends UCACPacket
{
    string attr[NUM_SHARE];
};
packet UCACRedirectPacket extends UCACPacket
{
    string ID;
    string Redirect_URI;
    string access_policy;
}
packet UCACRedirectDesPacket extends UCACPacket
{
 	string ID;
 	string Redirect_URI;
 	element_s nounce;
}
packet UCACAuthenticatePacket extends UCACPacket
{
    string ID;
    string credential;
};
packet UCACTokenPacket extends UCACPacket
{
    Token sk_token;
    element_s nounce;
    int procId;
};

packet UCACDataPacket extends UCACPacket
{
    string Payload;
};

packet UCACInitializePacket extends UCACPacket
{
    //authorizer public keys
    pairing_s pairing;
    element_s g;
    element_s h;
    element_s f;
    //authorizer secret key
    element_s beta;
    //owner secret key
    element_s owner_sk;
    //owner public key
    element_s owner_pub;  
}