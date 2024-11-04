/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:27:26 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/04 17:03:48 by jonghan          ###   ########.fr       */
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

typedef struct s_pipe
{
	char	**cmd1;
	char	**cmd2;
	char	*output_file;
	int		input_file_fd;
	int		output_file_fd;
}			t_pipe;

// pipe
void		get_pipe(t_pipe *pipe, char **av, char **envp);

// utils
char		*add_path(char *s);
char		**cmd1_join(char **av);
char		**cmd2_join(char **av);
void		free_split(char **strs);

#endif