/* ************************************************************************** */
/*	                                                             */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:51:07 by avancoll          #+#    #+#             */
/*   Updated: 2023/01/04 14:58:06 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (1);
  pid = fork();
	if (pid == -1)
    return (2);
	if (!pid)
		child_process(argv, env, fd);
	else
		main_process(argv, env, fd);
	waitpid(pid, 0, 0);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	execve(argv[1], argv + 1, env);
}
