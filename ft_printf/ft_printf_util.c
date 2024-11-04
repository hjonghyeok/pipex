/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:19:01 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/07 22:34:10 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_putstr(const char *s, int *len)
{
	char	*str;

	if (s == NULL)
		str = "(null)";
	else
		str = (char *)s;
	while (*str)
	{
		ft_putchar_fd(*str++, 1);
		*len += 1;
	}
}

void	print_putnbr(int n, int *len)
{
	long	nb;

	nb = n;
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		*len += 1;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		*len += 1;
		nb *= -1;
	}
	if (nb >= 10)
	{
		print_putnbr(nb / 10, len);
		print_putnbr(nb % 10, len);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
		*len += 1;
	}
}

void	print_unsigned(unsigned int nb, int *len)
{
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		*len += 1;
		return ;
	}
	if (nb >= 10)
	{
		print_unsigned(nb / 10, len);
		print_unsigned(nb % 10, len);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
		*len += 1;
	}
}

void	hex_is_zero(int *len)
{
	ft_putchar_fd('0', 1);
	*len += 1;
}

void	print_hex(unsigned int n, char x, int *len)
{
	char	*hex;
	char	buffer[16];
	int		i;

	if (n == 0)
	{
		hex_is_zero(len);
		return ;
	}
	i = 15;
	if (x == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	while (n != 0)
	{
		buffer[i--] = hex[n % 16];
		n /= 16;
	}
	i++;
	while (i < 16)
	{
		ft_putchar_fd(buffer[i++], 1);
		*len += 1;
	}
}
