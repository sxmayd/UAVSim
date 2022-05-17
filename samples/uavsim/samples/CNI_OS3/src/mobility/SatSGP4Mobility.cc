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

#include "SatSGP4Mobility.h"

Define_Module(SatSGP4Mobility);

using namespace std;

void SatSGP4Mobility::initialize(int stage)
{
    // noradModule must be initialized before LineSegmentsMobilityBase calling setTargetPosition() in its initialization at stage 1
    if(stage == 1)
    {
        noradModule->initializeMobility(nextChange);
    }
    LineSegmentsMobilityBase::initialize(stage);

    noradModule = check_and_cast< Norad* >(this->getParentModule()->getSubmodule("NoradModule"));
    if(noradModule == NULL)
    {
        error("Error in SatSGP4Mobility::initializeMobility(): Cannot find module Norad.");
    }

    tm *currentTime;
    time_t timestamp = time(0);
    currentTime = gmtime(&timestamp);

    // Convert to julian time
    noradModule->setJulian(currentTime);

    mapX = atoi(this->getParentModule()->getParentModule()->getDisplayString().getTagArg("bgb", 0));
    mapY = atoi(this->getParentModule()->getParentModule()->getDisplayString().getTagArg("bgb", 1));
    //cout << "\n"<< mapX <<endl;
    //cout << "\n" << mapY <<endl;
    transmitPower = this->getParentModule()->par("transmitPower");

    ev << "initializing SatSGP4Mobility stage " << stage << endl;
    WATCH(lastPosition);

    updateVisualRepresentation();
}

double SatSGP4Mobility::getAltitude() const
{
    return noradModule->getAltitude();
}

double SatSGP4Mobility::getElevation(const double &refLatitude, const double &refLongitude,
                                     const double &refAltitude) const
{
    return noradModule->getElevation(refLatitude, refLongitude, refAltitude);
}

double SatSGP4Mobility::getAzimuth(const double &refLatitude, const double &refLongitude,
                                   const double &refAltitude) const
{
    return noradModule->getAzimuth(refLatitude, refLongitude, refAltitude);
}

double SatSGP4Mobility::getDistance(const double &refLatitude, const double &refLongitude,
                                    const double &refAltitude) const
{
    cout<<"Inside SatSGP4Mobility: Distance - "<< noradModule->getDistance(refLatitude, refLongitude, refAltitude)<<endl;
    return noradModule->getDistance(refLatitude, refLongitude, refAltitude);
}

double SatSGP4Mobility::getLongitude() const
{
    return noradModule->getLongitude();
}

double SatSGP4Mobility::getLatitude() const
{
    return noradModule->getLatitude();
}

void SatSGP4Mobility::setTargetPosition()
{

    nextChange += updateInterval.dbl();
    noradModule->updateTime(nextChange);
    //cout<<"Next position satellite: "<<nextChange<<endl;   // added by farha for debugging July 12th 2014
    //cout<<"get longitude: "<<endl;                         // added by farha for debugging July 12th 2014
    lastPosition.x = mapX * noradModule->getLongitude() / 360 + (mapX / 2);
    //cout<<"last position 1: "<<lastPosition.x <<endl;         // added by farha for debugging July 12th 2014
    lastPosition.x = ((int)lastPosition.x % (int)mapX);
    //cout<<"last position 2: "<<lastPosition.x<<endl;          // added by farha for debugging July 12th 2014
    lastPosition.y = ((-mapY * noradModule->getLatitude()) / 180) + (mapY / 2); // from the "original" move function.

    targetPosition.x = lastPosition.x;
    targetPosition.y = lastPosition.y;

    //cout << targetPosition.x << " " << targetPosition.y << endl;
}

void SatSGP4Mobility::move()
{
    LineSegmentsMobilityBase::move();
    raiseErrorIfOutside();
}


void SatSGP4Mobility::fixIfHostGetsOutside()
{
    raiseErrorIfOutside();
}
