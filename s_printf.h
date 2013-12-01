/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 05:29:48 by amerle            #+#    #+#             */
/*   Updated: 2013/11/25 05:29:50 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PRINTF_H
# define S_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_printf
{
	t_bool		display_sign;
	va_list		*va;
	int			min_display;
	t_bool		right_align;
	t_bool		no_sign_space;
	t_bool		diese_flag;
	t_bool		fill_zero;
	int			precision;
	t_bool		l_size;
}				t_printf;

void	ft_printf_reset_prevalues(t_printf *st);
void	ft_printf_parse_flags(char const **s, t_printf *st);
void	ft_printf_dis_int(int number, t_printf *st);
void	ft_printf_dis_lint(long int number, t_printf *st);
void	ft_printf_parse_sublength(char const **s, t_printf *st);
void	ft_printf_display_string(char *str, t_printf *st);
void	ft_printf_parse_2(char c, t_printf *st);

#endif
