#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	/* to execute a program like 'ping', 'ls' and others we need to use a family */
	/* 	of functions called 'exec..xyz' */

	/* execl -> take a list of arguments */
	/* execle -> take a list of arguments and allows you to specify the environment */
				/* for the new process image, while execl does not. */
				/* 	execle takes and additional argument (envp[]) */

	/* execlp and execlpe is similar to execl, the difference is that they use the */
	/* 	PATH environment variable to find the program to execute. This means that */
	/* 	you only need to provide the name of the program, and the system will */
	/* 	look for it in directories listed in the PATH variable. */

	/* 	execlpe -> also allows you to specify the environment for the new */
	/* 	process image. And takes additional argument (envp[]) too. */

	/* execv and execve -> These functions take a vector of arguments. */
	/* 	Is useful when the number of parameters that are to be sent to the exec'ed */
	/* 	process are variable. The difference between the two is that 'EXECVE' */
	/* 	allows you to specify the environment for the new process image. (envp[]). */

	/* execvp and exevpe are similar to execv and 've'. They use the PATH like */
	/* 	execlp and execlpe. */


	return (0);
}

