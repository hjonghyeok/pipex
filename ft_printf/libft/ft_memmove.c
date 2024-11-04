/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:45:22 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/01 14:55:31 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;

	d = dest;
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		while (n-- > 0)
			*d++ = *(unsigned char *)src++;
	}
	else
	{
		while (n-- > 0)
			*(d + n) = *(unsigned char *)(src + n);
	}
	return (dest);
}
