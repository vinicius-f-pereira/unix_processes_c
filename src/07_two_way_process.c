#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	p1[2];
	if (pipe(p1) == -1)	{ return (1); }
	int	pid = fork();
	if (pid == -1) { return (2); }
	if (pid == 0) {
		/* child process */
		int	x;
		if (read(p1[0], &x, sizeof(x)) == -1) { return (3);}
		printf("Received value %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1) { return (4); }
		printf("Wrote value %d\n", x);
	}
	else {
		/* parent process */
		srand(time(NULL));
		int	y = rand() % 10;
		if (write(p1[1], &y, sizeof(y)) == -1) { return (5); }
		printf("Wrote value %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1) { return (6); }
		printf("Result is %d\n", y);
	}
	close(p1[0]);
	close(p1[1]);
	return (0);
}

/* this code is to simulating a pipe command but only with one call to pipe */
/* function (pipe()) tha's not recommended. You need to do it with 2 calls */
/* of pipe function. One for child process to parent, and other from parent */
/* to child. */

/* To work right, this function need to write in a fd, wait child process read */
/* and then write again after operation (x *= 4) and then back to parent and read */
/* to print the result. */

/* I'll do the right code in next file. */
