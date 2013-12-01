/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 21:04:43 by amerle            #+#    #+#             */
/*   Updated: 2013/11/26 21:07:02 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isinarray(char c, char const *chars)
{
	while (*chars)
	{
		if (c == *chars)
			return (true);
		++chars;
	}
	return (false);
}
