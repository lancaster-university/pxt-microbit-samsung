#include "pxt.h"
#include "IssService.h"

/**
* share
* use
*/

IssService IssService(uBit.radio);

//% color=#99ccff weight=100 icon="\uf197" block="ISS"
namespace iss {

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
    StringData* getName()
    {
        init();
        ManagedString result = IssService.getName("name");
        return result.leakData();
    }

    //%
    int getId()
    {
        init();
        ManagedString result = IssService.getId("id");
        int value = stringToNumber(result);
        return value;
    }


    //%
    StringData* getLocation()
    {
        init();
        ManagedString result = IssService.getLocation("location");
        return result.leakData();
    }

    //%
    StringData* getSolarLocation()
    {
        init();
        ManagedString result = IssService.getSolarlocation("solarlocation");
        return result.leakData();
    }

    //%
    int getVelocity()
    {
        init();
        ManagedString result = IssService.getVelocity("velocity");
        int value = stringToNumber(result);
        return value;
    }

    //%
    int getAltitude()
    {
        init();
        ManagedString result = IssService.getAltitude("altitude");
        int value = stringToNumber(result);
        return value;
    }

    //%
    StringData* getVisibility()
    {
        init();
        ManagedString result = IssService.getVisibility("visibility");
        return result.leakData();
    }

    //%
    int getDayNum()
    {
        init();
        ManagedString result = IssService.getDaynum("daynum");
        int value = stringToNumber(result);
        return value;
    }
};
