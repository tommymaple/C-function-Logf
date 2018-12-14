/** LogF Ver1.2 DiliverUnicorn Copy LEFT Nothing RIGHTS**/
/*
Features:
    1.logs events.
    2.UTC time with in.
    3.Auto end line detect.
*/
#include<stdio.h>

#include "logF.h"

int main()
{
    char string[]="logs events here,\n";

    logF(string);
    logF("or you can just type in string.");

    return 0;
}
