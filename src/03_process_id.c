#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	int	id;

	id = fork();
	/**
	 * getpid return PROCESS ID from from the calling process
	 * now when use printf, each process will execute printf, and return
	 * the PID from calling process that should be different.
	 */
	/**
	 * getppid is the same behavior of getpid, but if have a parent id, this
	 * function returns it.
	 * OK? but who's parent id from the main process? Basically in any OS
	 * each process have a parent process. Think, who start the main process?
	 * some process of your system, so main process are the first process of your
	 * programm, but not of your system.
	 */
	/**
	 * in this if statment, child process will wait 1 second and parent process will terminate.
	 * so the parent id will change... Will no more be of the main process that was terminated.
	 * the child process have get parent process that hold the child now.
	 */
	if (id == 0)
		sleep(1);
	/**
	 * So, every programm that you use fork, you need to say for main process
	 * wait for child process ends first.
	 * */
	int res = wait(NULL);
	if (res == -1) // NULL will return '-1' if errors, or if have nothing to wait for,
				   // that is the same that the child process ended.
		printf("No children to wait for\n");
	else
		printf("%d finished execution\n"); // just show up PID that finished the execution
	printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
	return (0);
}
