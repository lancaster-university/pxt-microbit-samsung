#include "pxt.h"
//#include "IssService.h"

/**
* share
* use
*/

//IssService IssService(uBit.radio);

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
        int result = IssService.getId("id");
        return result;
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
        ManagedString result = IssService.getSolarLocation("solarlocation");
        return result.leakData();
    }

    //%
    int getVelocity()
    {
        init();
        int result = IssService.getVelocity("velocity");
        return result;
    }

    //%
    int getAltitude()
    {
        init();
        int result = IssService.getAltitude("altitude");
        return result;
    }

    //%
    StringData* getVisability()
    {
        init();
        ManagedString result = IssService.getVisability("visability");
        return result.leakData();
    }

    //%
    int getDayNum()
    {
        init();
        int result = IssService.getDaynumber("daynumber");
        return result;
    }
};
