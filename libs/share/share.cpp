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

    //%
    void shareData(StringData* data, StringData* name, int level)
    {
        init();
        //This forces the input to be either a 1 or 0. Anything else becomes a 1 (school)
        if(level == (int)ShareLevel::all)
        {
            level = 0;
        }
        else
        {
            level = 1;
        }
        ShareService.setShareData(data,name,level);
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
        command.leakData();
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
        command.leakData();
        return reply.leakData();
    }

    //%
    int textToNumber(StringData* text)
    {
        init();
        ManagedString managedText = (ManagedString)text;
        int value = (int)atof(managedText.toCharArray());
        managedText.leakData();
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

    //%
    int setShareLevel(ShareLevel level)
    {
        return (int)level;
    }

    
};