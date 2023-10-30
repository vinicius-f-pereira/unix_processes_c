#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	/* fork return a int assigned to return value of fork (0 success and -1 fail) */
	/* fork clone the calling process, creating an exact copy */
	/* the id in the child process is aways be 0 */
	/* id 0 means that we are on the child process and not in the main process */
	/* in the main process will be another number. */
	int	id = fork();
	/* printf("Hello world from id: %d\n", id); */
	if (id == 0)
		printf("Hello from child process\n");
	else 
		printf("Hello from the main process\n");
	return (0);
}
