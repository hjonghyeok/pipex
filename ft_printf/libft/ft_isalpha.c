/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:31:53 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/03 17:29:40 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((unsigned char)c >= 'a' && (unsigned char)c <= 'z') || \
		((unsigned char)c >= 'A' && (unsigned char)c <= 'Z'))
		return (1);
	return (0);
}
