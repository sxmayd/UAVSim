//
// Generated file, do not edit! Created by nedtool 4.6 from GPSPacket.msg.
//

#ifndef _GPSPACKET_M_H_
#define _GPSPACKET_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "INETDefs.h"
// }}

/**
 * Class generated from <tt>GPSPacket.msg:27</tt> by nedtool.
 * <pre>
 * //
 * // Represents an GPS packet, to be used with the ~GPS module.
 * //
 * packet GPSPacket
 * {
 *     unsigned short sourcePort;
 *     unsigned short destinationPort;
 *     double longitude;
 *     double latitude;
 *     double altitude;
 *     double elevation;
 *     double distance[];
 * }
 * </pre>
 */
class GPSPacket : public ::cPacket
{
  protected:
    unsigned short sourcePort_var;
    unsigned short destinationPort_var;
    double longitude_var;
    double latitude_var;
    double altitude_var;
    double elevation_var;
    double *distance_var; // array ptr
    unsigned int distance_arraysize;

  private:
    void copy(const GPSPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const GPSPacket&);

  public:
    GPSPacket(const char *name=NULL, int kind=0);
    GPSPacket(const GPSPacket& other);
    virtual ~GPSPacket();
    GPSPacket& operator=(const GPSPacket& other);
    virtual GPSPacket *dup() const {return new GPSPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned short getSourcePort() const;
    virtual void setSourcePort(unsigned short sourcePort);
    virtual unsigned short getDestinationPort() const;
    virtual void setDestinationPort(unsigned short destinationPort);
    virtual double getLongitude() const;
    virtual void setLongitude(double longitude);
    virtual double getLatitude() const;
    virtual void setLatitude(double latitude);
    virtual double getAltitude() const;
    virtual void setAltitude(double altitude);
    virtual double getElevation() const;
    virtual void setElevation(double elevation);
    virtual void setDistanceArraySize(unsigned int size);
    virtual unsigned int getDistanceArraySize() const;
    virtual double getDistance(unsigned int k) const;
    virtual void setDistance(unsigned int k, double distance);
};

inline void doPacking(cCommBuffer *b, GPSPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, GPSPacket& obj) {obj.parsimUnpack(b);}


#endif // ifndef _GPSPACKET_M_H_

