#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>
#define STDOUT 1

int main(int argc, char **argv)
{
	char msg[] = "Hello World!\n";
	int nr = SYS_write;
	syscall(nr, STDOUT, msg, sizeof(msg));
	return 0;
}
