#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	int	arr[] = { 1, 2, 3, 4, 1, 2, 7, 9, 15 };
	int	arr_size = sizeof(arr) / sizeof(int);
	int	start, end, sum, id, id2, count, sumFromChild, totalSum;
	int	fd[2];
	
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		start = 0;
		end = arr_size / 3;
	}
	else
	{
		start = arr_size / 2;
		end = arr_size;
	}
	if (id != 0)
	{
		id2 = fork();
		if ()
	}
	sum = 0;
	for (count = start; count < end; count++)
	{
		sum += arr[count];
	}
	printf("Calculated partial sum: %d\n", sum);

	/* now start to manipulate values with pipe */
	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			return (3);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
			return (4);
		close(fd[0]);
		totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
		wait(NULL);
	}
	return (0);
}
