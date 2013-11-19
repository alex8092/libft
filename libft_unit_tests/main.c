/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:33:54 by amerle            #+#    #+#             */
/*   Updated: 2013/11/19 16:32:32 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_test_memset2(char *str, char *str2, int n)
{
	int	res;

	res = 0;
	ft_memset(str, '{', n);
	memset(str2, '{', n);
	ft_putstr("After : \"");
	ft_putstr(str);
	ft_putstr("\" , \"");
	ft_putstr(str2);
	ft_putstr("\"");
	if (ft_strcmp(str, str2))
		++res;
	if (!res)
		ft_putstr(" [SUCCESS]\n");
	else
		ft_putstr(" [FAIL]\n");
	return (res);
}

int	ft_test_memset(void)
{
	int res;
	char str[] = "Bonjour";
	char str2[] = "bonjour";

	res = 0;
	ft_putstr("\nBegin unit test : ft_memset\n");
	res += ft_test_memset2(str, str2, 4);
	ft_putstr("End unit test : ft_memset");
	if (!res)
		ft_putstr(" [Success]\n");
	else
		ft_putstr(" [Fail]\n");
	return (res);
}

int ft_test_strcmp2(char *str, char *str2)
{
	int	res;
	int	res2;

	res = ft_strcmp(str, str2);
	res2 = strcmp(str, str2);
	ft_putstr("Compare \"");
	ft_putstr(str);
	ft_putstr("\" and \"");
	ft_putstr(str2);
	ft_putstr("\" { ");
	ft_putnbr(res);
	ft_putstr(" , ");
	ft_putnbr(res2);
	ft_putstr(" } ");
	if (res == res2)
		ft_putstr("[OK]\n");
	else
		ft_putstr("[FAIL]\n");
	return (res != res2);
}

int	ft_test_strcmp(void)
{
	int res;

	res = 0;
	ft_putstr("Begin unit test : ft_strcmp\n");
	res += ft_test_strcmp2("test", "testing");
	res += ft_test_strcmp2("bonjour", "");
	res += ft_test_strcmp2("hello", "hello");
	res += ft_test_strcmp2("", "");
	ft_putstr("End unit test : ft_strcmp");
	if (!res)
		ft_putstr(" [Success]\n");
	else
		ft_putstr(" [Fail]\n");
	return (res);
}

int	main(void)
{
	int	res;

	res = 0;
	res += ft_test_strcmp();
	res += ft_test_memset();	
	return (0);
}
