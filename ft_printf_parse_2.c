/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 21:52:52 by amerle            #+#    #+#             */
/*   Updated: 2013/12/01 21:52:53 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_printf.h"

void	ft_printf_parse_2(char c, t_printf *st)
{
	if (c == 'x' || c == 'X')
		ft_putlhex(va_arg(*st->va, unsigned long int), (c == 'x'));
	else if (c == 'c')
		ft_putchar((char)va_arg(*st->va, int));
	else if (c == 'f' || c == 'F')
	{
		if (st->precision == -1)
			ft_putdouble(va_arg(*st->va, double), true, 6);
		else
			ft_putdouble(va_arg(*st->va, double), true, st->precision);
	}
	else if (c == '%')
		ft_putchar('%');
}
