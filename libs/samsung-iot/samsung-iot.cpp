#include "pxt.h"
#include "IotService.h"

enum class SwitchState{
    off = 0,
    on = 1
};

enum class BulbColour{
    soft_1 = 0,
    level_2 = 1,
    level_3 = 2,
    level_4 = 3,
    level_5 = 4,
    level_6 = 5,
    level_7 = 6,
    level_8 = 7,
    level_9 = 8,
    daylight_10 = 9
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
        bool state = true;
        init();
        ManagedString result = IotService.getBulbState(ManagedString(bulbName));
        uBit.display.scroll(result);
        if(strcmp(result.toCharArray(), "0") == 0)
        {
            state = false;
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
        if((int)colour < (int)BulbColour::soft_1)
        {
            colour = BulbColour::soft_1;
        }
        if((int)colour > (int)BulbColour::daylight_10)
        {
            colour = BulbColour::daylight_10;
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
