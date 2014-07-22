/* 
 * File:   room.h
 * Author: root
 *
 * Created on July 21, 2014, 6:28 PM
 */

#ifndef ROOM_H
#define	ROOM_H

#include <vector>
#include "access_point.h"

using namespace std;

class Room {
public:
    vector<AccessPoint> accessPoints; // vector hold the AP objects

    Room() {
    };

    Room(int numberOfAccessPoints) { // constructor with the number of APs
        for (int i = 0; i < numberOfAccessPoints; i++) { // loop to create multiple AP
            AccessPoint *ap1; // create an AP pointer
            ap1 = new AccessPoint; // put a new AP object in that location
            accessPoints.push_back(*ap1); // push that AP into the vector
        }
    };

    ~Room() { // default empty constructor
    };

    void addAccessPoint() { // method to add an AP tot he room
        AccessPoint *ap1; // create an AP pointer
        ap1 = new AccessPoint; // put a new AP object in that location
        accessPoints.push_back(*ap1); // push that AP into the vector
    };

    int getNumberOfAccessPoints() { // get the number of AP objects in the room
        return accessPoints.size(); // return the size of the vector
    };

private:
};

#endif	/* ROOM_H */

