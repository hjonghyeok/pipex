/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:15:31 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/06 12:25:07 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	arg_error(void)
{
	ft_printf("Error: Invalid number of arguments\n");
	exit(1);
}

void	fd_error(char *s)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(s, 2);
	exit(1);
}

void	other_error(void)
{
	perror("pipex");
	exit(1);
}

void	mem_error(void)
{
	ft_printf("Error: Memory allocation failed\n");
	exit(1);
}

void	cmd_error(char **strs)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(strs[0], 2);
	free_split(strs);
	exit(1);
}
