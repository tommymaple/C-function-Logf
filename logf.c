/* C function Logf Ver1.0 by DiliverUnicorn
    copyleft

Features:
    1.logs events.
    2.UTC time with in.
    3.Auto end line detect.
*/
#include<stdio.h>

#include "logf.h"

int main()
{
    char string[]="logs events here,\n";

    logf(string);
    logf("or you can just type in string.");

    return 0;
}
