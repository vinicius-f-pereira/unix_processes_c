#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	int	id;
	int	id2;

	id = fork();
	id2 = fork();
}
