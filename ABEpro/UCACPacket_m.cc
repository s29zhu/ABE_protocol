//
// Generated file, do not edit! Created by opp_msgc 4.2 from UCACPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "UCACPacket_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("UCACPacketType");
    if (!e) enums.getInstance()->add(e = new cEnum("UCACPacketType"));
    e->insert(CONN_REQ, "CONN_REQ");
    e->insert(CONN_ACK, "CONN_ACK");
    e->insert(DISC_REQ, "DISC_REQ");
    e->insert(DISC_ACK, "DISC_ACK");
    e->insert(REDIRECT, "REDIRECT");
    e->insert(CONFINED_D_REQ, "CONFINED_D_REQ");
    e->insert(CONFINED_D_RES, "CONFINED_D_RES");
    e->insert(D_REQ, "D_REQ");
    e->insert(D_RES, "D_RES");
    e->insert(PRNT_REQ, "PRNT_REQ");
    e->insert(PRNT_RES, "PRNT_RES");
    e->insert(FILE_REQ, "FILE_REQ");
    e->insert(FILE_RES, "FILE_RES");
    e->insert(AUTZ_REQ, "AUTZ_REQ");
    e->insert(AUTZ_RES, "AUTZ_RES");
    e->insert(AUTN_REQ, "AUTN_REQ");
    e->insert(AUTN_RES, "AUTN_RES");
    e->insert(ATTR_REQ, "ATTR_REQ");
    e->insert(ATTR_RES, "ATTR_RES");
    e->insert(DES1_REQ, "DES1_REQ");
    e->insert(DES1_RES, "DES1_RES");
    e->insert(DES2_REQ, "DES2_REQ");
    e->insert(DES2_RES, "DES2_RES");
    e->insert(INI_REQ, "INI_REQ");
    e->insert(INI_RES, "INI_RES");
    e->insert(TOKEN, "TOKEN");
    e->insert(DES1_RES_FAILED, "DES1_RES_FAILED");
);

Register_Class(UCACPacket);

UCACPacket::UCACPacket(const char *name, int kind) : cPacket(name,kind)
{
    this->srcAddress_var = 0;
    this->destAddress_var = 0;
    this->srcProcId_var = 0;
    this->destProcId_var = 0;
}

UCACPacket::UCACPacket(const UCACPacket& other) : cPacket(other)
{
    copy(other);
}

UCACPacket::~UCACPacket()
{
}

UCACPacket& UCACPacket::operator=(const UCACPacket& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void UCACPacket::copy(const UCACPacket& other)
{
    this->srcAddress_var = other.srcAddress_var;
    this->destAddress_var = other.destAddress_var;
    this->srcProcId_var = other.srcProcId_var;
    this->destProcId_var = other.destProcId_var;
}

void UCACPacket::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->srcAddress_var);
    doPacking(b,this->destAddress_var);
    doPacking(b,this->srcProcId_var);
    doPacking(b,this->destProcId_var);
}

void UCACPacket::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->srcAddress_var);
    doUnpacking(b,this->destAddress_var);
    doUnpacking(b,this->srcProcId_var);
    doUnpacking(b,this->destProcId_var);
}

int UCACPacket::getSrcAddress() const
{
    return srcAddress_var;
}

void UCACPacket::setSrcAddress(int srcAddress)
{
    this->srcAddress_var = srcAddress;
}

int UCACPacket::getDestAddress() const
{
    return destAddress_var;
}

void UCACPacket::setDestAddress(int destAddress)
{
    this->destAddress_var = destAddress;
}

int UCACPacket::getSrcProcId() const
{
    return srcProcId_var;
}

void UCACPacket::setSrcProcId(int srcProcId)
{
    this->srcProcId_var = srcProcId;
}

int UCACPacket::getDestProcId() const
{
    return destProcId_var;
}

void UCACPacket::setDestProcId(int destProcId)
{
    this->destProcId_var = destProcId;
}

