/** LogF Ver1.1 DiliverUnicorn Copy LEFT Nothing RIGHTS**/
/*
Features:
    1.logs events.
    2.UTC time with in.
    3.Auto end line detect.
*/
/// INPUT Example : logf("LOG HI");
/// Result in Events.txt file >> 20180717 UTC  4:41:23 LOG HI

#include <time.h>

void logf( char logstr[])
{
    char event[256+22]={0};//22for time string use
    FILE * logf_pFile;
    logf_pFile = fopen ("Log","a+");

    time_t rawtime;
    struct tm * timeptr;

    if (logf_pFile!=NULL)
    {
        time ( &rawtime );
        timeptr = gmtime ( &rawtime );
        //write time in string
        sprintf (event,"%d%02d%02d UTC %2d:%02d:%02d ", 1900 + timeptr->tm_year, timeptr->tm_mon, timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min, timeptr->tm_sec);//utc
        //combine time and events
        strcat(event,logstr);
        //detect endline ,if no endline add on it.
        if( NULL==strchr(event,'\n') )
            strcat(event,"\n");

        fputs (event,logf_pFile);

        fclose (logf_pFile);
    }

}

