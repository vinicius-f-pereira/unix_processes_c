/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_wait_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:09:11 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/22 12:17:50 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	int	id;
	int	n;
	int	i;

	id = fork();
	if (id == 0)
		n = 1;
	else 
		n = 52;
	if (id != 0)
	/*
	 * here the main (parent) process wait until the child process end to start over.
	 * and when child process come to this line id is zero, so don't execute this line.
	 * */
		wait();
	for (i = n; i < n + 50; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	if (id != 0)
		printf("\n");
	return (0);
}