class UCACPacketDescriptor : public cClassDescriptor
{
  public:
    UCACPacketDescriptor();
    virtual ~UCACPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(UCACPacketDescriptor);

UCACPacketDescriptor::UCACPacketDescriptor() : cClassDescriptor("UCACPacket", "cPacket")
{
}

UCACPacketDescriptor::~UCACPacketDescriptor()
{
}

bool UCACPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UCACPacket *>(obj)!=NULL;
}

const char *UCACPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UCACPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int UCACPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *UCACPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcAddress",
        "destAddress",
        "srcProcId",
        "destProcId",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int UCACPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddress")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcProcId")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destProcId")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UCACPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *UCACPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int UCACPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UCACPacket *pp = (UCACPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UCACPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UCACPacket *pp = (UCACPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcAddress());
        case 1: return long2string(pp->getDestAddress());
        case 2: return long2string(pp->getSrcProcId());
        case 3: return long2string(pp->getDestProcId());
        default: return "";
    }
}

bool UCACPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UCACPacket *pp = (UCACPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcAddress(string2long(value)); return true;
        case 1: pp->setDestAddress(string2long(value)); return true;
        case 2: pp->setSrcProcId(string2long(value)); return true;
        case 3: pp->setDestProcId(string2long(value)); return true;
        default: return false;
    }
}

const char *UCACPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *UCACPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UCACPacket *pp = (UCACPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(UCACAttrPacket);

UCACAttrPacket::UCACAttrPacket(const char *name, int kind) : UCACPacket(name,kind)
{
    for (unsigned int i=0; i<NUM_SHARE; i++)
        this->attr_var[i] = 0;
}

UCACAttrPacket::UCACAttrPacket(const UCACAttrPacket& other) : UCACPacket(other)
{
    copy(other);
}

UCACAttrPacket::~UCACAttrPacket()
{
}

UCACAttrPacket& UCACAttrPacket::operator=(const UCACAttrPacket& other)
{
    if (this==&other) return *this;
    UCACPacket::operator=(other);
    copy(other);
    return *this;
}

void UCACAttrPacket::copy(const UCACAttrPacket& other)
{
    for (unsigned int i=0; i<NUM_SHARE; i++)
        this->attr_var[i] = other.attr_var[i];
}

void UCACAttrPacket::parsimPack(cCommBuffer *b)
{
    UCACPacket::parsimPack(b);
    doPacking(b,this->attr_var,NUM_SHARE);
}

void UCACAttrPacket::parsimUnpack(cCommBuffer *b)
{
    UCACPacket::parsimUnpack(b);
    doUnpacking(b,this->attr_var,NUM_SHARE);
}

unsigned int UCACAttrPacket::getAttrArraySize() const
{
    return NUM_SHARE;
}

const char * UCACAttrPacket::getAttr(unsigned int k) const
{
    if (k>=NUM_SHARE) throw cRuntimeError("Array of size NUM_SHARE indexed by %lu", (unsigned long)k);
    return attr_var[k].c_str();
}

void UCACAttrPacket::setAttr(unsigned int k, const char * attr)
{
    if (k>=NUM_SHARE) throw cRuntimeError("Array of size NUM_SHARE indexed by %lu", (unsigned long)k);
    this->attr_var[k] = attr;
}

class UCACAttrPacketDescriptor : public cClassDescriptor
{
  public:
    UCACAttrPacketDescriptor();
    virtual ~UCACAttrPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(UCACAttrPacketDescriptor);

UCACAttrPacketDescriptor::UCACAttrPacketDescriptor() : cClassDescriptor("UCACAttrPacket", "UCACPacket")
{
}

UCACAttrPacketDescriptor::~UCACAttrPacketDescriptor()
{
}

bool UCACAttrPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UCACAttrPacket *>(obj)!=NULL;
}

const char *UCACAttrPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UCACAttrPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int UCACAttrPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *UCACAttrPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "attr",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int UCACAttrPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "attr")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UCACAttrPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *UCACAttrPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int UCACAttrPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UCACAttrPacket *pp = (UCACAttrPacket *)object; (void)pp;
    switch (field) {
        case 0: return NUM_SHARE;
        default: return 0;
    }
}

