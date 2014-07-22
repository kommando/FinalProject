/* 
Imagine you are working for an in-house software team for a company that wants 
to monitor network access points in a building. Each building has a specified 
number of floors, a certain number of rooms per floor, and some number of network 
access points in a room. Each network access point is labeled with its state as 
being on or off and if it is on it has the month it was turned on. Design, 
implement, and test classes that represent buildings, floors, and network access
 points. Your classes should provide suitable observer methods that allow you to
 determine how many floors are in a building, how many rooms are on a floor, how
 many access points are in a room, and if an access point is on or off and which
 month it was turned on. You should also provide mutator methods that allow you 
to turn a network access point on or off and to set the month if it is turned on. 
You should use composition as a key strategy in designing these classes—thus, a 
building should contain floors, floors should contain rooms, and rooms should 
contain network access points. Your program should allow a user to add additional
 floors, rooms, and access points as well as turn access points on and off. Your
 program should also report errors using exceptions if a room, floor, or access 
point is chosen that does not exist.
 */

#include <iostream>
#include "building.h"

using namespace std;

int main() {
    BuildingFactory bf;
    bf.build();
    BuildingManager bm(bf.deliver());
    bm.manage();

    return 0;
}
