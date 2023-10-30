#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	execlp("ping", "ping", "-c", "3", "google.com", NULL);
	return (0);
}
