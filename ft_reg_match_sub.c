/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reg_match_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:30:18 by amerle            #+#    #+#             */
/*   Updated: 2013/12/01 19:30:19 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex.h"

t_bool	ft_match_sub(t_op_sub *sub, t_reg *reg)
{
	size_t	s_pos;
	t_regop	*tmp;

	s_pos = reg->pos;
	ft_printf("match sub\n");
	tmp = (t_regop *)ft_memalloc(sizeof(t_regop));
	tmp->next = sub->begin_op;
	if (ft_reg_match_ismatchnext(tmp, reg, -1))
	{
		free(tmp);
		return (true);
	}
	free(tmp);
	ft_printf("match sub fail\n");
	reg->pos = s_pos;
	return (false);
}

void	ft_reg_parse_sub(t_reg *reg)
{
	reg->save_op = ft_reg_create_op(REGOP_SUB, reg);
	++reg->pos_reg;
}

void	ft_reg_parse_sub_end(t_reg *reg)
{
	((t_op_sub *)reg->save_op)->begin_op = reg->save_op->next;
	reg->save_op->next = 0;
	reg->end_op = reg->save_op;
	reg->save_op = 0;
	++reg->pos_reg;
}
