/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:36:52 by amerle            #+#    #+#             */
/*   Updated: 2013/11/23 15:36:54 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_dlistdel(t_dlist **item, t_bool next_replace)
{
	t_dlist	*prev;
	t_dlist	*next;

	if (item && *item)
	{
		prev = (*item)->prev;
		next = (*item)->next;
		if (prev)
			prev->next = next;
		if (next)
			next->prev = prev;
		free(*item);
		*item = ((next_replace) ? next : prev);
		return (true);
	}
	return (false);
}
