//
// Generated file, do not edit! Created by nedtool 4.6 from DynaPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "DynaPacket_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("DynaPacketType");
    if (!e) enums.getInstance()->add(e = new cEnum("DynaPacketType"));
    e->insert(DYNA_CONN_REQ, "DYNA_CONN_REQ");
    e->insert(DYNA_CONN_ACK, "DYNA_CONN_ACK");
    e->insert(DYNA_DISC_REQ, "DYNA_DISC_REQ");
    e->insert(DYNA_DISC_ACK, "DYNA_DISC_ACK");
    e->insert(DYNA_DATA, "DYNA_DATA");
);

Register_Class(DynaPacket);

DynaPacket::DynaPacket(const char *name, int kind) : ::cPacket(name,kind)
{
    this->srcAddress_var = 0;
    this->destAddress_var = 0;
    this->serverProcId_var = 0;
}

DynaPacket::DynaPacket(const DynaPacket& other) : ::cPacket(other)
{
    copy(other);
}

DynaPacket::~DynaPacket()
{
}

DynaPacket& DynaPacket::operator=(const DynaPacket& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DynaPacket::copy(const DynaPacket& other)
{
    this->srcAddress_var = other.srcAddress_var;
    this->destAddress_var = other.destAddress_var;
    this->serverProcId_var = other.serverProcId_var;
}

void DynaPacket::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->srcAddress_var);
    doPacking(b,this->destAddress_var);
    doPacking(b,this->serverProcId_var);
}

void DynaPacket::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->srcAddress_var);
    doUnpacking(b,this->destAddress_var);
    doUnpacking(b,this->serverProcId_var);
}

int DynaPacket::getSrcAddress() const
{
    return srcAddress_var;
}

void DynaPacket::setSrcAddress(int srcAddress)
{
    this->srcAddress_var = srcAddress;
}

int DynaPacket::getDestAddress() const
{
    return destAddress_var;
}

void DynaPacket::setDestAddress(int destAddress)
{
    this->destAddress_var = destAddress;
}

int DynaPacket::getServerProcId() const
{
    return serverProcId_var;
}

void DynaPacket::setServerProcId(int serverProcId)
{
    this->serverProcId_var = serverProcId;
}

class DynaPacketDescriptor : public cClassDescriptor
{
  public:
    DynaPacketDescriptor();
    virtual ~DynaPacketDescriptor();

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

Register_ClassDescriptor(DynaPacketDescriptor);

DynaPacketDescriptor::DynaPacketDescriptor() : cClassDescriptor("DynaPacket", "cPacket")
{
}

DynaPacketDescriptor::~DynaPacketDescriptor()
{
}

bool DynaPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DynaPacket *>(obj)!=NULL;
}

const char *DynaPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DynaPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int DynaPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *DynaPacketDescriptor::getFieldName(void *object, int field) const
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
        "serverProcId",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int DynaPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddress")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "serverProcId")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DynaPacketDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *DynaPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int DynaPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DynaPacket *pp = (DynaPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DynaPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DynaPacket *pp = (DynaPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcAddress());
        case 1: return long2string(pp->getDestAddress());
        case 2: return long2string(pp->getServerProcId());
        default: return "";
    }
}

bool DynaPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DynaPacket *pp = (DynaPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcAddress(string2long(value)); return true;
        case 1: pp->setDestAddress(string2long(value)); return true;
        case 2: pp->setServerProcId(string2long(value)); return true;
        default: return false;
    }
}

const char *DynaPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *DynaPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DynaPacket *pp = (DynaPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DynaDataPacket);

DynaDataPacket::DynaDataPacket(const char *name, int kind) : ::DynaPacket(name,kind)
{
    this->payload_var = 0;
}

DynaDataPacket::DynaDataPacket(const DynaDataPacket& other) : ::DynaPacket(other)
{
    copy(other);
}

DynaDataPacket::~DynaDataPacket()
{
}

DynaDataPacket& DynaDataPacket::operator=(const DynaDataPacket& other)
{
    if (this==&other) return *this;
    ::DynaPacket::operator=(other);
    copy(other);
    return *this;
}

void DynaDataPacket::copy(const DynaDataPacket& other)
{
    this->payload_var = other.payload_var;
}

void DynaDataPacket::parsimPack(cCommBuffer *b)
{
    ::DynaPacket::parsimPack(b);
    doPacking(b,this->payload_var);
}

void DynaDataPacket::parsimUnpack(cCommBuffer *b)
{
    ::DynaPacket::parsimUnpack(b);
    doUnpacking(b,this->payload_var);
}

const char * DynaDataPacket::getPayload() const
{
    return payload_var.c_str();
}

void DynaDataPacket::setPayload(const char * payload)
{
    this->payload_var = payload;
}

class DynaDataPacketDescriptor : public cClassDescriptor
{
  public:
    DynaDataPacketDescriptor();
    virtual ~DynaDataPacketDescriptor();

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

Register_ClassDescriptor(DynaDataPacketDescriptor);

DynaDataPacketDescriptor::DynaDataPacketDescriptor() : cClassDescriptor("DynaDataPacket", "DynaPacket")
{
}

DynaDataPacketDescriptor::~DynaDataPacketDescriptor()
{
}

bool DynaDataPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DynaDataPacket *>(obj)!=NULL;
}

const char *DynaDataPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DynaDataPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int DynaDataPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *DynaDataPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "payload",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int DynaDataPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payload")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DynaDataPacketDescriptor::getFieldTypeString(void *object, int field) const
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

const char *DynaDataPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int DynaDataPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DynaDataPacket *pp = (DynaDataPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DynaDataPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DynaDataPacket *pp = (DynaDataPacket *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getPayload());
        default: return "";
    }
}

bool DynaDataPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DynaDataPacket *pp = (DynaDataPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setPayload((value)); return true;
        default: return false;
    }
}

const char *DynaDataPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *DynaDataPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DynaDataPacket *pp = (DynaDataPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


