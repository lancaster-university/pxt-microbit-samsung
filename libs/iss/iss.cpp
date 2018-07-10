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
        ManagedString result = IssService.getSolarlocation("solarlocation");
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
        int result = IssService.getDaynum("daynum");
        return result;
    }
};
