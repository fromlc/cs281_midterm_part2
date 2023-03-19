//------------------------------------------------------------------------------
// home.cpp : CS 281 Midterm Quiz Part 2
// 
// Instructions:
//      1) Add the class and app code for ONE of the devices listed in the
//          Midterm Quiz.
// 
//      2) Make sure you add all needed member variables and functions.
// 
//      3) Make sure all the code you add is in the correct file.
// 
//      4) Issue the appropriate device control command(s). Be sure to display
//          output that indicates what command is executing and the result.
// 
//      5) Display the status of all devices after each command executes.
// 
//      6) Don't forget to use proper coding style.
// 
//------------------------------------------------------------------------------
#include "SmartHome.h"

#include <iostream>
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
bool initHome(SmartHome&);
inline void displayDeviceResponse(bool);
bool lightsOn(SmartHome&);
bool unlockDoor(SmartHome&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    SmartHome h;
    initHome(h);

    lightsOn(h);
    unlockDoor(h);

    cout << "Welcome home smart person!\n";
}

//------------------------------------------------------------------------------
// display command outcome
//------------------------------------------------------------------------------
inline void displayDeviceResponse(bool ok) {

    if (ok) {
        cout << "OK\n";
    }
    else {
        cout << "Not OK!\n";
    }
}

//------------------------------------------------------------------------------
// - connect all devices
// - display status of all devices
//------------------------------------------------------------------------------
bool initHome(SmartHome& h) {

    cout << "\nYour SmartHouse senses your approach!\n";
    cout << "Connecting all smart devices...\n";
    bool homeOK = h.connectAll();

    cout << "All smart devices are ";
    displayDeviceResponse(homeOK);

    cout << '\n';
    h.displayStatus();

    return homeOK;
}

//------------------------------------------------------------------------------
// turn living room lamp on
//------------------------------------------------------------------------------
bool lightsOn(SmartHome& h) {

    cout << "Lights on!\n";

    bool lightsOK = h.lrLamp.switchOn();
    displayDeviceResponse(lightsOK);

    cout << '\n';
    h.displayStatus();

    return lightsOK;
}

//------------------------------------------------------------------------------
// unlock the front door
//------------------------------------------------------------------------------
bool unlockDoor(SmartHome& h) {
    
    cout << "Unlock door!\n";

    bool doorOK = h.fd.unlock();
    displayDeviceResponse(doorOK);

    cout << '\n';
    h.displayStatus();

    return doorOK;
}