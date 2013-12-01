/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 08:24:04 by amerle            #+#    #+#             */
/*   Updated: 2013/11/23 08:24:06 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*item;

	item = (t_list*)malloc(sizeof(t_list));
	if (item)
	{
		item->content = (void *)content;
		item->content_size = (content) ? content_size : 0;
		item->next = 0;
	}
	return (item);
}
