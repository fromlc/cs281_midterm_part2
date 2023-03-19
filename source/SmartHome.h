//------------------------------------------------------------------------------
// SmartHome : class declaration and definition
//------------------------------------------------------------------------------
#ifndef SMARTHOME_H
#define SMARTHOME_H

// device classes
#include "Lamp.h"
#include "Door.h"

#include <iostream>
using std::cout;

//------------------------------------------------------------------------------
// SmartHome
//------------------------------------------------------------------------------
class SmartHome {
public:
    Lamp lrLamp;
    Door fd;

    // constructor
    SmartHome() { }

    // connect all composed devices to wireless network
    bool connectAll() {
        return (lrLamp.connect() && fd.connect());
    }

    // disconnect all composed devices from wireless network
    void disconnectAll() {
        lrLamp.disconnect();
        fd.disconnect();
    }

    // show status for all devices
    void displayStatus() {
        // living room lamp
        lrLamp.displayStatus();
        cout << '\n';

        // front door
        fd.displayStatus();
        cout << '\n';

        // additional device status diplays go here

        cout << '\n';
    }
};
#endif  // SMARTHOME_H