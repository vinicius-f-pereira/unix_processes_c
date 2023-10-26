#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	/* fd[0] - read */
	/* fd[1] - write */
	int	fd[2];

	/* id to store return of fork */
	int	id;

	/* x variable is to store writed content in fd and use in another process. */
	int	x;

	/* y variable is to store readed content from fd that writen in fork process */ 
	/* 	in parent process */
	int y;

	/* verify if pipe return successful or not. */
	if (pipe(fd) == -1)
	{
		printf("An error ocurred with openning the pipe\n");
		return (1);
	}
	/* now we can fork, we have sure that pipe function return successful. */
	/* 	and it need to be done in this order because, if we fork before, */
	/* 		call pipe function, the child process will inherit call of */
	/* 			pipe function and even if we close a fd in child process */
	/* 			it remains open in the parent process, and it can be a */
	/* 			problem, so we need to do in this order to assure that */
	/* 			when we close a fd, does not remains a parent process */ 
	/* 			with fd open. */
	id = fork();
	if (id == 0)
	{
		/* we inherit fd from parent process, in this case we need to */
		/* 	close fd that will not be used at start of fork. */
		close(fd[0]); // read fd
		printf("input a number: ");
		scanf("%d", &x);
		/* should use fd[1] to write in 'x' */
		write(fd[1], &x, sizeof(int));
		/* after write in 'x' address we don't need to keep open fd[1] */
		/* 	we should close it. */
		close(fd[1]);
	}
	/* now we need to read from first pipe (from the fork) */
	else
	{
		/* this close is the same of fork process */
		close(fd[1]);
		read(fd[0], &y, sizeof(int));

	}
	return (0);
}


int	comp(int a, int b) //a = 1 | b = 2
{
	return (a * (a < b) + b * (b <= a));
	return ()
		//to upper
	c -= 32 * (c * (se for upper (retorna 0), se  for lower(1))
	if (a < b)
		return (a);
	else
		return (b);
}
