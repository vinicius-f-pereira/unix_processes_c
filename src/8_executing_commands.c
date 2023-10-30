#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	/* fork to put execution of a command in a child process */
	int pid = fork();
	/* checking if fork() was been created (it means, returned 0 or not) */
	if (pid == -1) {
		return (1);
	}
	/* checking if we are on child / parent process */
	if (pid == 0) {
		/* this function execute a command, but kill entire process */
		/* after execution, so to avoid that our programm stop after */
		/* executing this command, we need to put it in a child process. */
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
		/* this should not be printed */
		printf("Success\n");
		printf("Some post processing goes here\n");
	} else {
		wait(NULL);
		printf("Success\n");
	}
	return (0);
}
