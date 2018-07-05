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
        ManagedString result = "ISS"; //IssService.setShareData(ManagedString(data),ManagedString(name),(int)level);
        return result.leakData();
    }

    //%
    int getId()
    {
        init();
        int result = 25544; //IssService.setShareData(ManagedString(data),ManagedString(name),(int)level);
        return result;
    }


    //%
    StringData* getLocation()
    {
        init();
        ManagedString result = "LAT:-6.3547249173764 LON:43.523139793007s"; //IssService.setShareData(ManagedString(data),ManagedString(name),(int)level);
        return result.leakData();
    }

    //%
    StringData* getSolarLocation()
    {
        init();
        ManagedString result = "LAT:22.940300269597 LON:23.264864291413"; //IssService.setShareData(ManagedString(data),ManagedString(name),(int)level);
        return result.leakData();
    }

    //%
    int getVelocity()
    {
        init();
        int result = 27606; //IssService.setShareData(ManagedString(data),ManagedString(name),(int)level);
        return result;
    }

    //%
    int getAltitude()
    {
        init();
        int result = 405; //IssService.setShareData(ManagedString(data),ManagedString(name),(int)level);
        return result;
    }

    //%
    StringData* getVisability()
    {
        init();
        ManagedString result = "daylight"; //IssService.setShareData(ManagedString(data),ManagedString(name),(int)level);
        return result.leakData();
    }

    //%
    int getDayNum()
    {
        init();
        int result = 2458302; //IssService.setShareData(ManagedString(data),ManagedString(name),(int)level);
        return result;
    }
};
