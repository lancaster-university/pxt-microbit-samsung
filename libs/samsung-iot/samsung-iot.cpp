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
    bool getBulbState(StringData* bulbName)
    {
        init();
        ManagedString s = IotService.getBulbState(ManagedString(bulbName));

        return true;
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
    int getBulbLevel(StringData* bulbName)
    {
        init();
        ManagedString s = IotService.getBulbLevel(ManagedString(bulbName));

        return 40;
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
    int getBulbColor(StringData* bulbName)
    {
        init();
        ManagedString s = IotService.getBulbColour(ManagedString(bulbName));

        return 3;
    }

    //%
    void turnSwitch(StringData* switchName, SwitchState switchState)
    {
        init();
        IotService.setSwitchState(ManagedString(switchName),(int)switchState);
    }

    //%
    bool getSwitchState(StringData* switchName)
    {
        init();
        ManagedString s = IotService.getSwitchState(ManagedString(switchName));

        return true;
    }


    //%
    bool getSensorState(StringData* sensorName)
    {
        init();
        ManagedString command = "sensorState/";
        command = command + sensorName;
        ManagedString s = IotService.getSensorState(command.leakData());

        bool result = false;
        if(strcmp("active", s.toCharArray()) == 0)
        {
            result = true;
        }
        s.leakData();
        return result;
    }
};
