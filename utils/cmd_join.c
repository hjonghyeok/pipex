/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:42:56 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/04 22:32:24 by jonghan          ###   ########.fr       */
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

char	**cmd1_join(char **av)
{
	char	**result;
	char	**split;
	int		i;

	i = 0;
	split = ft_split(av[2], ' ');
	if (!split)
		return (NULL);
	while (split[i])
		i++;
	result = (char **)ft_calloc(sizeof(char *), (i + 2));
	if (!result)
		return (NULL);
	result[i] = NULL;
	i = 0;
	while (split[i])
		result[i++] = ft_strdup(split[i]);
	result[i] = ft_strdup(av[1]);
	free_split(split);
	return (result);
}
