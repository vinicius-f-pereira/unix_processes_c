#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int pid = fork();
	if (pid == -1) {
		return (1);
	}
	if (pid == 0) {
		/* Child process */
		/* exec funcitons return a int to say if exec can run command or not */
		int	err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		/* now we need to check if it was success or not and return a message if error. */
		if (err == -1) {
			printf("Could not find program to execut\n");
			return (0);
		}
	} else {
		int	wstatus;
		/* Parent process */
		wait(&wstatus);
		if (WIFEXITED(wstatus)) {
			int	statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0) {
				printf("Success\n");
			}
			else {
				printf("Failure with status code %d\n", statusCode);
			}
		}
	}
	return (0);
}
