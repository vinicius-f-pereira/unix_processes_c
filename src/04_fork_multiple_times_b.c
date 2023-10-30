#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	id = fork();
	/* to check if you're in the child process to not fork again */ 
	/* inside of a child process. Just verify if id is != 0 */
	/* in this case we'll have only 3 hellow world. */
	/* in the child process created by fork, id will be zero, and in */
	/* the main process will be another number */
	if (id != 0)
	{
		fork();
	}
	printf("Hello world\n");
	return (0);
}
