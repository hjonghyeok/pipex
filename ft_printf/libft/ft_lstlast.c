/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:02:09 by jonghan           #+#    #+#             */
/*   Updated: 2024/10/04 16:32:06 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*n_lst;

	if (!lst)
		return (NULL);
	n_lst = lst;
	while (n_lst->next)
		n_lst = n_lst->next;
	return (n_lst);
}