std::string UCACAttrPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UCACAttrPacket *pp = (UCACAttrPacket *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getAttr(i));
        default: return "";
    }
}

bool UCACAttrPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UCACAttrPacket *pp = (UCACAttrPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setAttr(i,(value)); return true;
        default: return false;
    }
}

const char *UCACAttrPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *UCACAttrPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UCACAttrPacket *pp = (UCACAttrPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(UCACRedirectPacket);

UCACRedirectPacket::UCACRedirectPacket(const char *name, int kind) : UCACPacket(name,kind)
{
    this->ID_var = 0;
    this->Redirect_URI_var = 0;
    this->access_policy_var = 0;
}

UCACRedirectPacket::UCACRedirectPacket(const UCACRedirectPacket& other) : UCACPacket(other)
{
    copy(other);
}

UCACRedirectPacket::~UCACRedirectPacket()
{
}

UCACRedirectPacket& UCACRedirectPacket::operator=(const UCACRedirectPacket& other)
{
    if (this==&other) return *this;
    UCACPacket::operator=(other);
    copy(other);
    return *this;
}

void UCACRedirectPacket::copy(const UCACRedirectPacket& other)
{
    this->ID_var = other.ID_var;
    this->Redirect_URI_var = other.Redirect_URI_var;
    this->access_policy_var = other.access_policy_var;
}

void UCACRedirectPacket::parsimPack(cCommBuffer *b)
{
    UCACPacket::parsimPack(b);
    doPacking(b,this->ID_var);
    doPacking(b,this->Redirect_URI_var);
    doPacking(b,this->access_policy_var);
}

void UCACRedirectPacket::parsimUnpack(cCommBuffer *b)
{
    UCACPacket::parsimUnpack(b);
    doUnpacking(b,this->ID_var);
    doUnpacking(b,this->Redirect_URI_var);
    doUnpacking(b,this->access_policy_var);
}

const char * UCACRedirectPacket::getID() const
{
    return ID_var.c_str();
}

void UCACRedirectPacket::setID(const char * ID)
{
    this->ID_var = ID;
}

const char * UCACRedirectPacket::getRedirect_URI() const
{
    return Redirect_URI_var.c_str();
}

void UCACRedirectPacket::setRedirect_URI(const char * Redirect_URI)
{
    this->Redirect_URI_var = Redirect_URI;
}

const char * UCACRedirectPacket::getAccess_policy() const
{
    return access_policy_var.c_str();
}

void UCACRedirectPacket::setAccess_policy(const char * access_policy)
{
    this->access_policy_var = access_policy;
}

class UCACRedirectPacketDescriptor : public cClassDescriptor
{
  public:
    UCACRedirectPacketDescriptor();
    virtual ~UCACRedirectPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(UCACRedirectPacketDescriptor);

UCACRedirectPacketDescriptor::UCACRedirectPacketDescriptor() : cClassDescriptor("UCACRedirectPacket", "UCACPacket")
{
}

UCACRedirectPacketDescriptor::~UCACRedirectPacketDescriptor()
{
}

bool UCACRedirectPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UCACRedirectPacket *>(obj)!=NULL;
}

const char *UCACRedirectPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UCACRedirectPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int UCACRedirectPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *UCACRedirectPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "ID",
        "Redirect_URI",
        "access_policy",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int UCACRedirectPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='I' && strcmp(fieldName, "ID")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "Redirect_URI")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "access_policy")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UCACRedirectPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *UCACRedirectPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int UCACRedirectPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UCACRedirectPacket *pp = (UCACRedirectPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UCACRedirectPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UCACRedirectPacket *pp = (UCACRedirectPacket *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getID());
        case 1: return oppstring2string(pp->getRedirect_URI());
        case 2: return oppstring2string(pp->getAccess_policy());
        default: return "";
    }
}

