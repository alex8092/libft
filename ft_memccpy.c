/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:20:09 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 08:50:52 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	src = (const unsigned char *)s2;
	dest = (unsigned char *)s1;
	if (s1 && s2 && n > 0)
	{
		while (*src != (unsigned char)c && n)
		{
			*dest = *src;
			++dest;
			++src;
			--n;
		}
		if (*src == (unsigned char)c && n != 0)
		{
			*dest = *src;
			++dest;
		}
		return ((n == 0) ? 0 : dest);
	}
	return (0);
}
