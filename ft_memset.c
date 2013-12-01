/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:31:34 by amerle            #+#    #+#             */
/*   Updated: 2013/11/21 16:57:51 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;

	tmp = (char *)b;
	if (tmp && len > 0)
	{
		while (len)
		{
			*tmp = (unsigned char)c;
			--len;
			++tmp;
		}
	}
	return (b);
}
