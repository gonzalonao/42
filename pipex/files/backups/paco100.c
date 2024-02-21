/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:48:13 by glopez-c          #+#    #+#             */
/*   Updated: 2024/01/25 13:03:49 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**cmd2;
	char	**paths;
	char	*temp;
	char	*path;

	cmd2 = ft_split(cmd, ' ');
	if (!envp)
		return (NULL);
	i = -1;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PATH=", 5))
			break ;
	if (!envp[i])
		paths = ft_split("/bin /usr/bin /sbin /usr/sbin", ' ');
	else
		paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd2[0]);
		free(temp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		path = NULL;
		i++;
	}
	if (access(cmd2[0], F_OK) == 0)
		return (cmd2[0]);
	i = 0;
/*	if (!path)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(cmd2[0], 2);
		ft_putendl_fd(": command not found", 2);
		while (cmd2[i])
			free(cmd2[i++]);
		free(cmd2);
		exit(127);
	}*/
	return (NULL);
}

void	ft_execute(char *argv, char **envp)
{
	char	*path;
	char	**argv2;
	char	*argv3[4];

	argv2 = ft_split(argv, ' ');
	path = get_path(argv, envp);
	if (!ft_strnstr(argv, "./", 2) && !path)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv2[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
/*	else if (!path)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv2[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
*/
	path = "/bin/sh";
	argv3[0] = "sh";
	argv3[1] = "-c";
	argv3[2] = argv;
	argv3[3] = NULL;
	execve(path, argv3, envp);
/*	if (execve(path, argv3, envp) == -1)
	{
		ft_putstr_fd("sh: ", 2);
		ft_putstr_fd(argv2[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
*/
}

void	child_process(int *fd, char **argv, char **envp)
{
	int	input;

	input = open(argv[1], O_RDONLY);
	if (input == -1)
	{
		perror("pipex: input");
		exit(EXIT_FAILURE);
	}
	dup2(input, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	ft_execute(argv[2], envp);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	dup2(output, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	ft_execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	int		fd[2];

	if (argc != 5)
		exit(EXIT_FAILURE);
	else
	{
		if (pipe(fd) == -1)
			perror("Error");
		pid1 = fork();
		if (pid1 == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	if (pid1 == 0)
		child_process(fd, argv, envp);
	parent_process(fd, argv, envp);
	}
	return (0);
}
