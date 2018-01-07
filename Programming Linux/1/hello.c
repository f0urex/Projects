#include "hello.h"
#include <stdio.h>

void hello_message(const char *name)
{
	printf("Hello %s! You use dynamic library\n", name);
}
