/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 09:41:05 by amerle            #+#    #+#             */
/*   Updated: 2013/11/30 09:41:07 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_H
# define REGEX_H

# include "libft.h"
# include <stdio.h>

# define REGOP_BASE		0
# define REGOP_BRACK	1
# define REGOP_REP		2
# define REGOP_ANY		3
# define REGOP_STAR		4
# define REGOP_BEGEND	5
# define REGOP_QUEST	REGOP_STAR
# define REGOP_PLUS		REGOP_STAR
# define REGOP_SUB		6

typedef struct		s_regop
{
	char			type;
	struct s_regop	*next;
	t_bool			skip_false;
}					t_regop;

typedef struct	s_op_base
{
	t_regop		base;

	char		find;
}				t_op_base;

typedef struct	s_op_brack
{
	t_regop		base;

	char		*s_brack;
	t_bool		in_brack;
}				t_op_brack;

typedef struct	s_op_rep
{
	t_regop		base;

	t_regop		*rep;
	int			min_rep;
	int			max_rep;
}				t_op_rep;

typedef struct	s_op_any
{
	t_regop		base;
}				t_op_any;

typedef struct	s_op_star
{
	t_regop		base;

	t_op_rep	*rep;
}				t_op_star;

typedef t_op_star	t_op_quest;
typedef t_op_star	t_op_plus;

typedef struct	s_op_sub
{
	t_regop		base;

	t_regop		*begin_op;
	t_regop		*end_op;
}				t_op_sub;

typedef struct	s_op_begend
{
	t_regop		base;

	t_bool		beg;
}				t_op_begend;

typedef struct	s_regex
{
	char	*s_base;
	size_t	pos;
	size_t	len_b;
	char	*s_reg;
	size_t	pos_reg;
	size_t	len_r;
	t_regop	*save_op;
	t_regop	*beg_op;
	t_regop	*end_op;
	t_bool	use_sub;
	t_bool	match;
	char	*p_match;
}				t_reg;

t_regop	*ft_reg_create_op(char type, t_reg *reg);

void	ft_reg_parse(t_reg *reg);

void	ft_reg_parse_any(t_reg *reg);
void	ft_reg_parse_star(t_reg *reg);
void	ft_reg_parse_quest(t_reg *reg);
void	ft_reg_parse_begend(t_reg *reg, t_bool beg);
void	ft_reg_parse_sub(t_reg *reg);

t_bool	ft_match_rep(t_op_rep *op, t_reg *reg);
t_bool	ft_match_any(t_op_any *any, t_reg *reg);
t_bool	ft_match_star(t_op_star *op, t_reg *reg);
t_bool	ft_match_op(t_regop *op, t_reg *reg);
t_bool	ft_match_begend(t_op_begend *op, t_reg *reg);
t_bool	ft_match_sub(t_op_sub *sub, t_reg *reg);
void	ft_reg_parse_sub_end(t_reg *reg);

void	ft_reg_matcher(t_reg *reg);

t_bool	ft_reg_match_ismatchnext(t_regop *current, t_reg *reg, int s_pos);

#endif
