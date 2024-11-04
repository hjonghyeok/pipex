/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 08:11:55 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/02 08:23:08 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end] && ft_strchr(set, s1[end]))
	{
		if (end < 1)
			break ;
		end--;
	}
	if (start > end)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1 + start, end - start + 2);
	return (dest);
}
