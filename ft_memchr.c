/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:33:20 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 09:45:58 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp;
	size_t		i;

	i = 0;
	tmp = (unsigned char *)s;
	if (tmp && i < n)
	{
		while (i < n && tmp[i] != (unsigned char)c)
			++i;
		if (i < n && tmp[i] == (unsigned char)c)
			return ((void *)tmp + i);
	}
	return (0);
}
