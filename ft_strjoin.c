/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:37:06 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 17:40:41 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n;

	if (s1 && s2)
	{
		n = ft_strlen(s1);
		str = (char *)malloc(sizeof(char) * (n + ft_strlen(s2) + 1));
		ft_strcpy(str, s1);
		ft_strcpy(str + n, s2);
		return (str);
	}
	return (0);
}
