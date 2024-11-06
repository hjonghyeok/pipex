/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:45:26 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/06 22:23:43 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc_child(char **av, int fd[])
{
	int		ret;
	char	*buf;
	char	*limiter;

	buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	if (!buf)
		mem_error();
	limiter = ft_strjoin(av[2], "\n");
	if (!limiter)
		mem_error();
	close(fd[0]);
	while (1)
	{
		ret = read_std(buf);
		if (ret < 0 || ft_strncmp(buf, limiter, ft_strlen(limiter)) == 0)
		{
			free(buf);
			exit(0);
		}
		write(fd[1], buf, ft_strlen(buf));
	}
	free(buf);
}

void	here_doc_pipe(char **av)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		other_error();
	pid = fork();
	if (pid == -1)
		other_error();
	if (pid == 0)
		here_doc_child(av, fd);
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			fd_error(av[5]);
		wait(NULL);
	}
}
