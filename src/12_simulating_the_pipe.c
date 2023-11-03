#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	fd[2];
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		printf("in fucker child\n");
	}
	else
	{
		wait(NULL);
		printf("in fucker child\n");
	}
	return (0);
}