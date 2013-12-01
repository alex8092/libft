/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistrm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:52:13 by amerle            #+#    #+#             */
/*   Updated: 2013/11/24 05:31:26 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_dlistrm(t_dlist **lst, size_t index)
{
	t_dlist	*current;

	if (lst && *lst)
	{
		current = *lst;
		while (index)
		{
			if (current->next)
				current = current->next;
			else
				return (false);
			--index;
		}
		if (current == *lst)
			ft_dlistdel(lst, true);
		else
		{
			ft_dlistdel(&current, true);
		}
		return (true);
	}
	return (false);
}
