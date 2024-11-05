/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:38:34 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/05 13:33:55 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
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
	else
		arg_error();
	return (0);
}
