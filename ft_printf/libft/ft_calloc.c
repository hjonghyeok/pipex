/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 06:44:03 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/02 07:26:51 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	mem_size;

	if (nmemb != 0 && size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	mem_size = nmemb * size;
	mem = (void *)malloc(mem_size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, mem_size);
	return (mem);
}
