/* 
 * File:   Floor.h
 * Author: root
 *
 * Created on July 21, 2014, 6:22 PM
 */

#ifndef FLOOR_H
#define	FLOOR_H

#include "room.h"

using namespace std;

class Floor {
public:

    vector<Room> rooms; // vector holds the room objects for the floor

    Floor() { // the default empty constructor
    };

    Floor(int numberOfRooms) { // constructor that can allocate rooms on the floor auto-magically
        for (int i = 0; i < numberOfRooms; i++) { // loop till reaching the number
            Room *room1; // create a room pointer
            room1 = new Room; // place a new room object at that pointer
            rooms.push_back(*room1); // push that room object into the vector
        }
    };

    ~Floor() { // the default destructor
    };

    void addRoom() { // add a room one by one or append more rooms after the constructor
        Room *room1; // create a room pointer
        room1 = new Room; // place a new room object at that pointer
        rooms.push_back(*room1); // push that room object into the vector
    };

    int getNumberOfRooms() {
        return rooms.size(); // get the number of rooms on the floor
    };

private:

};

#endif	/* FLOOR_H */

