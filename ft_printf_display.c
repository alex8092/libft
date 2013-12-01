/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:13:55 by amerle            #+#    #+#             */
/*   Updated: 2013/11/29 00:13:56 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_printf.h"

void	ft_printf_display_string(char *str, t_printf *st)
{
	int	pad;

	pad = (st->precision != -1) ? (size_t)st->precision : ft_strlen(str);
	while (pad < st->min_display && st->right_align)
	{
		ft_putchar(' ');
		++pad;
	}
	if (st->precision != -1)
		write(1, str, st->precision);
	else
		ft_putstr(str);
	while (pad < st->min_display && !st->right_align)
	{
		ft_putchar(' ');
		++pad;
	}
}
