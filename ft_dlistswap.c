/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 01:29:21 by amerle            #+#    #+#             */
/*   Updated: 2013/11/27 01:29:23 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct	s_swap
{
	t_dlist	*next;
	t_dlist *prev;
	t_dlist *next2;
	t_dlist *prev2;
};


void		ft_dlistswap(t_dlist **item, t_dlist **item2)
{
	struct s_swap	swapp;
	t_dlist	*next;

	if (item && *item && item2 && *item2)
	{
		swapp.next = (*item)->next;
		swapp.prev = (*item)->prev;
		swapp.next2 = (*item2)->next;
		swapp.prev2 = (*item2)->prev;

		if ((*item2) == (*item)->next)
		{
			if (swapp.prev)
				swapp.prev->next = (*item2);
			if (swapp.next2)
				swapp.next2->prev = (*item);
			(*item2)->next = (*item);
			(*item2)->prev = swapp.prev;
			(*item)->prev = (*item2);
			(*item)->next = swapp.next2;
			next = (*item);
			(*item) = (*item2);
			(*item2) = next;
		}
	}
}
