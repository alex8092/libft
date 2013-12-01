/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 06:15:19 by amerle            #+#    #+#             */
/*   Updated: 2013/11/25 06:15:21 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_printf.h"

void		ft_printf_parse_flags(char const **s, t_printf *st)
{
	char		c;

	c = *(*s);
	if (c != '+' && c != '-' && c != ' ' && c != '#' && c != '0')
		return ;
	if (c == '+')
		st->display_sign = true;
	else if (c == '-')
		st->right_align = false;
	else if (c == ' ')
		st->no_sign_space = true;
	else if (c == '#')
		st->diese_flag = true;
	else if (c == '0')
		st->fill_zero = true;
	*s = ((*s) + 1);
	ft_printf_parse_flags(s, st);
}

static void	ft_printf_dis_int2(long int number, t_printf *st, size_t len_dis)
{
	int	n;

	if (st->precision > 0)
		n = (st->precision > (int)len_dis) ? st->precision : (int)len_dis;
	else
		n = len_dis;
	while (n < st->min_display)
	{
		ft_putchar(' ');
		++n;
	}
	(void)len_dis;
	if (number >= 0 && st->display_sign)
		ft_putchar('+');
	else if (number < 0)
		ft_putchar('-');
}

void		ft_printf_dis_int(int number, t_printf *st)
{
	size_t	len_dis;
	size_t	n;

	if (st->precision == 0 && number == 0)
		return ;
	len_dis = ft_itoa_ccount((number < 0) ? number * -1 : number);
	if (number < 0)
		++len_dis;
	ft_printf_dis_int2(number, st, len_dis);
	if ((int)len_dis < st->precision && st->right_align)
	{
		n = st->precision - len_dis;
		while (n--)
			ft_putchar('0');
	}
	if (number < 0)
		ft_putunbr(number * -1);
	else
		ft_putunbr(number);
	if ((int)len_dis < st->precision && !st->right_align)
	{
		n = st->precision - len_dis;
		while (n--)
			ft_putchar('0');
	}
}

void		ft_printf_dis_lint(long int number, t_printf *st)
{
	size_t	len_dis;
	int		n;

	if (st->precision == 0 && number == 0)
		return ;
	len_dis = ft_itoa_ccount((number < 0) ? number * -1 : number);
	if (number < 0)
		++len_dis;
	ft_printf_dis_int2(number, st, len_dis);
	if ((int)len_dis < st->precision && st->right_align)
	{
		n = st->precision - len_dis;
		while (n--)
			ft_putchar('0');
	}
	if (number < 0)
		ft_putunbr(number * -1);
	else
		ft_putunbr(number);
	if ((int)len_dis < st->precision && !st->right_align)
	{
		n = st->precision - len_dis;
		while (n--)
			ft_putchar('0');
	}
}

void		ft_printf_reset_prevalues(t_printf *st)
{
	st->min_display = 0;
	st->precision = -1;
	st->right_align = true;
}
