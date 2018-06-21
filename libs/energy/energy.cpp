#include "pxt.h"
#include "EnergyService.h"

enum class EnergyType{
    electric = 0, 
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

    //%
    StringData* queryEnergy(int t, StringData* schoolid)
    {
        init();

        //protect against invalid input
        if(t < 0)
        {
            t = 0;
        }
        if(t > (int)EnergyType::solar)
        {
            t = (int)EnergyType::solar;
        }


        ManagedString command = "energyLevel/";
        char eType[5];
        memset(eType,0,sizeof(eType));
        sprintf(eType,"%d",t);

        command = command + eType;
        command = command + "/";
        command = command + schoolid;

        ManagedString reply = EnergyService.getEnergyLevel(command.leakData());
        return reply.leakData();
    }

    //%
    StringData* querySchoolEnergy(int t)
    {
        init();

        //protect against invalid input
        if(t < 0)
        {
            t = 0;
        }
        if(t > (int)EnergyType::solar)
        {
            t = (int)EnergyType::solar;
        }

        ManagedString command = "energyLevel/";
        char eType[5];
        memset(eType,0,sizeof(eType));
        sprintf(eType,"%d",t);

        command = command + eType;
        command = command + "/";
        command = command + "local";

        ManagedString reply = EnergyService.getEnergyLevel(command.leakData());
        return reply.leakData();
    }

    //%
    int setEnergyType(EnergyType energyType)
    {
        return (int)energyType;
    }
};
