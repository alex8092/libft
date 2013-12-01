/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:07:25 by amerle            #+#    #+#             */
/*   Updated: 2013/11/23 06:20:55 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	char		*dest2;
	const char	*src2;
	size_t		dest_len;
	size_t		n;

	dest2 = dest;
	src2 = src;
	n = dest_size + 1;
	while (*dest2 && (n -= 1))
		++dest2;
	dest_len = dest2 - dest;
	if ((dest_size -= dest_len) == 0)
		return (dest_len + ft_strlen(src));
	while (*src2)
	{
		if (dest_size != 1)
		{
			*dest2 = *src2;
			dest2++;
			--dest_size;
		}
		++src2;
	}
	*dest2 = 0;
	return (dest_len + (src2 - src));
}
