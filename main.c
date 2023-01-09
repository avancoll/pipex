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

void	child_process(char **argv, char **env, int *fd)
{
	int	inputfd;

	inputfd = open(argv[1], O_RDONLY, 0777);
	if (inputfd == -1)
	{
		write(2, "grh", 3);
		return ;
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(inputfd, STDIN_FILENO);
	close(fd[0]);
	execve(argv[2], argv, env);
}

int	main_process(char **argv, char **env, int *fd)
{
	int		outputfd;

	outputfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outputfd == -1)
		return (1);
	dup2(fd[0], STDIN_FILENO);
	dup2(outputfd, STDOUT_FILENO);
	close(fd[1]);
	execve(argv[3], argv, env);
	return (127);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		return (1);
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (2);
	if (!pid)
		child_process(argv, env, fd);
	else
		main_process(argv, env, fd);
	waitpid(pid, NULL, 0);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
