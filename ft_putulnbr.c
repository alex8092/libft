/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:23:57 by amerle            #+#    #+#             */
/*   Updated: 2013/11/28 15:23:58 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putulnbr_rec(unsigned long int number)
{
	char	c;

	if (number)
	{
		c = (number % 10) + '0';
		ft_putulnbr_rec(number / 10);
		ft_putchar(c);
	}
}

void	ft_putulnbr(unsigned long int number)
{
	if (!number)
		ft_putstr("0");
	else
		ft_putulnbr_rec(number);
}
