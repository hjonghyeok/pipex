/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:12:54 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/07 02:13:16 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		basic_pipe(av, envp);
	else if (ac > 5)
		bonus_pipe(ac, av, envp);
	else
		arg_error();
	exit(0);
}
