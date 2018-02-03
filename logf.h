/* C function Logf Ver1.0 by DiliverUnicorn
    copy left

Features:
    1.logs events.
    2.UTC time with in.
    3.Auto end line detect.
*/
#include<stdio.h>
#include<time.h>
#include<string.h>
void logf( char logstr[])
{
    char event[256+22]={0};//22 是時間所需的位置
    FILE * logf_pFile;
    logf_pFile = fopen ("Log","a+");

    time_t rawtime;
    struct tm * timeptr;

    if (logf_pFile!=NULL)
    {
        time ( &rawtime );
        timeptr = gmtime ( &rawtime );

        sprintf (event,"%d%02d%02d UTC %2d:%02d:%02d ", 1900 + timeptr->tm_year, timeptr->tm_mon, timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min, timeptr->tm_sec);//utc
        //printf ("%d %d UTC %2d:%02d:%02d ",1900 + timeptr->tm_year , (timeptr->tm_hour)%24, timeptr->tm_min, timeptr->tm_sec);//utc
        strcat(event,logstr);

        if( NULL==strchr(event,'\n') )
            strcat(event,"\n");

        fputs (event,logf_pFile);

        fclose (logf_pFile);
    }

}
