/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:15:49 by amerle            #+#    #+#             */
/*   Updated: 2013/11/23 04:16:22 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	c;

	if (n > 0)
	{
		c = *((const char *)s2);
		ft_memmove((char *)(s1) + 1, (const char *)(s2) + 1, n - 1);
		*((char *)s1) = c;
	}
	return (s1);
}
