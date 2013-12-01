/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:07:25 by amerle            #+#    #+#             */
/*   Updated: 2013/11/22 01:07:38 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	char	c;
	size_t	len;

	if (str && find)
	{
		len = ft_strlen(find);
		if (len == 0)
			return ((char *)str);
		while ((c = *str) && n >= len)
		{
			if (!ft_strncmp(str, find, len))
				return ((char *)str);
			++str;
			--n;
		}
	}
	return (0);
}
