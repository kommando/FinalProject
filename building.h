/* 
 * File:   building.h
 * Author: Daniel Crandall
 *
 * Created on July 21, 2014, 6:16 PM
 */

#ifndef BUILDING_H
#define	BUILDING_H

#include "floor.h"
#include <cstdlib>

using namespace std;

class Building {
public:
    vector<Floor> floors; // this vector holds the floor objects for the building

    Building() { // default empty constructor
    };

    Building(int numberOfFloors) { // constructor with number of floors
        for (int i = 0; i < numberOfFloors; i++) { // loop till reaching the desired number
            Floor *floor1; // create a pointer for a floor object
            floor1 = new Floor; // put a new floor object in that location
            floors.push_back(*floor1); // push a floor object into the vector
        }
    };

    ~Building() { // the default destructor
    };

    void addFloor() { // add a floor method for a building object
        Floor *floor1; // create a pointer to a floor object
        floor1 = new Floor; // put a new floor object in that location
        floors.push_back(*floor1); // push a floor object into the vector
    }

    int getNumberOfFloors() {
        return floors.size(); // retrieve the number of floor objects in the building
    };

private:
};

class BuildingFactory {
    /*
     * This class creates a full building object with all floors, rooms, and access points
     */
public:

    BuildingFactory() { // default empty constructor
    };

    void build() { // the heavy lifting method for this class
        /*
         The following is a dialogue used to create a building and associated sub-parts (classes) 
         */
        cout << endl << endl;
        cout << "##############################################################" << endl;
        cout << "#                                                            #" << endl;
        cout << "# This program will create a building to your specifications #" << endl;
        cout << "#                                                            #" << endl;
        cout << "##############################################################" << endl << endl;

        cout << "[?] How many floors will be in your building?" << endl;
        cin >> numberOfFloors;
        for (int x = 0; x < numberOfFloors; ++x) {
            building.addFloor();
            cout << "[?] How many rooms on floor number " << x + 1 << "?" << endl;
            cin >> numberOfRooms;
            for (int y = 0; y < numberOfRooms; ++y) {
                building.floors.at(x).addRoom();
                cout << "[?] How many access points are in room " << y + 1 << " on floor " << x + 1 << "?" << endl;
                cin >> numberOfAccessPoints;
                for (int z = 0; z < numberOfAccessPoints; ++z) {
                    building.floors.at(x).rooms.at(y).addAccessPoint();
                }
            }
        }
        cout << "##############################################################" << endl;
        cout << "#                       Done Building                        #" << endl;
        cout << "##############################################################" << endl << endl;
    }

    Building deliver() { // used to return the building object after building
        return building;
    }

private:
    int numberOfFloors; // hold  the input for floors in the building
    int numberOfRooms; // holds the input for rooms on the floor
    int numberOfAccessPoints; // holds the input for access points in a room
    char ans1; // holds answer for question #1
    int ans2; // holds answer for question #2
    Building building; // create the building we will pass to the building manager later
};

class BuildingManager {
    /*
     * Takes a building object and can:
     *  Turn APs on and off
     *  Add floors to the building
     *  Add rooms to the floors of the building
     *  Add APs to the rooms of the building
     */

public:

    BuildingManager(Building building) {
        // building manager must be instantiated with a building object
        bldg = building;
    };

    void getProperties() { // displays the properties of the building being managed
        cout << "##############################################################" << endl;
        cout << "#                 The status of the building is              #" << endl;
        cout << "##############################################################" << endl;
        cout << "                                                             #" << endl;
        cout << "[B] The building has " << bldg.getNumberOfFloors() << " floors" << "                                #" << endl;
        for (int x = 0; x < bldg.getNumberOfFloors(); x++) {
            cout << "  [F] Floor " << x + 1 << " has " << bldg.floors.at(x).getNumberOfRooms() << " rooms" "                                    #" << endl;
            for (int y = 0; y < bldg.floors.at(x).getNumberOfRooms(); y++) {
                cout << "    [R] Room number " << y + 1 << " on floor " << x + 1 << " has " << bldg.floors.at(x).rooms.at(y).getNumberOfAccessPoints() << " access points" "         #" << endl;
                for (int z = 0; z < bldg.floors.at(x).rooms.at(y).getNumberOfAccessPoints(); z++) {
                    cout << "      " << bldg.floors.at(x).rooms.at(y).accessPoints.at(z) << "       #" << endl;
                }
            }
        }
        cout << "                                                             #" << endl;
        cout << "##############################################################" << endl << endl;
    };

