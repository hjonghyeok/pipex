/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:21:28 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/05 01:14:11 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execve_call(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (!cmd)
		other_error();
	path = add_path(cmd[0], envp);
	if (!path)
	{
		free_split(cmd);
		other_error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_split(cmd);
		free(path);
		other_error();
	}
}

void	child_process(char **av, char **envp, int fd[])
{
	int	input_file_fd;

	input_file_fd = open(av[1], O_RDONLY, 0777);
	if (input_file_fd == -1)
		other_error();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		other_error();
	if (dup2(input_file_fd, STDIN_FILENO) == -1)
		other_error();
	close(fd[0]);
	execve_call(av[2], envp);
}

void	parent_process(char **av, char **envp, int fd[])
{
	int	output_file_fd;

	output_file_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output_file_fd == -1)
		other_error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		other_error();
	if (dup2(output_file_fd, STDOUT_FILENO) == -1)
		other_error();
	close(fd[1]);
	execve_call(av[3], envp);
}