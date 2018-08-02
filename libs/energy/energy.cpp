#include "pxt.h"
#include "EnergyService.h"

enum class EnergyType{
    electricity = 0, 
    gas = 1, 
    solar = 2,
};

enum class HourType{
    _1_hour_ago = 1, 
    _2_hours_ago = 2, 
    _3_hours_ago = 3,
    _4_hours_ago = 4,
    _5_hours_ago = 5, 
    _6_hours_ago = 6,
    _7_hours_ago = 7,
    _8_hours_ago = 8, 
    _9_hours_ago = 9,
    _10_hours_ago = 10,
    _11_hours_ago = 11, 
    _12_hours_ago = 12,
    _13_hours_ago = 13,
};

enum class DayType{
    yesterday = 1, 
    _2_days_ago = 2, 
    _3_days_ago = 3,
    _4_days_ago = 4,
    _5_days_ago = 5,
    _6_days_ago = 6,
    _7_days_ago = 7,
    _8_days_ago = 8,
};

enum class WeekType{
    last_week = 1, 
    _2_weeks_ago = 2, 
    _3_weeks_ago = 3,
    _4_weeks_ago = 4,
    _5_weeks_ago = 5,
};

enum class MonthType{
    last_month = 1, 
    _2_months_ago = 2, 
    _3_months_ago = 3,
    _4_months_ago = 4,
    _5_months_ago = 5, 
    _6_months_ago = 6,
    _7_months_ago = 7,
    _8_months_ago = 8, 
    _9_months_ago = 9,
    _10_months_ago = 10,
    _11_months_ago = 11, 
    _12_months_ago = 12,
    _13_months_ago = 13,
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


    // Commands at Raspberry Pi
    //
    //  Query Energy Electric for MY School and Other School 655BD
    //          energy/energyLevel/0/local
    //          energy/energyLevel/0/655BD
    //                            |  |
    //                            |  }--> School Id or local
    //                            }--> Energy Type: Gas = 0, Electric = 1, Solar = 2
    //
    //  Historical
    //
    //  Query Energy Historical Electric by DAY for My School and Other School 655BD
    //          energy/historical/energyLevel/0/day/3/local
    //          energy/historical/energyLevel/0/day/3/655BD
    //                 |                      |  |  | |
    //                 |                      |  |  | }--> School Id or local
    //                 |                      |  |  }-->Amount of days back: 1 = yesterday, 2 = the day before
    //                 |                      |  }--> Type of historical time:  hour, day, week, month
    //                 |                      }--> Energy Type: Gas = 0, Electric = 1, Solar = 2
    //                 }--> historical, So we know this is looking for historical data


    //%
    StringData* queryEnergyText(EnergyType t, ManagedString schoolid, ManagedString historicData)
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
        if(historicData.length() > 0)
        {
            command = "historical/energyLevel/";
        }
        char eType[5];
        memset(eType,0,sizeof(eType));
        sprintf(eType,"%d",(int)t);

        command = command + eType;
        command = command + "/";

        if(historicData.length() > 0)
        {
            command = command + historicData;
            command = command + "/";
        }

        command = command + schoolid;

        ManagedString reply = EnergyService.getEnergyLevel(command);
        return reply.leakData();
    }

    //%
    int queryEnergy(EnergyType t, StringData* schoolid)
    {
        ManagedString result = queryEnergyText(t,schoolid,"");
        int value = stringToNumber(result);
        return value;
    }


    //%
    int queryEnergyHour(EnergyType t, HourType h, StringData* schoolid)
    {
        char buffer[6];
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"hour/%d", (int)h);
        ManagedString result = queryEnergyText(t, ManagedString(schoolid), ManagedString(buffer));
        int value = stringToNumber(result);
        return value;
    }

    //%
    int queryEnergyDay(EnergyType t, DayType d, StringData* schoolid)
    {
        char buffer[6];
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"day/%d", (int)d);
        ManagedString result = queryEnergyText(t, ManagedString(schoolid), ManagedString(buffer));
        int value = stringToNumber(result);
        return value;
    }

    //%
    int queryEnergyWeek(EnergyType t, WeekType w, StringData* schoolid)
    {
        char buffer[6];
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"week/%d", (int)w);
        ManagedString result = queryEnergyText(t, ManagedString(schoolid), ManagedString(buffer));
        int value = stringToNumber(result);
        return value;
    }

    //%
    int querySchoolMonth(EnergyType t, MonthType m, StringData* schoolid)
    {
        char buffer[6];
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"month/%d", (int)m);
        ManagedString result = queryEnergyText(t, ManagedString(schoolid), ManagedString(buffer));
        int value = stringToNumber(result);
        return value;
    }

    //%
    int querySchoolEnergy(EnergyType t)
    {
        ManagedString result = queryEnergyText(t, ManagedString("local"), "");
        int value = stringToNumber(result);
        return value;
    }



    //%
    int querySchoolEnergyDay(EnergyType t, DayType d)
    {
        char buffer[6];
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"day/%d", (int)d);
        ManagedString result = queryEnergyText(t, ManagedString("local"), ManagedString(buffer));
        int value = stringToNumber(result);
        return value;
    }

    //%
    int querySchoolEnergyHour(EnergyType t, HourType h)
    {
        char buffer[6];
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"hour/%d", (int)h);
        ManagedString result = queryEnergyText(t, ManagedString("local"), ManagedString(buffer));
        int value = stringToNumber(result);
        return value;
    }

    //%
    int querySchoolEnergyWeek(EnergyType t, WeekType w)
    {
        char buffer[6];
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"week/%d", (int)w);
        ManagedString result = queryEnergyText(t, ManagedString("local"), ManagedString(buffer));
        int value = stringToNumber(result);
        return value;
    }

    //%
    int querySchoolEnergyMonth(EnergyType t, MonthType m)
    {
        char buffer[6];
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"month/%d", (int)m);
        ManagedString result = queryEnergyText(t, ManagedString("local"), ManagedString(buffer));
        int value = stringToNumber(result);
        return value;
    }

};
