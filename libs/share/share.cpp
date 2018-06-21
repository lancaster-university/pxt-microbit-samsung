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
        ManagedString reply = ShareService.getFetchData(command.leakData());
        return reply.leakData();
    }

    //%
    StringData* fetchSchoolData(StringData* name)
    {
        init();

        ManagedString command = "fetchData/";
        command = command + name;
        command = command + "/local";
        ManagedString reply = ShareService.getFetchData(command.leakData());
        return reply.leakData();
    }

    //%
    int setShareLevel(ShareLevel level)
    {
        return (int)level;
    }

    
};