#include "pxt.h"
#include "IotService.h"

enum class SwitchState{
    off = 0,
    on = 1
};

enum class BulbColour{
    red = 0,
    pink,
    lightblue,
    blue,
    green,
    lightgreen,
    orange,
    purple,
    white
};

/**
* share
* use
*/

IotService IotService(uBit.radio);

//% color=#000080 weight=100 icon="\uf0eb" block="Samsung IoT"
namespace samsungiot {

    int init() {
        return enableRadio();
    }

    //%
    bool setSwitchState(SwitchState status)
    {
        if(status == SwitchState::off)
        {
            return false;
        }
        else{
            return true;
        }
        return false;
    }

    //%
    int setLightColour(BulbColour lightcolour)
    {
        return (int)lightcolour;
    }

    //%
    void setBulbState(StringData* bulbName, SwitchState switchState)
    {
        init();
        IotService.setBulbState(ManagedString(bulbName), (int)switchState);
    }

    //%
    void setBulbLevel(StringData* bulbName, int level)
    {
        init();

        if(level < 0)
        {
            level = 0;
        }
        if(level > 99)
        {
            level = 99;
        }
        IotService.setBulbVal(ManagedString(bulbName), level);
    }

    //%
    void setBulbColour(StringData* bulbName, int colour)
    {
        init();
        if(colour < 0)
        {
            colour = 0;
        }
        if(colour > (int)BulbColour::white)
        {
            colour = (int)BulbColour::white;
        }
        IotService.setBulbColour(ManagedString(bulbName), colour);
    }

    //%
    void turnSwitch(StringData* switchName, SwitchState switchState)
    {
        init();
        IotService.setSwitchState(ManagedString(switchName),(int)switchState);
    }


    //%
    StringData* getSensorState(StringData* sensorName)
    {
        init();
        ManagedString command = "sensorState/";
        command = command + sensorName;
        ManagedString s = IotService.getSensorState(command.leakData());
        return s.leakData();
    }
};