bool UCACRedirectPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UCACRedirectPacket *pp = (UCACRedirectPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setID((value)); return true;
        case 1: pp->setRedirect_URI((value)); return true;
        case 2: pp->setAccess_policy((value)); return true;
        default: return false;
    }
}

const char *UCACRedirectPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *UCACRedirectPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UCACRedirectPacket *pp = (UCACRedirectPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(UCACRedirectDesPacket);

UCACRedirectDesPacket::UCACRedirectDesPacket(const char *name, int kind) : UCACPacket(name,kind)
{
    this->ID_var = 0;
    this->Redirect_URI_var = 0;
}

UCACRedirectDesPacket::UCACRedirectDesPacket(const UCACRedirectDesPacket& other) : UCACPacket(other)
{
    copy(other);
}

UCACRedirectDesPacket::~UCACRedirectDesPacket()
{
}

UCACRedirectDesPacket& UCACRedirectDesPacket::operator=(const UCACRedirectDesPacket& other)
{
    if (this==&other) return *this;
    UCACPacket::operator=(other);
    copy(other);
    return *this;
}

void UCACRedirectDesPacket::copy(const UCACRedirectDesPacket& other)
{
    this->ID_var = other.ID_var;
    this->Redirect_URI_var = other.Redirect_URI_var;
    this->nounce_var = other.nounce_var;
}

void UCACRedirectDesPacket::parsimPack(cCommBuffer *b)
{
    UCACPacket::parsimPack(b);
    doPacking(b,this->ID_var);
    doPacking(b,this->Redirect_URI_var);
    doPacking(b,this->nounce_var);
}

void UCACRedirectDesPacket::parsimUnpack(cCommBuffer *b)
{
    UCACPacket::parsimUnpack(b);
    doUnpacking(b,this->ID_var);
    doUnpacking(b,this->Redirect_URI_var);
    doUnpacking(b,this->nounce_var);
}

const char * UCACRedirectDesPacket::getID() const
{
    return ID_var.c_str();
}

void UCACRedirectDesPacket::setID(const char * ID)
{
    this->ID_var = ID;
}

const char * UCACRedirectDesPacket::getRedirect_URI() const
{
    return Redirect_URI_var.c_str();
}

void UCACRedirectDesPacket::setRedirect_URI(const char * Redirect_URI)
{
    this->Redirect_URI_var = Redirect_URI;
}

element_s& UCACRedirectDesPacket::getNounce()
{
    return nounce_var;
}

void UCACRedirectDesPacket::setNounce(const element_s& nounce)
{
    this->nounce_var = nounce;
}

class UCACRedirectDesPacketDescriptor : public cClassDescriptor
{
  public:
    UCACRedirectDesPacketDescriptor();
    virtual ~UCACRedirectDesPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(UCACRedirectDesPacketDescriptor);

UCACRedirectDesPacketDescriptor::UCACRedirectDesPacketDescriptor() : cClassDescriptor("UCACRedirectDesPacket", "UCACPacket")
{
}

UCACRedirectDesPacketDescriptor::~UCACRedirectDesPacketDescriptor()
{
}

bool UCACRedirectDesPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UCACRedirectDesPacket *>(obj)!=NULL;
}

const char *UCACRedirectDesPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UCACRedirectDesPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int UCACRedirectDesPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *UCACRedirectDesPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "ID",
        "Redirect_URI",
        "nounce",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int UCACRedirectDesPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='I' && strcmp(fieldName, "ID")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "Redirect_URI")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "nounce")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UCACRedirectDesPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "element_s",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *UCACRedirectDesPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int UCACRedirectDesPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UCACRedirectDesPacket *pp = (UCACRedirectDesPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UCACRedirectDesPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UCACRedirectDesPacket *pp = (UCACRedirectDesPacket *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getID());
        case 1: return oppstring2string(pp->getRedirect_URI());
        case 2: {std::stringstream out; out << pp->getNounce(); return out.str();}
        default: return "";
    }
}

