#include "pxt.h"
#include "IotService.h"

enum class SwitchState{
    off = 0,
    on = 1
};

enum class BulbTemp{
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

enum class BulbColour{
    white = 0,
    red = 1,
    orange = 2,
    yellow = 3,
    green = 4,
    blue = 5,
    purple = 6,
    violet = 7
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
    int setTempColour(BulbTemp colourTemp)
    {
        return (int)colourTemp;
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

        ManagedString command = "bulbState/";
        command = command + bulbName;

        ManagedString result = IotService.getBulbState(command);
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

        ManagedString result = IotService.setBulbLevel(ManagedString(bulbName), level);
        uBit.display.scroll(result);
    }

    //%
    int getBulbLevel(StringData* bulbName)
    {
        init();
        ManagedString command = "bulbLevel/";
        command = command + bulbName;

        ManagedString result = IotService.getBulbLevel(command);
        int level = stringToNumber(result);
        return level;
    }

    //%
    int getBulbTemp(StringData* bulbName)
    {
        init();
        ManagedString command = "bulbTemp/";
        command = command + bulbName;

        ManagedString result = IotService.getBulbTemp(command);
        int temp = stringToNumber(result);
        return temp;
    }

    //%
    void setBulbTemp(StringData* bulbName, BulbTemp temp)
    {
        init();
        if((int)temp < (int)BulbTemp::soft_1)
        {
            temp = BulbTemp::soft_1;
        }
        if((int)temp > (int)BulbTemp::daylight_10)
        {
            temp = BulbTemp::daylight_10;
        }

        ManagedString result = IotService.setBulbTemp(ManagedString(bulbName), (int)temp);
        uBit.display.scroll(result);
    }

    //%
    void setBulbNextTemp(StringData* bulbName)
    {
        int value = getBulbTemp(bulbName);
        ++value;
        if(value > (int)BulbTemp::daylight_10)
        {
            value = (int)BulbTemp::soft_1;
        }
        setBulbTemp(bulbName,(BulbTemp)value);
    }

    //%
    void setBulbColour(StringData* bulbName, BulbColour colour)
    {
        init();
        if((int)colour < (int)BulbColour::white)
        {
            colour = BulbColour::white;
        }
        if((int)colour > (int)BulbColour::violet)
        {
            colour = BulbColour::violet;
        }

        ManagedString result = IotService.setBulbColour(ManagedString(bulbName), (int)colour);
        uBit.display.scroll(result);
    }

    //%
    int getBulbColour(StringData* bulbName)
    {
        init();
        ManagedString command = "bulbColour/";
        command = command + bulbName;

        ManagedString result = IotService.getBulbColour(command);
        int colour = stringToNumber(result);
        return colour;
    }


    //%
    void setBulbNextColour(StringData* bulbName)
    {
        int value = getBulbColour(bulbName);
        ++value;
        if(value > (int)BulbColour::violet)
        {
            value = (int)BulbColour::white;
        }
        setBulbColour(bulbName,(BulbColour)value);
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
        ManagedString command = "switchState/";
        command = command + switchName;

        ManagedString result = IotService.getSwitchState(command);
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
