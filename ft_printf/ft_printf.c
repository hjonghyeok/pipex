/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:23:49 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/07 22:26:26 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	op_case(va_list *args, int *len, char op)
{
	if (op == 'd' || op == 'i')
		print_putnbr(va_arg(*args, int), len);
	else if (op == 's')
		printf_putstr(va_arg(*args, char *), len);
	else if (op == 'c')
	{
		ft_putchar_fd(va_arg(*args, int), 1);
		*len += 1;
	}
	else if (op == 'u')
		print_unsigned(va_arg(*args, unsigned int), len);
	else if (op == '%')
	{
		ft_putchar_fd('%', 1);
		*len += 1;
	}
	else if (op == 'x' || op == 'X')
		print_hex(va_arg(*args, unsigned int), op, len);
	else if (op == 'p')
		print_addr(va_arg(*args, void *), len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			op_case(&args, &len, s[i]);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
