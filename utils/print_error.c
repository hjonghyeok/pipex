/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:15:31 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/05 13:10:49 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	arg_error(void)
{
	ft_printf("Error: Invalid number of arguments\n");
	exit(1);
}

void	other_error(void)
{
	perror("Error");
	exit(1);
}

void	mem_error(void)
{
	ft_printf("Error: Memory allocation failed\n");
	exit(1);
}
void	cmd_error(void)
{
	perror("command not found");
	exit(1);
}