//------------------------------------------------------------------------------
// IoTDevice.h : abstract class declaration and definition file
// 
// Base class: IoTDevice
//      pure virtual function: string getStatus()
//------------------------------------------------------------------------------
#ifndef IOTDEVICE_H
#define IOTDEVICE_H

#include <iostream>
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// IoTDevice : base class
//------------------------------------------------------------------------------
class IoTDevice {
protected:
    string ssid;        // wireless network name
    string password;    // wireless network password

    bool connected;     // true if connected to wireless network
    bool on;            // true if powered on
    bool statusOK;

public:
    // constructor
    IoTDevice() : ssid("CS281"), connected(false), on(false), statusOK(true) { }

    // set network name and password
    void setNetworkCreds(const string& _ssid, const string& _password) {
        ssid = _ssid;
        password = _password;
    }

    // return network name
    string getNetworkName() const { return ssid; }

    // dummy connect for now
    bool connect(string _password = "") {
        if (!_password.empty()) {
            password = _password;
        }

        connected = true;
        return true;
    }

    // dummy disconnect for now
    void disconnect() { connected = false; }

    bool isConnected() const { return connected; }
    bool isOn() { return on; }

    // device commands
    bool switchOn() { return _iSwitch(true); }
    bool switchOff() { return _iSwitch(false); }

    // device status
    bool isStatusOK() { return statusOK; }
    bool resetStatus() { statusOK = true; }

    // each device must provide its own status display!
    virtual void displayStatus() = 0;

private:

    // internal set device on/off function
    bool _iSwitch(bool _on) {
        if (connected) {
            on = _on;
            return true;
        }
        return false;
    }


};
#endif  // IOTDEVICE_H

