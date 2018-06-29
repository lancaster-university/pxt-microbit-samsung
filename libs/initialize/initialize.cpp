#include "pxt.h"
#include "InitService.h"

enum class InitType{
   school = 0,
    raspberry = 1,
};

/**
* share
* use
*/

InitService InitService(uBit.radio);

//% color=#51008B weight=100 icon="\uf019" block="Initialise"
namespace initialize {

    int init() {
        return enableRadio();
    }

    //%
    void initUnit(StringData* initData, int t)
    {
        init();

        ManagedString result;
        if(t == (int)InitType::school)
        {
            result = InitService.setSchoolId(ManagedString(initData));
        }
        else
        {
            result = InitService.setPiId(ManagedString(initData));
        }
        uBit.display.scroll(result);
    }

    //%
    int setInitType(InitType initType)
    {
        return (int)initType;
    }
};
