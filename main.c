/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:38:34 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/04 17:56:18 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	char	*path;

	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	path = *envp + 5;
	return (ft_split(path, ':'));
}

// int	init_pipes_cmd(t_pipe *pipes, char **av)
// {
// 	pipes->cmd1 = cmd1_join(av);
// 	if (pipes->cmd1 == NULL)
// 		return (1);
// 	pipes->cmd2 = ft_split(av[3], ' ');
// 	if (pipes->cmd2 == NULL)
// 	{
// 		free_split(pipes->cmd1);
// 		return (1);
// 	}
// 	pipes.cmd1[0] = add_path(pipes.cmd1[0]);
// 	pipes.cmd2[0] = add_path(pipes.cmd2[0]);
// }

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipes;
	char	**path;

	if (ac == 5)
	{
		pipes.cmd1 = cmd1_join(av);
		pipes.cmd2 = ft_split(av[3], ' ');
		pipes.cmd1[0] = add_path(pipes.cmd1[0]);
		pipes.cmd2[0] = add_path(pipes.cmd2[0]);
		pipes.input_file_fd = open(av[1], O_RDONLY);
		pipes.output_file_fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		path = get_path(envp);
		get_pipe(&pipes, av, envp);
		free_split(pipes.cmd1);
		free_split(pipes.cmd2);
		free_split(path);
	}
	else
		ft_printf("ar error\n");
	return (0);
}
