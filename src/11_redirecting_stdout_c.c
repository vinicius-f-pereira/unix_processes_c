#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int pid = fork();
	if (pid == -1) {
		return (1);
	}
	if (pid == 0) {
		/* to get output of ping command and send to a file we need first to */
		/* 	create a file with write and read only and create, */ 
		/* 		   and permissions in octal */
		int	file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
		/* verify if success */
		if (file == -1)
			return (2);
		/* now we need to use dup function to duplicate file the opened file */
		/* 	descriptor. And it point to the same file "pingResults" */
		//int	file2 = dup(file);

		/* line above are for dup, but in this case is better use dup2. */
		/* 	The differente is that dup2 duplicate for a specific fd */
		/* 	(second param) like stdout/in/err. */
		/* 	if you use dup2 in this like in this case, the output of ping command */
		/* 		will be store in the pingResults.txt instead of printed in stdout. */
		printf("The fd to pingResults: %d\n", file);
		int	file2 = dup2(file, STDOUT_FILENO);
		printf("The duplicated fd: %d\n", file2);
		/* before end, we need to close fd '3' (file), we'll now just use file2 */
		/* 	so don't need to let file opened. */
		close(file);
		int	err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1) {
			printf("Could not find program to execut\n");
			return (0);
		}
	} else {
		// Parent
		int	wstatus;
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
