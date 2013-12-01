/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_sublength.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:09:34 by amerle            #+#    #+#             */
/*   Updated: 2013/11/28 15:09:36 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_printf.h"

void	ft_printf_parse_sublength(char const **s, t_printf *st)
{
	char	*current;

	current = (char *)*s;
	if (*current == 'l')
	{
		st->l_size = true;
		++current;
	}
	*s = current;
}
