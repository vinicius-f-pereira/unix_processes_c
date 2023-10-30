#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	/* what will happen if we use fork two times? How much times */
	/* hello world will be printed? A: 4 */
	/* this first fork create one child process and main process still executing */
	/* next line together. */
	/* main process execute fork again (second one) and child process created by */
	/* first fork execute it too, so we have 4 execution lines. */
	fork();
	fork();
	printf("Hello world\n");
	return (0);
}
