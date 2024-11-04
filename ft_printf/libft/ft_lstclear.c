/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:54:43 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/04 16:34:58 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	f_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*loop_lst;

	loop_lst = *lst;
	if (*lst)
	{
		while (loop_lst)
		{
			n_lst = loop_lst->next;
			f_lstdelone(loop_lst, del);
			loop_lst = n_lst;
		}
		*lst = NULL;
	}
}