bool UCACRedirectDesPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UCACRedirectDesPacket *pp = (UCACRedirectDesPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setID((value)); return true;
        case 1: pp->setRedirect_URI((value)); return true;
        default: return false;
    }
}

const char *UCACRedirectDesPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        "element_s",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *UCACRedirectDesPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UCACRedirectDesPacket *pp = (UCACRedirectDesPacket *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getNounce()); break;
        default: return NULL;
    }
}

Register_Class(UCACAuthenticatePacket);

UCACAuthenticatePacket::UCACAuthenticatePacket(const char *name, int kind) : UCACPacket(name,kind)
{
    this->ID_var = 0;
    this->credential_var = 0;
}

UCACAuthenticatePacket::UCACAuthenticatePacket(const UCACAuthenticatePacket& other) : UCACPacket(other)
{
    copy(other);
}

UCACAuthenticatePacket::~UCACAuthenticatePacket()
{
}

UCACAuthenticatePacket& UCACAuthenticatePacket::operator=(const UCACAuthenticatePacket& other)
{
    if (this==&other) return *this;
    UCACPacket::operator=(other);
    copy(other);
    return *this;
}

void UCACAuthenticatePacket::copy(const UCACAuthenticatePacket& other)
{
    this->ID_var = other.ID_var;
    this->credential_var = other.credential_var;
}

void UCACAuthenticatePacket::parsimPack(cCommBuffer *b)
{
    UCACPacket::parsimPack(b);
    doPacking(b,this->ID_var);
    doPacking(b,this->credential_var);
}

void UCACAuthenticatePacket::parsimUnpack(cCommBuffer *b)
{
    UCACPacket::parsimUnpack(b);
    doUnpacking(b,this->ID_var);
    doUnpacking(b,this->credential_var);
}

const char * UCACAuthenticatePacket::getID() const
{
    return ID_var.c_str();
}

void UCACAuthenticatePacket::setID(const char * ID)
{
    this->ID_var = ID;
}

const char * UCACAuthenticatePacket::getCredential() const
{
    return credential_var.c_str();
}

void UCACAuthenticatePacket::setCredential(const char * credential)
{
    this->credential_var = credential;
}

class UCACAuthenticatePacketDescriptor : public cClassDescriptor
{
  public:
    UCACAuthenticatePacketDescriptor();
    virtual ~UCACAuthenticatePacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(UCACAuthenticatePacketDescriptor);

UCACAuthenticatePacketDescriptor::UCACAuthenticatePacketDescriptor() : cClassDescriptor("UCACAuthenticatePacket", "UCACPacket")
{
}

UCACAuthenticatePacketDescriptor::~UCACAuthenticatePacketDescriptor()
{
}

bool UCACAuthenticatePacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UCACAuthenticatePacket *>(obj)!=NULL;
}

const char *UCACAuthenticatePacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UCACAuthenticatePacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int UCACAuthenticatePacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *UCACAuthenticatePacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "ID",
        "credential",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int UCACAuthenticatePacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='I' && strcmp(fieldName, "ID")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "credential")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UCACAuthenticatePacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *UCACAuthenticatePacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int UCACAuthenticatePacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UCACAuthenticatePacket *pp = (UCACAuthenticatePacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UCACAuthenticatePacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UCACAuthenticatePacket *pp = (UCACAuthenticatePacket *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getID());
        case 1: return oppstring2string(pp->getCredential());
        default: return "";
    }
}

bool UCACAuthenticatePacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UCACAuthenticatePacket *pp = (UCACAuthenticatePacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setID((value)); return true;
        case 1: pp->setCredential((value)); return true;
        default: return false;
    }
}

