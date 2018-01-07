#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <dlfcn.h>


void (*hello_message)(const char*);

bool init_library()
{
	void *hdl = dlopen("./libHello.so", RTLD_LAZY);
	if(hdl == NULL)
		return false;
	
	hello_message = (void (*)(char *))dlsym(hdl, "hello_message");
	
	if(hello_message == NULL)
		return false;

	return true;
}

int main()
{
	if( init_library() )
		hello_message("Artyom");
	else
		printf("Library was not loaded"); 
	return 0;
}
