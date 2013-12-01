/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:41:44 by amerle            #+#    #+#             */
/*   Updated: 2013/11/23 11:41:48 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_dlistadd_bottom(t_dlist **lst, t_dlist *current, t_dlist *item)
{
	while (current && current->next)
		current = current->next;
	if (current)
	{
		current->next = item;
		item->prev = current;
		item->next = 0;
	}
	else
	{
		*lst = item;
		item->next = 0;
		item->prev = 0;
	}
}

t_bool		ft_dlistadd(t_dlist **lst, t_dlist *item, t_bool top)
{
	t_dlist	*current;

	if (lst && item)
	{
		current = *lst;
		if (top == true)
		{
			item->next = current;
			item->prev = 0;
			if (current)
				current->prev = item;
			*lst = item;
		}
		else
			ft_dlistadd_bottom(lst, current, item);
		return (true);
	}
	return (false);
}