const char *UCACAuthenticatePacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *UCACAuthenticatePacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UCACAuthenticatePacket *pp = (UCACAuthenticatePacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(UCACTokenPacket);

UCACTokenPacket::UCACTokenPacket(const char *name, int kind) : UCACPacket(name,kind)
{
    this->procId_var = 0;
}

UCACTokenPacket::UCACTokenPacket(const UCACTokenPacket& other) : UCACPacket(other)
{
    copy(other);
}

UCACTokenPacket::~UCACTokenPacket()
{
}

UCACTokenPacket& UCACTokenPacket::operator=(const UCACTokenPacket& other)
{
    if (this==&other) return *this;
    UCACPacket::operator=(other);
    copy(other);
    return *this;
}

void UCACTokenPacket::copy(const UCACTokenPacket& other)
{
    this->sk_token_var = other.sk_token_var;
    this->nounce_var = other.nounce_var;
    this->procId_var = other.procId_var;
}

void UCACTokenPacket::parsimPack(cCommBuffer *b)
{
    UCACPacket::parsimPack(b);
    doPacking(b,this->sk_token_var);
    doPacking(b,this->nounce_var);
    doPacking(b,this->procId_var);
}

void UCACTokenPacket::parsimUnpack(cCommBuffer *b)
{
    UCACPacket::parsimUnpack(b);
    doUnpacking(b,this->sk_token_var);
    doUnpacking(b,this->nounce_var);
    doUnpacking(b,this->procId_var);
}

Token& UCACTokenPacket::getSk_token()
{
    return sk_token_var;
}

void UCACTokenPacket::setSk_token(const Token& sk_token)
{
    this->sk_token_var = sk_token;
}

element_s& UCACTokenPacket::getNounce()
{
    return nounce_var;
}

void UCACTokenPacket::setNounce(const element_s& nounce)
{
    this->nounce_var = nounce;
}

int UCACTokenPacket::getProcId() const
{
    return procId_var;
}

void UCACTokenPacket::setProcId(int procId)
{
    this->procId_var = procId;
}

class UCACTokenPacketDescriptor : public cClassDescriptor
{
  public:
    UCACTokenPacketDescriptor();
    virtual ~UCACTokenPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(UCACTokenPacketDescriptor);

UCACTokenPacketDescriptor::UCACTokenPacketDescriptor() : cClassDescriptor("UCACTokenPacket", "UCACPacket")
{
}

UCACTokenPacketDescriptor::~UCACTokenPacketDescriptor()
{
}

bool UCACTokenPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UCACTokenPacket *>(obj)!=NULL;
}

const char *UCACTokenPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UCACTokenPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int UCACTokenPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *UCACTokenPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sk_token",
        "nounce",
        "procId",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int UCACTokenPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sk_token")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nounce")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "procId")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UCACTokenPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "Token",
        "element_s",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *UCACTokenPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int UCACTokenPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UCACTokenPacket *pp = (UCACTokenPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UCACTokenPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UCACTokenPacket *pp = (UCACTokenPacket *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSk_token(); return out.str();}
        case 1: {std::stringstream out; out << pp->getNounce(); return out.str();}
        case 2: return long2string(pp->getProcId());
        default: return "";
    }
}

bool UCACTokenPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UCACTokenPacket *pp = (UCACTokenPacket *)object; (void)pp;
    switch (field) {
        case 2: pp->setProcId(string2long(value)); return true;
        default: return false;
    }
}

const char *UCACTokenPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "Token",
        "element_s",
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *UCACTokenPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UCACTokenPacket *pp = (UCACTokenPacket *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSk_token()); break;
        case 1: return (void *)(&pp->getNounce()); break;
        default: return NULL;
    }
}

Register_Class(UCACDataPacket);

UCACDataPacket::UCACDataPacket(const char *name, int kind) : UCACPacket(name,kind)
{
    this->Payload_var = 0;
}

UCACDataPacket::UCACDataPacket(const UCACDataPacket& other) : UCACPacket(other)
{
    copy(other);
}

UCACDataPacket::~UCACDataPacket()
{
}

