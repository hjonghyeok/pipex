/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:05:49 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/04 16:36:44 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*f_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}

static void	f_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}

static void	f_lstclear(t_list **lst, void (*del)(void *))
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

static void	f_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n_lst;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	n_lst = *lst;
	while (n_lst->next)
		n_lst = n_lst->next;
	n_lst->next = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		new_list = f_lstnew(f(lst->content));
		if (!new_list)
		{
			f_lstclear(&tmp, del);
			return (NULL);
		}
		f_lstadd_back(&tmp, new_list);
		lst = lst->next;
	}
	return (tmp);
}
