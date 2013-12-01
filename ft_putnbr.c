/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:31:28 by amerle            #+#    #+#             */
/*   Updated: 2013/11/19 15:54:18 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(int number)
{
	char	c;

	if (number)
	{
		c = (number % 10) + '0';
		ft_putnbr_rec(number / 10);
		ft_putchar(c);
	}
}

void	ft_putnbr(int number)
{
	if (number != 0)
	{
		if (number < 0)
		{
			ft_putchar('-');
			number *= -1;
		}
		ft_putnbr_rec(number);
	}
	else
	{
		ft_putchar('0');
	}
}
