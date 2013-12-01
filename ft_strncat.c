/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:07:25 by amerle            #+#    #+#             */
/*   Updated: 2013/11/21 18:17:41 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*save;

	save = dest;
	if (dest && src && n > 0)
	{
		while (*dest)
			++dest;
		while (*src && n)
		{
			*dest = *src;
			++dest;
			++src;
			--n;
		}
		*dest = 0;
	}
	return (save);
}
