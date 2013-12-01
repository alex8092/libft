/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reg_match_rep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 13:46:19 by amerle            #+#    #+#             */
/*   Updated: 2013/12/01 20:41:43 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex.h"

t_bool	ft_reg_match_ismatchnext(t_regop *current, t_reg *reg, int s_pos)
{
	t_bool	res;

	res = false;
	ft_printf("match begin\n");
	while ((current = current->next))
	{
		ft_printf("match next\n");
		if (!(res = ft_match_op(current, reg)))
		{
			if (!current->skip_false)
			{
				reg->pos = s_pos;
				break ;
			}
			else
				res = true;
		}
	}
	if (res && s_pos != -1)
		reg->pos = s_pos;
	return (res);
}

t_bool	ft_match_rep(t_op_rep *op, t_reg *reg)
{
	t_bool		res;
	int			i;
	size_t		s_pos;

	res = true;
	i = 1;
	while (i < op->min_rep && res && (i++))
		res = ft_match_op(op->rep, reg);
	if ((i == op->min_rep && res) || (op->min_rep == 0))
	{
		while ((i < op->max_rep && op->max_rep > 0)
			|| (op->max_rep == 0 && (i++)))
		{
			if (res && op->max_rep == 0 && (s_pos = reg->pos))
			{
				if (ft_reg_match_ismatchnext((t_regop *)op, reg, s_pos))
					return (true);
			}
			res = ft_match_op(op->rep, reg);
			if (!res)
				break ;
		}
		return (true);
	}
	return (false);
}

t_bool	ft_match_star(t_op_star *op, t_reg *reg)
{
	ft_printf("match star\n");
	return (ft_match_rep(op->rep, reg));
}

void	ft_reg_parse_star(t_reg *reg)
{
	t_op_star	*star;

	star = (t_op_star *)ft_reg_create_op(REGOP_STAR, reg);
	star->rep->min_rep = 0;
	star->rep->max_rep = 0;
	++reg->pos_reg;
}

void	ft_reg_parse_quest(t_reg *reg)
{
	t_op_quest	*quest;

	quest = (t_op_quest *)ft_reg_create_op(REGOP_QUEST, reg);
	quest->rep->min_rep = 0;
	quest->rep->max_rep = 1;
	++reg->pos_reg;
}
