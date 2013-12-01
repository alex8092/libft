/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 01:24:30 by amerle            #+#    #+#             */
/*   Updated: 2013/11/27 01:24:33 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_dlistsort_do(t_dlist **begin,\
	t_bool (*swap)(t_dlist *it, t_dlist *it2), size_t len)
{
	t_dlist	*current;
	t_dlist	*tmp;

	current = *begin;
	while (current->next && len)
	{
		if (swap(current, current->next))
		{
			tmp = current->next;
			ft_dlistswap(&current, &tmp);
		}
		--len;
		current = current->next;
	}
	while (current->prev)
		current = current->prev;
	*begin = current;
}

void	ft_dlistsort(t_dlist **lst, t_bool (*swap)(t_dlist *it, t_dlist *it2))
{
	size_t	len;
	t_dlist	*current;

	if (lst && *lst)
	{
		len = ft_dlistlen(*lst);
		current = *lst;
		while (len > 1)
		{
			ft_dlistsort_do(&current, swap, len);
			--len;
		}
		*lst = current;
	}
}
