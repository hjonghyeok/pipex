/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:06:30 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/06 23:52:23 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	basic_pipe(char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		other_error();
	pid = fork();
	if (pid == -1)
		other_error();
	if (pid == 0)
		child_process(av, envp, fd);
	else
		parent_process(av, envp, fd);
	waitpid(pid, NULL, 0);
}
