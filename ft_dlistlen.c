/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 12:04:23 by amerle            #+#    #+#             */
/*   Updated: 2013/11/23 12:04:24 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlistlen(t_dlist *lst)
{
	size_t	len;

	len = 0;
	if (lst)
	{
		while (lst)
		{
			++len;
			lst = lst->next;
		}
	}
	return (len);
}
