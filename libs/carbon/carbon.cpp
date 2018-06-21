#include "pxt.h"
#include "CarbonService.h"

enum class GenerationMixType{
    gas = 0,
    coal = 1, 
    solar = 2, 
    wind = 3, 
    nuclear = 4, 
    hydro = 5, 
    biomas = 6, 
    imports = 7, 
    other = 8,
};

enum class CarbonIndex{
    very_low = 0,
    low = 1, 
    moderate = 2, 
    high = 3, 
    very_high = 4, 
};

static const char* const generationTypes[] = {"gas","coal","solar","wind","nuclear","hydro","biomas","imports","other"}; 
static const char* const carbonIndexValueTypes[] = {"very_low","low","moderate","high","very_high"}; 

/**
* share
* use
*/

CarbonService CarbonService(uBit.radio);

//% color=#000000 weight=100 icon="\uf216" block="carbon"
namespace carbon {

    int init() {
        return enableRadio();
    }

    //%
    StringData* queryCarbonValue()
    {
        init();

        ManagedString command = "value";
        ManagedString reply = CarbonService.getCarbonValue(command.leakData());
        return reply.leakData();
    }

    //Convert the carbon index from string to int
    //%
    int queryCarbonIndex()
    {
        init();

        ManagedString command = "index";
        ManagedString reply = CarbonService.getCarbonIndex(command.leakData());

        int replyValue = -1;

        for(int loop=0; loop < 5; ++ loop)
        {
            if(strcmp(carbonIndexValueTypes[loop], reply.toCharArray()) == 0)
            {
                replyValue = loop;
                break;
            }
        }

        reply.leakData();
        return replyValue;
    }

    //%
    StringData* queryCarbonIndexText()
    {
        init();

        ManagedString command = "index";
        ManagedString reply = CarbonService.getCarbonIndex(command.leakData());
        return reply.leakData();
    }

    //%
    StringData* queryCarbonGenerationMix(int mix)
    {
        init();

        if(mix < 0)
        {
            mix = 0;
        }

        if(mix > (int)GenerationMixType::other)
        {
            mix = (int)GenerationMixType::other;
        }
               

        ManagedString command = "genmix/";
        command = command + generationTypes[mix];
        
        ManagedString reply = CarbonService.getCarbonGenerationMix(command.leakData());
        return reply.leakData();
    }

    //%
    int setGenerationMixType(GenerationMixType GenerationMixType)
    {
        return (int)GenerationMixType;
    }

    //%
    int setCarbonIndexValueType(CarbonIndex index)
    {
        return (int)index;
    }

    
};
