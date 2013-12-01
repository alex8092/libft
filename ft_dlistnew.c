/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:38:29 by amerle            #+#    #+#             */
/*   Updated: 2013/11/23 11:38:30 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlistnew(void const *content, size_t content_size)
{
	t_dlist	*item;

	item = (t_dlist*)malloc(sizeof(t_dlist));
	if (item)
	{
		item->content = (void *)content;
		item->content_size = content_size;
		item->next = 0;
		item->prev = 0;
	}
	return (item);
}