    void manage() {
        int ans;
        int ap;
        int rm;
        int flr;

        cout << "##############################################################" << endl;
        cout << "#                 Management System Online                   #" << endl;
        cout << "##############################################################" << endl << endl << endl;

        while (true) {
            cout << "[?] What would you like to do?" << endl;
            cout << "\t[1] Add a floor" << endl;
            cout << "\t[2] Add a room" << endl;
            cout << "\t[3] Add an access point" << endl;
            cout << "\t[4] Turn an access point on" << endl;
            cout << "\t[5] Turn an access point off" << endl;
            cout << "\t[6] View building status/properties" << endl;
            cout << "\t[7] Exit the management system" << endl;
            cin >> ans;

            switch (ans) {
                case 1: cout << "[>] Adding a floor" << endl;
                    bldg.addFloor();
                    break;
                case 2: cout << "[?] On what floor?" << endl;
                    cin >> flr;
                    cout << "[>] Adding a room" << endl;
                    bldg.floors.at(flr - 1).addRoom();
                    break;
                case 3: cout << "[?] On what floor?" << endl;
                    cin >> flr;
                    cout << "[?] In what what room on floor" << flr << "?" << endl;
                    cin >> rm;
                    cout << "[>] Adding an AP" << endl;
                    bldg.floors.at(flr - 1).rooms.at(rm -1 ).addAccessPoint();
                    break;
                case 4: cout << "[?] On what floor?" << endl;
                    cin >> flr;
                    cout << "[?] In what what room on floor " << flr << "?" << endl;
                    cin >> rm;
                    cout << "[?] Which access point in room" << rm << "?" << endl;
                    cin >> ap;
                    cout << "[>] Turning on AP " << ap << " in room " << rm << " on floor " << flr << endl;
                    bldg.floors.at(flr - 1).rooms.at(rm - 1).accessPoints.at(ap - 1).PowerOn();
                    bldg.floors.at(flr - 1).rooms.at(rm - 1).accessPoints.at(ap - 1).setMonthTurnedOn(October);
                    break;
                case 5: cout << "[?] On what floor?" << endl;
                    cin >> flr;
                    cout << "[?] In what what room on floor " << flr << "?" << endl;
                    cin >> rm;
                    cout << "[?] Which access point in room " << rm << "?" << endl;
                    cin >> ap;
                    cout << "[>] Turning off AP " << ap << " in room " << rm << " on floor " << flr << endl;
                    bldg.floors.at(flr -1).rooms.at(rm - 1).accessPoints.at(ap -1).PowerOff();
                    break;
                case 6: getProperties();
                    break;
                case 7: cout << "[>] Exiting, goodbye!" << endl;
                    exit(0);
                    break;
                default: continue;
                    break;
            }
        }


    };

    void powerOnAP(int floor, int room, int ap, MONTH month) {
        // can power on any AP in the building given its floor, room, AP number, and the month
        if (ap < bldg.floors.at(floor).rooms.at(room).getNumberOfAccessPoints()) {
            bldg.floors.at(floor).rooms.at(room).accessPoints.at(ap).PowerOn();
            bldg.floors.at(floor).rooms.at(room).accessPoints.at(ap).setMonthTurnedOn(month);
        }
    };

    void powerOffAP(int floor, int room, int ap) {
        // can power on any AP in the building given its floor, room, and AP number
        if (ap < bldg.floors.at(floor).rooms.at(room).getNumberOfAccessPoints()) {
            bldg.floors.at(floor).rooms.at(room).accessPoints.at(ap).PowerOff();
            bldg.floors.at(floor).rooms.at(room).accessPoints.at(ap).setMonthTurnedOn(Null);
        }
    };

private:
    Building bldg; // the building object is held here and is private
};

#endif	/* BUILDING_H */

