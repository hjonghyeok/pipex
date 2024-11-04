/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:58:08 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/04 16:02:22 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*n_lst;

	n = 0;
	n_lst = lst;
	while (n_lst)
	{
		n_lst = n_lst->next;
		n++;
	}
	return (n);
}
