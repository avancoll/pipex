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

int	free_path(char **path, char **cmd, char *argv)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
	return (error_handler(CMD_ERROR, argv));
}

int	exec(char *argv, char **env)
{
	int		i;
	char	**path;
	char	**cmd;

	i = 0;
	while (!ft_strnstr(env[i], "PATH=", 5))
		i++;
	path = ft_split(env[i] + 5, ':');
	cmd = ft_split(argv, ' ');
	i = -1;
	while (path[++i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd[0]);
	}
	i = 0;
	while (path[i] && access(path[i], F_OK))
		i++;
	execve(path[i], cmd, env);
	return (free_path(path, cmd, argv));
}

int	child_process(char **argv, char **env, int *fd)
{
	int	inputfd;

	inputfd = open(argv[1], O_RDONLY);
	if (inputfd == -1)
		return (error_handler(INPUTFILE_ERROR, argv[1]));
	dup2(fd[1], STDOUT_FILENO);
	dup2(inputfd, STDIN_FILENO);
	close(fd[0]);
	exec(argv[2], env);
	return (1);
}

int	main_process(char **argv, char **env, int *fd)
{
	int		outputfd;

	outputfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outputfd == -1)
		return (error_handler(OUTPUTFILE_ERROR, argv[4]));
	dup2(fd[0], STDIN_FILENO);
	dup2(outputfd, STDOUT_FILENO);
	close(fd[1]);
	exec(argv[3], env);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		return (error_handler(ARGC_ERROR, NULL));
	if (pipe(fd) == -1)
		return (error_handler(PIPE_ERROR, NULL));
	pid = fork();
	if (pid == -1)
		return (error_handler(FORK_ERROR, NULL));
	if (!pid)
		child_process(argv, env, fd);
	else
		main_process(argv, env, fd);
	waitpid(pid, NULL, 0);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
