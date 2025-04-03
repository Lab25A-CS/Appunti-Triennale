#include <unistd.h>
#include <stdio.h>

#define STDOUT 1

int main()
{
	char msg[] = "Hello World!\n";
	write(STDOUT, msg, sizeof(msg));

	return 0;
	
}