UCACDataPacket& UCACDataPacket::operator=(const UCACDataPacket& other)
{
    if (this==&other) return *this;
    UCACPacket::operator=(other);
    copy(other);
    return *this;
}

void UCACDataPacket::copy(const UCACDataPacket& other)
{
    this->Payload_var = other.Payload_var;
}

void UCACDataPacket::parsimPack(cCommBuffer *b)
{
    UCACPacket::parsimPack(b);
    doPacking(b,this->Payload_var);
}

void UCACDataPacket::parsimUnpack(cCommBuffer *b)
{
    UCACPacket::parsimUnpack(b);
    doUnpacking(b,this->Payload_var);
}

const char * UCACDataPacket::getPayload() const
{
    return Payload_var.c_str();
}

void UCACDataPacket::setPayload(const char * Payload)
{
    this->Payload_var = Payload;
}

class UCACDataPacketDescriptor : public cClassDescriptor
{
  public:
    UCACDataPacketDescriptor();
    virtual ~UCACDataPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(UCACDataPacketDescriptor);

UCACDataPacketDescriptor::UCACDataPacketDescriptor() : cClassDescriptor("UCACDataPacket", "UCACPacket")
{
}

UCACDataPacketDescriptor::~UCACDataPacketDescriptor()
{
}

bool UCACDataPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UCACDataPacket *>(obj)!=NULL;
}

const char *UCACDataPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UCACDataPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int UCACDataPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *UCACDataPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Payload",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int UCACDataPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='P' && strcmp(fieldName, "Payload")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UCACDataPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *UCACDataPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int UCACDataPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UCACDataPacket *pp = (UCACDataPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UCACDataPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UCACDataPacket *pp = (UCACDataPacket *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getPayload());
        default: return "";
    }
}

bool UCACDataPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UCACDataPacket *pp = (UCACDataPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setPayload((value)); return true;
        default: return false;
    }
}

