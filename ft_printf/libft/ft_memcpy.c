/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:19 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/03 17:32:55 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;

	if (!dest && !src)
		return (NULL);
	d = dest;
	if (dest == src)
		return (dest);
	while (n-- > 0)
		*d++ = *(unsigned char *)src++;
	return (dest);
}
