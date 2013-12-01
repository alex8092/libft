/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:50:15 by amerle            #+#    #+#             */
/*   Updated: 2013/11/21 21:12:04 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	str = (char *)s;
	while (i > 0)
	{
		if (str[i] == (char)c)
			return (str + i);
		--i;
	}
	return ((str[i] == (char)c) ? str : NULL);
}
