/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 04:09:37 by amerle            #+#    #+#             */
/*   Updated: 2013/11/24 04:09:38 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putlhex_rec(unsigned long int number, t_bool lower)
{
	char	c;
	char	map[] = "0123456789abcdef";

	if (number)
	{
		c = (char)(number & 0xF);
		number = (number >> 4);
		ft_putlhex_rec(number, lower);
		if (lower)
			ft_putchar(map[(int)c]);
		else
			ft_putchar(ft_toupper(map[(int)c]));
	}
}

void		ft_putlhex(unsigned long int number, t_bool lower)
{
	ft_putstr("0x");
	ft_putlhex_rec(number, lower);
}
