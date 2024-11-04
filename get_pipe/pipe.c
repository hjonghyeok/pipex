/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:41:35 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/04 18:10:57 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parent_pipe(t_pipe *pipes, int fd[], char **envp)
{
	wait(0);
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	dup2(pipes->output_file_fd, 1);
	close(pipes->output_file_fd);
	if (execve(pipes->cmd2[0], pipes->cmd2, envp) == -1)
	{
		ft_printf("%s\n", strerror(errno));
		exit(1);
	}
}

int	child_pipe(t_pipe *pipes, int fd[], char **envp)
{
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	if (execve(pipes->cmd1[0], pipes->cmd1, envp) == -1)
	{
		ft_printf("%s\n", strerror(errno));
		exit(1);
	}
}

void	get_pipe(t_pipe *pipes, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
	{
		ft_printf("%s\n", strerror(errno));
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		ft_printf("%s\n", strerror(errno));
		return ;
	}
	if (pid > 0)
	{
		close(fd[1]);
		parent_pipe(pipes, fd, envp);
		close(fd[0]);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		child_pipe(pipes, fd, envp);
		close(fd[1]);
	}
}
