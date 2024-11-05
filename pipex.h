/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:27:26 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/04 22:43:51 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/resource.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// pipe
void	child_process(char **av, char **envp, int fd[]);
void	parent_process(char **av, char **envp, int fd[]);

// utils
char	*add_path(char *s, char **envp);
char	**cmd1_join(char **av);
char	**cmd2_join(char **av);
void	free_split(char **strs);
void	arg_error(void);
void	other_error(void);
void	mem_error(void);
char	**get_path(char **envp);

#endif