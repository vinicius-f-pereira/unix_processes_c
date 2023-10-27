#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	p1[2]; // Child to parent
	int	p2[2]; // Parent to child
	if (pipe(p1) == -1)	{ return (1); }
	if (pipe(p2) == -1)	{ return (2); }
	int	pid = fork();
	if (pid == -1) { return (3); }
	if (pid == 0) {
		/* child process */
		/* we don't need of this fds, cuz the child only write to it */
		close(p1[0]); 
		close(p2[1]); 
		int	x;
		if (read(p2[0], &x, sizeof(x)) == -1) { return (4);}
		printf("Received value %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1) { return (5); }
		printf("Wrote value %d\n", x);
		close(p1[1]);
		close(p2[0]);
	}
	else {
		/* parent process */
		close(p1[1]); // the same of child process
		close(p2[0]); // the same of child process
		srand(time(NULL));
		int	y = rand() % 10;
		if (write(p2[1], &y, sizeof(y)) == -1) { return (6); }
		printf("Wrote value %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1) { return (7); }
		printf("Result is %d\n", y);
		close(p1[0]);
		close(p2[1]);
	}
	return (0);
}
