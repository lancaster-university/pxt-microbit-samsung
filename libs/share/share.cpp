#include "pxt.h"
#include "ShareService.h"

enum class ShareLevel{
    all = 0,
    school = 1, 
};


/**
* share
* use
*/

ShareService ShareService(uBit.radio);

//% color=#999999 weight=100 icon="\uf086" block="share"
namespace share {

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
    void shareData(StringData* data, StringData* name, ShareLevel level)
    {
        init();
        //This forces the input to be either a 1 or 0. Anything else becomes a 1 (school)
        if(level == ShareLevel::all)
        {
            level = ShareLevel::all;
        }
        else
        {
            level = ShareLevel::school;
        }
        ManagedString result = ShareService.setShareData(ManagedString(data),ManagedString(name),(int)level);
        uBit.display.scroll(result);
    }

    //%
    void shareHistoricalData(StringData* data, StringData* name, StringData* space, StringData* unit)
    {
        init();

        //This forces the input to be either a 1 or 0. Anything else becomes a 1 (school)
        
        ManagedString result = ShareService.setHistoricalData(ManagedString(data),ManagedString(name),ManagedString(space),ManagedString(unit));
        uBit.display.scroll(result);
    }

    //%
    StringData* fetchData(StringData* name, StringData* targetSchool)
    {
        init();

        ManagedString command = "fetchData/";
        command = command + name;
        command = command + "/";
        command = command + targetSchool;
        ManagedString reply = ShareService.getFetchData(command);
        return reply.leakData();
    }

    //%
    StringData* fetchSchoolData(StringData* name)
    {
        init();

        ManagedString command = "fetchData/";
        command = command + name;
        command = command + "/local";
        ManagedString reply = ShareService.getFetchData(command);
        return reply.leakData();
    }

    //%
    int textToNumber(StringData* text)
    {
        init();
        
        int value = stringToNumber((ManagedString)text);
        return value;
    }


    //%
    StringData* numberToText(int value)
    {
        init();
        char buffer[15];
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"%d",value);
        return ManagedString(buffer).leakData();
    }

};