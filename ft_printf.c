/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 22:11:02 by amerle            #+#    #+#             */
/*   Updated: 2013/11/23 22:11:03 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_printf.h"

static void	ft_printf_parse_precision(char const **s, t_printf *st)
{
	char const	*current;
	char		*tmp;

	if (*(*s) == '.')
	{
		if (*((*s) + 1) == '*')
		{
			st->precision = va_arg(*st->va, int);
			*s = ((*s) + 2);
		}
		else
		{
			current = (*s) + 1;
			while (*current >= '0' && *current <= '9')
				++current;
			tmp = ft_strsub((*s) + 1, 0, current - (*s) - 1);
			st->precision = ft_atoi(tmp);
			free(tmp);
			*s = current;
		}
	}
}

static void	ft_printf_parse_prevalue(char const **s, t_printf *st)
{
	char const	*current;
	char const	*save;

	current = *s;
	ft_printf_parse_flags(&current, st);
	if (*current >= '0' && *current <= '9')
	{
		save = current;
		while (*current >= '0' && *current <= '9')
			++current;
		save = ft_strsub(save, 0, current - save - 1);
		st->min_display = ft_atoi(save);
		free((char *)save);
	}
	else if (*current == '*' && (current++))
		st->min_display = va_arg(*st->va, int);
	ft_printf_parse_precision(&current, st);
	ft_printf_parse_sublength(&current, st);
	*s = current;
}

static void	ft_printf_parse(char c, t_printf *st)
{
	unsigned int	uivalue;

	if (c == 's')
		ft_printf_display_string(va_arg(*st->va, char *), st);
	else if (c == 'd' || c == 'i')
		ft_printf_dis_lint(va_arg(*st->va, long int), st);
	else if (c == 'u')
	{
		uivalue = va_arg(*st->va, unsigned int);
		if (st->display_sign)
			ft_putchar('+');
		ft_putunbr(uivalue);
	}
	else if (c == 'p')
		ft_putlhex(va_arg(*st->va, unsigned long int), true);
	else
		ft_printf_parse_2(c, st);
}

static void	ft_printf_next_percent(char const **s, t_printf *st)
{
	char const	*current;

	current = *s;
	ft_printf_reset_prevalues(st);
	st->display_sign = false;
	while (*current != 0 && *current != '%')
		++current;
	if (*s != current)
		write(1, *s, (size_t)(current - (*s)));
	if (*current)
	{
		++current;
		ft_printf_parse_prevalue(&current, st);
		if (*current != '%')
			ft_printf_parse(*current, st);
		else
			ft_putchar('%');
		++current;
	}
	*s = current;
}

void	ft_printf(char const *s, ...)
{
	const char	*current;
	va_list		va;
	t_printf	st;

	ft_bzero(&st, sizeof(t_printf));
	st.va = &va;
	va_start(va, s);
	current = s;
	while (*current)
		ft_printf_next_percent(&current, &st);
}
