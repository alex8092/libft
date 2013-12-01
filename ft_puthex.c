/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 03:51:02 by amerle            #+#    #+#             */
/*   Updated: 2013/11/24 03:51:09 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_puthex_rec(unsigned int number)
{
	char	c;
	char	map[] = "0123456789abcdef";

	if (number)
	{
		c = (char)(number & 0xF);
		number = (number >> 4);
		ft_puthex_rec(number);
		ft_putchar(map[(int)c]);
	}
}

void		ft_puthex(unsigned int number)
{
	ft_putstr("0x");
	ft_puthex_rec(number);
}
