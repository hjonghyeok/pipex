/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:23:59 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/07 17:24:25 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h" 

void	printf_putstr(const char *s, int *len);
void	print_unsigned(unsigned int nb, int *len);
void	print_hex(unsigned int n, char x, int *len);
void	print_addr(void *addr, int *len);
int		ft_printf(const char *s, ...);
void	op_case(va_list *args, int *len, char op);
void	print_putnbr(int n, int *len);
void	addr_display(unsigned long addr, int *len);

#endif
