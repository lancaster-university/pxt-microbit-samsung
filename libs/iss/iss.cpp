#include "pxt.h"
#include "IssService.h"
#include <time.h>

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

    time_t timeFromDate( int year, int month, int day ) 
{ 
     time_t rawtime; 
     struct tm * my_time; 
  
     // Create a filled in time structure 
     time( &rawtime ); 
     my_time = localtime( &rawtime ); 
      
     // Reassign our date 
     my_time->tm_year     = year - 1900; // Different sources say 1900 and 1970? 
     my_time->tm_mon        = month - 1;    // tm uses uses january + months [0..11]  
     my_time->tm_mday     = day; 
  
     // Return it as seconds since epoch 
     return( mktime( my_time ) ); 
 }

    //%
    int getDayNum()
    {
        init();
        time_t launchDate, today; 
    
        launchDate  = (timeFromDate( 1998, 11, 20 )) /86400; 
        today = IssService.getDaynum("daynum");
        int days = difftime( today, launchDate); 
        return days;
    }
};
