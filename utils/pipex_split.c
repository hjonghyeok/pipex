/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:12:41 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/05 15:25:56 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	getsize(char const *s, int *size)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			*size += 1;
			while (s[i] && s[i] == ' ')
				i++;
		}
		else if (s[i++] == '\'')
		{
			*size += 1;
			while (s[++i] && s[i - 1] != '\'')
				;
		}
	}
}

static char	*pipex_splitdup(char const *s, char c)
{
	char	*dest;
	int		len;

	len = 0;
	if (s[len++] == '\'')
	{
		s++;
		while (s[++len] && s[len] != '\'')
			;
	}
	else
		while (s[len] && s[len] != c)
			len++;
	dest = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!dest)
		return (NULL);
	while (--len >= 0)
	{
		dest[len] = s[len];
	}
	return (dest);
}

static void loop(char const *s, int *i)
{
    if (s[(*i)++] == '\'')
        while (s[++(*i)] && s[*i - 1] != '\'')
            ;
    else
        while (s[*i - 1] && s[*i - 1] != ' ')
            (*i)++;
}

static char	**get_split(char const *s, int size)
{
	int		i;
	int		j;
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < size)
	{
		if (s[i] != ' ' || s[i] == '\'')
		{
			dest[j] = pipex_splitdup(&s[i], ' ');
			if (!dest[j])
				return (mem_free(dest, j));
			j++;
            loop(s, &i);
		}
		while (s[i] && s[i] == ' ')
			i++;
	}
	dest[j] = NULL;
	return (dest);
}

char	**pipex_split(char const *s)
{
	int		size;
	char	**dest;

	size = 0;
	getsize(s, &size);
	if (!size)
		return (NULL);
	return (get_split(s, size));
}