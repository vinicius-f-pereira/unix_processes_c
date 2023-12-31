#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if(pipe(fd) == -1) {
		return (1);
	}
	pid1 = fork();
	if (pid1 < 0) {
		return 2;
	}
	if (pid1 == 0) {
		// child process 1 (ping)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	pid2 = fork();
	if (pid2 < 0) {
		return (3);
	}
	if (pid2 == 0) {
		// Child process 2 (grep)
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	// Need to close fd, because it still open in parent process
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	printf("Done\n");
	return (0);
}