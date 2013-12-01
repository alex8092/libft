/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:07:25 by amerle            #+#    #+#             */
/*   Updated: 2013/11/19 15:07:59 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	char	c;
	size_t	len;

	if (str && find)
	{
		len = ft_strlen(find);
		if (len == 0)
			return ((char *)str);
		while ((c = *str))
		{
			if (!ft_strncmp(str, find, len))
				return ((char *)str);
			++str;
		}
	}
	return (0);
}
