/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reg_matcher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 11:05:14 by amerle            #+#    #+#             */
/*   Updated: 2013/11/30 11:05:18 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex.h"

static t_bool	ft_match_brack(t_op_brack *op, t_reg *reg);
static t_bool	ft_match_base(t_op_base *op, t_reg *reg);


t_bool	ft_match_op(t_regop *op, t_reg *reg)
{
	if (op->type == REGOP_BRACK)
		return (ft_match_brack((t_op_brack *)op, reg));
	else if (op->type == REGOP_BASE)
		return (ft_match_base((t_op_base *)op, reg));
	else if (op->type == REGOP_REP)
		return (ft_match_rep((t_op_rep *)op, reg));
	else if (op->type == REGOP_ANY)
		return (ft_match_any((t_op_any *)op, reg));
	else if (op->type == REGOP_STAR || op->type == REGOP_QUEST)
		return (ft_match_star((t_op_star *)op, reg));
	else if (op->type == REGOP_BEGEND)
		return (ft_match_begend((t_op_begend *)op, reg));
	else if (op->type == REGOP_SUB)
		return (ft_match_sub((t_op_sub *)op, reg));
	else
		return (false);
}

static t_bool	ft_match_brack(t_op_brack *op, t_reg *reg)
{
	t_bool	res;

	if (op->s_brack[0] != '^')
		res = ft_reg_isinarray(reg->s_base[reg->pos], op->s_brack);
	else
		res = !ft_reg_isinarray(reg->s_base[reg->pos], op->s_brack + 1);
	if (res)
		++reg->pos;
	ft_printf("match brack (%d)\n", res);
	return (res);
}

static t_bool	ft_match_base(t_op_base *op, t_reg *reg)
{
	t_bool	res;

	res = false;
	if (reg->s_base[reg->pos] == op->find)
		res = true;
	if (res)
		++reg->pos;
	ft_printf("match base '%c' - '%c'\n", reg->s_base[reg->pos], op->find);
	return (res);
}

void			ft_reg_matcher(t_reg *reg)
{
	t_regop	*current;
	size_t	i_save;

	i_save = reg->pos;
	while ((i_save = reg->pos) < reg->len_b)
	{
		current = reg->beg_op;
		reg->match = true;
		while (current && reg->match)
		{
			reg->match = ft_match_op(current, reg);
			if (current->skip_false)
				reg->match = true;
			current = current->next;
		}
		if (reg->match)
		{
			reg->p_match = reg->s_base + i_save;
			return ;
		}
		reg->pos = i_save;
		++reg->pos;
	}
}
