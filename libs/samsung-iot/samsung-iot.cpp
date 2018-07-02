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

    int stringToNumber(ManagedString input)
    {
        ManagedString resultString = "";
        int result = 0;

        int l = input.length();
        for(int x=0; x < l; ++x)
        {
            if(input.charAt(x) != '\n' && input.charAt(x) != '\r')
            {
                if(isdigit(input.charAt(x)) || input.charAt(x) == '.')
                {
                    resultString = resultString + input.charAt(x);
                }
                else
                {
                    result = -1;
                    break;
                }
            }
        }
        if(result > -1)
        {
            float f = atof(resultString.toCharArray());
            result = round(f);
        }
        return result;
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
        uBit.display.scroll(result);
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
        uBit.display.scroll(result);
    }

    //%
    int getBulbLevel(StringData* bulbName)
    {
        init();
        ManagedString result = IotService.getBulbLevel(ManagedString(bulbName));
        int level = stringToNumber(result);
        return level;
    }

    //%
    void setBulbColour(StringData* bulbName, BulbColour colour)
    {
        init();
        if((int)colour < (int)BulbColour::red)
        {
            colour = BulbColour::red;
        }
        if((int)colour > (int)BulbColour::white)
        {
            colour = BulbColour::white;
        }
        ManagedString result = IotService.setBulbColour(ManagedString(bulbName), (int)colour);
        uBit.display.scroll(result);
    }

    //%
    int getBulbColor(StringData* bulbName)
    {
        init();
        ManagedString result = IotService.getBulbColour(ManagedString(bulbName));
        int colour = stringToNumber(result);
        return colour;
    }

    //%
    void turnSwitch(StringData* switchName, SwitchState switchState)
    {
        init();
        ManagedString result = IotService.setSwitchState(ManagedString(switchName),(int)switchState);
        uBit.display.scroll(result);
    }

    //%
    bool getSwitchState(StringData* switchName)
    {
        bool state = false;

        init();
        ManagedString result = IotService.getSwitchState(ManagedString(switchName));
        if(strcmp(result.toCharArray(), "on") == 0)
        {
            state = true;
        }
        return state;
    }


    //%
    bool getSensorState(StringData* sensorName)
    {
        init();
        ManagedString command = "sensorState/";
        command = command + sensorName;
        ManagedString s = IotService.getSensorState(command);

        bool result = false;
        if(strcmp("active", s.toCharArray()) == 0)
        {
            result = true;
        }

        return result;
    }
};
