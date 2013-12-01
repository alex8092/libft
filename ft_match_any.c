/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_any.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 14:00:22 by amerle            #+#    #+#             */
/*   Updated: 2013/12/01 14:00:22 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex.h"

t_bool	ft_match_any(t_op_any *any, t_reg *reg)
{
	t_bool	res;

	(void)any;
	ft_printf("Match any\n");
	res = false;
	if (reg->s_base[reg->pos] != '\0')
		res = true;
	if (res)
		++reg->pos;
	return (res);
}

void	ft_reg_parse_any(t_reg *reg)
{
	ft_reg_create_op(REGOP_ANY, reg);
	++reg->pos_reg;
}
