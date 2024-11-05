/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:42:56 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/05 22:54:31 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*add_path(char *s, char **envp)
{
	char	*result;
	char	*tmp;
	char	**path;
	int		i;

	path = get_path(envp);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		result = ft_strjoin(tmp, s);
		free(tmp);
		if (!access(result, F_OK))
		{
			free_split(path);
			return (result);
		}
		if (path[i + 1] != NULL)
			free(result);
		i++;
	}
	free_split(path);
	return (result);
}

char	**get_path(char **envp)
{
	char	*path;

	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	path = *envp + 5;
	return (ft_split(path, ':'));
}

char	char_in_arr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == 34)
			return (s[i]);
		i++;
	}
	return (0);
}
