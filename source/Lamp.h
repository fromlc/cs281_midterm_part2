//------------------------------------------------------------------------------
// Lamp.h : derived class declaration and definition file
// 
// Base class: IoTDevice
//      pure virtual function: string getStatus()
//------------------------------------------------------------------------------
#ifndef LAMP_H
#define LAMP_H

#include "IoTDevice.h"  // base class

#include <algorithm>    // min()
using std::min;

#include <iostream>
using std::cout;

//------------------------------------------------------------------------------
// Lamp
//------------------------------------------------------------------------------
constexpr int LB_DEFAULT = 60;
constexpr int LB_MAX = 100;

class Lamp : public IoTDevice {
private:
    int watts;

public:
    // constructor
    Lamp() : IoTDevice() { watts = LB_DEFAULT; }

    // ambient light level
    bool setWatts(int _watts) {
        watts = min(_watts, LB_MAX);
    }

    // device-specific status display
    void displayStatus() {

        cout << "Ambient light level is ";

        if (on) {
            cout << watts << " watts";
        }
        else {
            cout << "off";
        }
    }
};
#endif  // LAMP_H
