#include "pxt.h"
#include "EnergyService.h"

enum class EnergyType{
    electricity = 0, 
    gas = 1, 
    solar = 2,
};

/**
* share
* use
*/

EnergyService EnergyService(uBit.radio);

//% color=#006f00 weight=100 icon="\uf275" block="energy"
namespace energy {

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

    
    StringData* queryEnergyText(EnergyType t, StringData* schoolid)
    {
        init();

        //protect against invalid input
        if(t < EnergyType::electricity)
        {
            t = EnergyType::electricity;
        }
        if(t > EnergyType::solar)
        {
            t = EnergyType::solar;
        }


        ManagedString command = "energyLevel/";
        char eType[5];
        memset(eType,0,sizeof(eType));
        sprintf(eType,"%d",(int)t);

        command = command + eType;
        command = command + "/";
        command = command + schoolid;

        ManagedString reply = EnergyService.getEnergyLevel(command);
        return reply.leakData();
    }

    //%
    int queryEnergy(EnergyType t, StringData* schoolid)
    {
        ManagedString result = queryEnergyText(t,schoolid);
        int value = stringToNumber(result);
        return value;
    }

    
    StringData* querySchoolEnergyText(EnergyType t)
    {
        init();

        //protect against invalid input
        if(t < EnergyType::electricity)
        {
            t = EnergyType::electricity;
        }
        if(t > EnergyType::solar)
        {
            t = EnergyType::solar;
        }

        ManagedString command = "energyLevel/";
        char eType[5];
        memset(eType,0,sizeof(eType));
        sprintf(eType,"%d",(int)t);

        command = command + eType;
        command = command + "/";
        command = command + "local";

        ManagedString reply = EnergyService.getEnergyLevel(command);
        return reply.leakData();
    }

    //%
    int querySchoolEnergy(EnergyType t)
    {
        ManagedString result = querySchoolEnergyText(t);
        int value = stringToNumber(result);
        return value;
    }

};