const char *UCACDataPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *UCACDataPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UCACDataPacket *pp = (UCACDataPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(UCACInitializePacket);

UCACInitializePacket::UCACInitializePacket(const char *name, int kind) : UCACPacket(name,kind)
{
}

UCACInitializePacket::UCACInitializePacket(const UCACInitializePacket& other) : UCACPacket(other)
{
    copy(other);
}

UCACInitializePacket::~UCACInitializePacket()
{
}

UCACInitializePacket& UCACInitializePacket::operator=(const UCACInitializePacket& other)
{
    if (this==&other) return *this;
    UCACPacket::operator=(other);
    copy(other);
    return *this;
}

void UCACInitializePacket::copy(const UCACInitializePacket& other)
{
    this->pairing_var = other.pairing_var;
    this->g_var = other.g_var;
    this->h_var = other.h_var;
    this->f_var = other.f_var;
    this->beta_var = other.beta_var;
    this->owner_sk_var = other.owner_sk_var;
    this->owner_pub_var = other.owner_pub_var;
}

void UCACInitializePacket::parsimPack(cCommBuffer *b)
{
    UCACPacket::parsimPack(b);
    doPacking(b,this->pairing_var);
    doPacking(b,this->g_var);
    doPacking(b,this->h_var);
    doPacking(b,this->f_var);
    doPacking(b,this->beta_var);
    doPacking(b,this->owner_sk_var);
    doPacking(b,this->owner_pub_var);
}

void UCACInitializePacket::parsimUnpack(cCommBuffer *b)
{
    UCACPacket::parsimUnpack(b);
    doUnpacking(b,this->pairing_var);
    doUnpacking(b,this->g_var);
    doUnpacking(b,this->h_var);
    doUnpacking(b,this->f_var);
    doUnpacking(b,this->beta_var);
    doUnpacking(b,this->owner_sk_var);
    doUnpacking(b,this->owner_pub_var);
}

pairing_s& UCACInitializePacket::getPairing()
{
    return pairing_var;
}

void UCACInitializePacket::setPairing(const pairing_s& pairing)
{
    this->pairing_var = pairing;
}

element_s& UCACInitializePacket::getG()
{
    return g_var;
}

void UCACInitializePacket::setG(const element_s& g)
{
    this->g_var = g;
}

element_s& UCACInitializePacket::getH()
{
    return h_var;
}

void UCACInitializePacket::setH(const element_s& h)
{
    this->h_var = h;
}

element_s& UCACInitializePacket::getF()
{
    return f_var;
}

void UCACInitializePacket::setF(const element_s& f)
{
    this->f_var = f;
}

element_s& UCACInitializePacket::getBeta()
{
    return beta_var;
}

void UCACInitializePacket::setBeta(const element_s& beta)
{
    this->beta_var = beta;
}

element_s& UCACInitializePacket::getOwner_sk()
{
    return owner_sk_var;
}

void UCACInitializePacket::setOwner_sk(const element_s& owner_sk)
{
    this->owner_sk_var = owner_sk;
}

element_s& UCACInitializePacket::getOwner_pub()
{
    return owner_pub_var;
}

void UCACInitializePacket::setOwner_pub(const element_s& owner_pub)
{
    this->owner_pub_var = owner_pub;
}

class UCACInitializePacketDescriptor : public cClassDescriptor
{
  public:
    UCACInitializePacketDescriptor();
    virtual ~UCACInitializePacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(UCACInitializePacketDescriptor);

UCACInitializePacketDescriptor::UCACInitializePacketDescriptor() : cClassDescriptor("UCACInitializePacket", "UCACPacket")
{
}

UCACInitializePacketDescriptor::~UCACInitializePacketDescriptor()
{
}

bool UCACInitializePacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UCACInitializePacket *>(obj)!=NULL;
}

const char *UCACInitializePacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UCACInitializePacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int UCACInitializePacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *UCACInitializePacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pairing",
        "g",
        "h",
        "f",
        "beta",
        "owner_sk",
        "owner_pub",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int UCACInitializePacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pairing")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "g")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "h")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "f")==0) return base+3;
    if (fieldName[0]=='b' && strcmp(fieldName, "beta")==0) return base+4;
    if (fieldName[0]=='o' && strcmp(fieldName, "owner_sk")==0) return base+5;
    if (fieldName[0]=='o' && strcmp(fieldName, "owner_pub")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UCACInitializePacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "pairing_s",
        "element_s",
        "element_s",
        "element_s",
        "element_s",
        "element_s",
        "element_s",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *UCACInitializePacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int UCACInitializePacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UCACInitializePacket *pp = (UCACInitializePacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UCACInitializePacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UCACInitializePacket *pp = (UCACInitializePacket *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getPairing(); return out.str();}
        case 1: {std::stringstream out; out << pp->getG(); return out.str();}
        case 2: {std::stringstream out; out << pp->getH(); return out.str();}
        case 3: {std::stringstream out; out << pp->getF(); return out.str();}
        case 4: {std::stringstream out; out << pp->getBeta(); return out.str();}
        case 5: {std::stringstream out; out << pp->getOwner_sk(); return out.str();}
        case 6: {std::stringstream out; out << pp->getOwner_pub(); return out.str();}
        default: return "";
    }
}

bool UCACInitializePacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UCACInitializePacket *pp = (UCACInitializePacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UCACInitializePacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "pairing_s",
        "element_s",
        "element_s",
        "element_s",
        "element_s",
        "element_s",
        "element_s",
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *UCACInitializePacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UCACInitializePacket *pp = (UCACInitializePacket *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getPairing()); break;
        case 1: return (void *)(&pp->getG()); break;
        case 2: return (void *)(&pp->getH()); break;
        case 3: return (void *)(&pp->getF()); break;
        case 4: return (void *)(&pp->getBeta()); break;
        case 5: return (void *)(&pp->getOwner_sk()); break;
        case 6: return (void *)(&pp->getOwner_pub()); break;
        default: return NULL;
    }
}


