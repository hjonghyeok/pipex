/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:04:50 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/03 17:30:18 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zero_case(void)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * 2);
	if (!dest)
		return (NULL);
	dest[0] = '0';
	dest[1] = 0;
	return (dest);
}

static char	*min_case(long n)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * 12);
	if (!dest)
		return (NULL);
	i = 10;
	while (n > 0)
	{
		dest[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	dest[0] = '-';
	dest[11] = 0;
	return (dest);
}

static char	*set_dest(int n, int len, int m)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		dest[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	if (m)
		dest[0] = '-';
	dest[len] = 0;
	return (dest);
}

char	*ft_itoa(int n)
{
	int		len;
	int		nb;
	int		m;

	len = 0;
	m = 0;
	nb = n;
	if (n == 0)
		return (zero_case());
	if (n == -2147483648)
		return (min_case(2147483648));
	if (n < 0)
	{
		len++;
		nb *= -1;
		n *= -1;
		m = 1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (set_dest(n, len, m));
}
