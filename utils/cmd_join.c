/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:42:56 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/04 18:10:40 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*add_path(char *s)
{
	char	*result;

	result = ft_strjoin("/usr/bin/", s);
	free(s);
	return (result);
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
