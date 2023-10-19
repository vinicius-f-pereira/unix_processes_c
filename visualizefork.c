#include <stdio.h>
#include <unistd.h>
#include <time.h>

int	main(int argc, char* argv[])
{
	int	id = fork();
	int	n;
	if (id == 0)
		n = 1;
	else 
		n = 52;
	if (id != 0)
		wait();

	int i;
		for (i = n; i < n + 50; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	if (id != 0)
		printf("\n");
	return (0);
}
