#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	/* Firts, lets do our first program with fork() */
	/* What happens if we call fork() function before printf? */
	/* if you tested it, 'Hello World' is printed twice! */
	/* Fork return an int, and this int is very important. \
	 * Is the id of fork process */
	/* All before fork() line will be executed once, and after will \
	 * be executed twice, once per process. */
	/* Will have 2 id's one of main process and other for the child process */ 
	/* fork() function return -1 for Errors, 0 for the new process \
	 * (child (this id is always be '0' (new process))) */
	/* Every single process in any O.S. (Operating System) have one ID */
	/* With this if condition, we'll get two different results */
	/* What happens if we call fork() a second time? */
	/* It print four times Hello World */
	fork();
	fork();
	/* check id number to choose if will fork again or not */
	//if (0 != id)
	//	fork();
	printf("Hello World\n");
	/* if (id == 0) */
	/* 	printf("Hello from child process\n"); */
	/* else */
	/* 	printf("Hello from main process\n"); */
	return (0);
}
