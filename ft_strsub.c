/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:33:01 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 17:36:49 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s && len > 0)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		ft_strncpy(str, s + start, len);
		str[len] = 0;
		return (str);
	}
	return (ft_strdup(""));
}
