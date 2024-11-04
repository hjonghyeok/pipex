/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:08:17 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/07 17:14:57 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	addr_display(unsigned long addr, int *len)
{
	char	*hex;
	char	buffer[16];
	int		i;

	i = 15;
	hex = "0123456789abcdef";
	while (addr != 0)
	{
		buffer[i--] = hex[addr % 16];
		addr /= 16;
	}
	write(1, "0x", 2);
	*len += 2;
	i++;
	while (i < 16)
	{
		ft_putchar_fd(buffer[i++], 1);
		*len += 1;
	}
}

void	print_addr(void *addr, int *len)
{
	unsigned char	*a;

	if (addr == NULL)
	{
		write(1, "(nil)", 5);
		*len += 5;
		return ;
	}
	a = addr;
	addr_display((unsigned long)a, len);
}
