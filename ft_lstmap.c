/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 09:03:16 by amerle            #+#    #+#             */
/*   Updated: 2013/11/23 09:03:17 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*tmp;
	t_list	*new;
	t_list	*current;

	begin = 0;
	current = 0;
	while (lst)
	{
		tmp = f(lst)->next;
		new = ft_lstnew(lst->content, lst->content_size);
		if (new && current)
			current->next = new;
		else if (new)
			begin = new;
		else
			return (0);
		current = new;
		lst = tmp;
	}
	return (begin);
}
