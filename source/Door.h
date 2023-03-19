//------------------------------------------------------------------------------
// Door.h : derived class declaration and definition file
// 
// Base class: IoTDevice
//      pure virtual function: string getStatus()
//------------------------------------------------------------------------------
#ifndef DOOR_H
#define DOOR_H

#include "IoTDevice.h"  // base class

#include <algorithm>    // min()
using std::min;

#include <iostream>
using std::cout;

//------------------------------------------------------------------------------
// Door
//------------------------------------------------------------------------------
class Door : public IoTDevice {
private:
    bool isLocked;        // true if door is unlocked

public:
    // constructor
    Door() : IoTDevice() { isLocked = true; }

    // unlock door command handler
    bool unlock() {
        if (connected) {
            isLocked = false;
            return true;
        }
        return false;
    }

    // lock door command handler
    bool lock() {
        if (connected) {
            isLocked = true;
            return true;
        }
        return false;
    }

    // device-specific status display
    void displayStatus() {

        cout << "Door is ";

        if (isLocked) {
            cout << "locked";
        }
        else {
            cout << "unlocked";
        }
    }
};
#endif  // DOOR_H