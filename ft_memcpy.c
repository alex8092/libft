/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:03:37 by amerle            #+#    #+#             */
/*   Updated: 2013/11/19 12:19:43 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void * s1, const void * s2, size_t len)
{
	char		*dest;
	const char	*src;

	dest = (char *)s1;
	src = (const char *)s2;
	if (dest && src && len > 0)
	{
		while (len)
		{
			*dest = *src;
			--len;
			++dest;
			++src;
		}
	}
	return (s1);
}
