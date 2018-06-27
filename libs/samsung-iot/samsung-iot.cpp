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
        ManagedString result = IotService.setBulbState(ManagedString(bulbName), (int)switchState);
        uBit.display.scroll(result.leakData());
    }

    //%
    bool getBulbState(StringData* bulbName)
    {
        bool state = false;
        init();
        ManagedString result = IotService.getBulbState(ManagedString(bulbName));
        if(strcmp(result.toCharArray(), "OK") == 0)
        {
            state = true;
        }
        result.leakData();
        return state;
    }

    //%
    void setBulbLevel(StringData* bulbName, int level)
    {
        init();

        if(level < 0)
        {
            level = 0;
        }
        if(level > 100)
        {
            level = 100;
        }
        ManagedString result = IotService.setBulbVal(ManagedString(bulbName), level);
        uBit.display.scroll(result.leakData());
    }

    //%
    int getBulbLevel(StringData* bulbName)
    {
        init();
        ManagedString s = IotService.getBulbLevel(ManagedString(bulbName));
        int status = atoi(s.toCharArray());
        s.leakData();
        return status;
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
        ManagedString result = IotService.setBulbColour(ManagedString(bulbName), colour);
        uBit.display.scroll(result.leakData());
    }

    //%
    int getBulbColor(StringData* bulbName)
    {
        init();
        ManagedString s = IotService.getBulbColour(ManagedString(bulbName));
        int status = atoi(s.toCharArray());
        s.leakData();
        return status;
    }

    //%
    void turnSwitch(StringData* switchName, SwitchState switchState)
    {
        init();
        ManagedString result = IotService.setSwitchState(ManagedString(switchName),(int)switchState);
        uBit.display.scroll(result.leakData());
    }

    //%
    bool getSwitchState(StringData* switchName)
    {
        bool state = false;

        init();
        ManagedString result = IotService.getSwitchState(ManagedString(switchName));
        if(strcmp(result.toCharArray(), "OK") == 0)
        {
            state = true;
        }
        result.leakData();
        return state;
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
