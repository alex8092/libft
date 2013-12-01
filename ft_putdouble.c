/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 02:56:45 by amerle            #+#    #+#             */
/*   Updated: 2013/11/25 02:56:48 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble(double number, t_bool use_preci, size_t precision)
{
	int		tmp;

	if (!use_preci)
		precision = 100;
	if (precision > 0)
	{
		tmp = (int)number;
		number -= tmp;
		ft_putnbr(tmp);
		ft_putchar('.');
		while (precision)
		{
			tmp = 0;
			if (number)
			{
				number *= 10;
				tmp = (int)number;
				number -= tmp;
			}
			else if (!use_preci)
				break ;
			ft_putchar((char)(tmp + '0'));
			--precision;
		}
	}
}
