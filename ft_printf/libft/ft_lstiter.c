/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:02:56 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/04 16:04:24 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*n_lst;

	n_lst = lst;
	while (n_lst)
	{
		(*f)(n_lst->content);
		n_lst = n_lst->next;
	}
}
