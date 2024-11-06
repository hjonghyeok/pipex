/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:27:26 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/06 22:04:25 by jonghan          ###   ########.fr       */
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

# define BUF_SIZE 10000

// basic
void	basic_pipe(char **av, char **envp);

// process
void	child_process(char **av, char **envp, int fd[]);
void	parent_process(char **av, char **envp, int fd[]);
void	execve_call(char *av, char **envp);

// utils
char	*add_path(char *s, char **envp);
void	free_split(char **strs);
char	**get_path(char **envp);
char	**pipex_split(char const *s, char c);
char	char_in_arr(char *s);
char	*get_next_line(int fd);

// error
void	arg_error(void);
void	other_error(void);
void	mem_error(void);
void	cmd_error(char **strs);
void	fd_error(char *s);

// bonus
void	bonus_pipe(int ac, char **av, char **envp);
int		read_std(char *buf);
void	here_doc_pipe(char **av);

#endif
