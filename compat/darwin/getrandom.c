#include "compat.h"

#include <stdlib.h>
#include <sys/types.h>

ssize_t
getrandom(void *buf, size_t buflen, unsigned int flags)
{
	(void)flags;
	arc4random_buf(buf, buflen);
	return ((ssize_t)buflen);
}
