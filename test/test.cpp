#include <stdio.h>
#include <stdlib.h>

#include "fuckscript.h"

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        return 0;
    }
    
    fuck * fk = newfuck();
    fkerrorinfo ei;
    binary * bin = fkparse(fk, &ei, argv[1]);
    if (ei.fkerror() != efk_ok)
    {
        printf("parse error %d, %s\n", ei.fkerror(), ei.fkerrorstr());
        return 0;
    }

    int ret = fkrun<int>(bin, &ei, "myfunc1", 1, 2);
    if (ei.fkerror() != efk_ok)
    {
        printf("call fail errorno %d, %s\n", ei.fkerror(), ei.fkerrorstr());
        return 0;
    }
    
    printf("call ret %d\n", ret);
    
    return 0;
}

