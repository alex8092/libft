/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 01:57:11 by amerle            #+#    #+#             */
/*   Updated: 2013/11/24 01:57:14 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putunbr_rec(unsigned int number)
{
	char	c;

	if (number)
	{
		c = (number % 10) + '0';
		ft_putunbr_rec(number / 10);
		ft_putchar(c);
	}
}

void	ft_putunbr(unsigned int number)
{
	if (!number)
		ft_putstr("0");
	else
		ft_putunbr_rec(number);
}
