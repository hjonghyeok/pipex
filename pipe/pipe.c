/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:21:28 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/06 21:23:08 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execve_call(char *av, char **envp)
{
	char	**cmd;
	char	*path;
	char	c;

	c = char_in_arr(av);
	if (c)
		cmd = pipex_split(av, c);
	else
		cmd = ft_split(av, ' ');
	if (!cmd)
		mem_error();
	path = add_path(cmd[0], envp);
	if (!path)
	{
		free_split(cmd);
		mem_error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		cmd_error(cmd);
	}
	free_split(cmd);
	free(path);
}

void	child_process(char **av, char **envp, int fd[])
{
	int	input_file_fd;

	close(fd[0]);
	if (access(av[1], R_OK) == -1)
		fd_error(av[1]);
	input_file_fd = open(av[1], O_RDONLY, 0777);
	if (input_file_fd == -1)
		fd_error(av[1]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		fd_error(av[1]);
	if (dup2(input_file_fd, STDIN_FILENO) == -1)
		fd_error(av[1]);
	execve_call(av[2], envp);
	exit(0);
}

void	parent_process(char **av, char **envp, int fd[])
{
	int	output_file_fd;

	close(fd[1]);
	output_file_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file_fd == -1)
		fd_error(av[4]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		fd_error(av[4]);
	if (dup2(output_file_fd, STDOUT_FILENO) == -1)
		fd_error(av[4]);
	execve_call(av[3], envp);
	exit(0);
}
