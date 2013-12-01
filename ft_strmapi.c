/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:24:09 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 17:27:04 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (s && f)
	{
		i = 0;
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		while (s[i])
		{
			str[i] = f(i, s[i]);
			++i;
		}
		str[i] = 0;
		return (str);
	}
	return (0);
}
