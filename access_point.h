/* 
 * File:   accesspoint.h
 * Author: root
 *
 * Created on July 21, 2014, 6:29 PM
 */

#ifndef ACCESSPOINT_H
#define	ACCESSPOINT_H

#include <string>
#include <ostream>

using namespace std;

enum MONTH {
    Null = 0, January, February, March, April, May, June, July, August, September, October, November, December
};

class AccessPoint {
public:

    AccessPoint() { // empty constructor
        isPoweredOn = false;
        monthTurnedOn = 0;
    };

    AccessPoint(bool power, MONTH month) { // construct with power status and month
        isPoweredOn = power;
        monthTurnedOn = month;
    };

    AccessPoint(bool power, int month) { // construct with int of month instead
        isPoweredOn = power;
        monthTurnedOn = month;
    };

    virtual ~AccessPoint() { // default destructor
    };

    void PowerOn() { // power on the AP
        isPoweredOn = true;
    };

    void PowerOff() { // power off the AP
        isPoweredOn = false;
    };

    void setMonthTurnedOn(MONTH month) { // set the powered on month for the AP
        monthTurnedOn = month;
    };

    string getPowerStatus() { // get the power status for the AP
        return isPoweredOn ? "On" : "Off";
        // Using the ternary operator to return a string from a bool
    };

    int getMonthTurnedOn() { // get the powered on month for the AP
        return monthTurnedOn;
    };

private:
    bool isPoweredOn; // powered on status
    int monthTurnedOn; // month powered on
    friend ostream& operator<<(ostream&, const AccessPoint&);
    // override the << operator to reveal AP status
};

ostream& operator<<(ostream &strm, const AccessPoint &ap) {
    /* 
     * used for the AP statuses by overriding the "<<" operator similar to the "toString" method in Java
     */
    return strm << "[AP] AccessPoint (Power: " << ap.isPoweredOn << "/ Month Powered On: " << ap.monthTurnedOn << ")";
};


#endif	/* ACCESSPOINT_H */

