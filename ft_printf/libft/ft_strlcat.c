/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:53:21 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/04 13:24:39 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	d_len;
	unsigned int	s_len;

	if (!dst || size == 0)
		return (ft_strlen(src));
	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	while (i < size - d_len - 1 && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = 0;
	return (s_len + d_len);
}
