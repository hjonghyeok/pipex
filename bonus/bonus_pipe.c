/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:10:23 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/06 23:33:39 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	bonus_child_process(char *av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		other_error();
	pid = fork();
	if (pid == -1)
		other_error();
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			fd_error(av);
		execve_call(av, envp);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			fd_error(av);
		waitpid(pid, NULL, 0);
	}
}

void	bonus_pipe(int ac, char **av, char **envp)
{
	int	i;
	int	output_file_fd;
	int	input_file_fd;

	if (ft_memcmp("here_doc", av[1], 9) == 0)
	{
		if (ac != 6)
			arg_error();
		output_file_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		i = 3;
		here_doc_pipe(av);
	}
	else
	{
		output_file_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		input_file_fd = open(av[1], O_RDONLY, 0777);
		i = 2;
		dup2(input_file_fd, STDIN_FILENO);
	}
	while (i < ac - 2)
		bonus_child_process(av[i++], envp);
	dup2(output_file_fd, STDOUT_FILENO);
	execve_call(av[ac - 2], envp);
}
