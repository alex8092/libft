/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:15:02 by amerle            #+#    #+#             */
/*   Updated: 2013/11/28 15:15:05 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putlnbr_rec(long int number)
{
	char	c;

	if (number)
	{
		c = (number % 10) + '0';
		ft_putlnbr_rec(number / 10);
		ft_putchar(c);
	}
}

void		ft_putlnbr(long int number)
{
	if (number != 0)
	{
		if (number < 0)
		{
			ft_putchar('-');
			number *= -1;
		}
		ft_putlnbr_rec(number);
	}
	else
	{
		ft_putchar('0');
	}
}
