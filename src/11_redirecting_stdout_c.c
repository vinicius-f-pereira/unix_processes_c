#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int	main(int ac, char **av, char *envp[])
{
	char	*arr[] = {
		"ping",
		"google.com",
		NULL
	};
	char	*env[]{
		"Test=environment variable",
		NULL
	};
	execlpe(
		"ping",
		"ping",
		"google.com",
		NULL,
		env
	);

	int	err = errno;
	printf("Ping Finished executing \n");
	return (0);
}
