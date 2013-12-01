/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexinarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 23:09:45 by amerle            #+#    #+#             */
/*   Updated: 2013/11/28 23:09:45 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_indexinarray(char *str, char **tab, size_t tab_len)
{
	size_t	i;

	i = 0;
	while (i < tab_len)
	{
		if (!ft_strcmp(tab[i], str))
			return ((int)i);
		++i;
	}
	return (-1);
}
