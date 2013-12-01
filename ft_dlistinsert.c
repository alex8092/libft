/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistinsert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 12:24:31 by amerle            #+#    #+#             */
/*   Updated: 2013/11/24 05:31:09 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_dlistinsert_2(t_dlist **lst, t_dlist *item)
{
	if (*lst)
	{
		item->next = *lst;
		(*lst)->prev = item;
	}
	*lst = item;
}

t_bool			ft_dlistinsert(t_dlist **lst, t_dlist *item, size_t index)
{
	t_dlist	*current;

	if (!lst)
	return (false);
	if (!(*lst) && !index)
		return (ft_dlistadd(lst, item, true));
	current = 0;
	while (index--)
	{
		if (current == 0)
			current = *lst;
		else if (current->next)
			current = current->next;
		else
			return (false);
	}
	if (current)
	{
		ft_dlistadd(&current->next, item, true);
		current->next->prev = current;
	}
	else
		ft_dlistinsert_2(lst, item);
	return (true);
}
