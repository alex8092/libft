/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:35:07 by amerle            #+#    #+#             */
/*   Updated: 2013/11/20 19:16:35 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



static void		ft_itoa_fill(char *number, unsigned int n)
{
	char	num;

	if (number && n)
	{
		num = (n % 10) + '0';
		n /= 10;
		ft_itoa_fill(number - 1, n);
		*number = num;
	}
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*number;

	count = ft_itoa_ccount((n < 0) ? n * -1 : n);
	if (n < 0)
	{
		number = (char *)malloc(sizeof(char) * (count + 2));
		number[0] = '-';
		ft_itoa_fill(number + count, n * -1);
		number[count + 1] = 0;
	}
	else if (n == 0)
	{
		number = (char *)malloc(sizeof(char) * 2);
		number[0] = '0';
		number[1] = 0;
	}
	else
	{
		number = (char *)malloc(sizeof(char) * (count + 1));
		ft_itoa_fill(number + count - 1, n);
		number[count] = 0;
	}
	return (number);
}
