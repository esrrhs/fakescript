#include "fuck.h"

void fuck::seterror(fkerrorinfo * ei, efkerror err, const char *fmt, ...)
{
    if (ei)
    {
        ei->errorno = err;
    	va_list ap;
    	va_start(ap, fmt);
        vsnprintf(ei->errorstr, sizeof(ei->errorstr) - 1, fmt, ap);
    	va_end(ap);
    	ei->errorstr[sizeof(ei->errorstr) - 1] = 0;
    }
}

