/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:05:38 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/04 18:16:58 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_itoa(int n)
{
	char *str;
	int i;
	int len;

	len = ft_size_number(n);
	str = (char *)malloc(sizeof(char) * len);
	i = -1;
	if (n < 0)
	{
		n = n * - 1;
		str[0] = '-';
		i++;
	}
	while (--len > i)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
int		ft_size_number(int n)
{
	int i;

	i = 0;
	if ( n == 0)
		i++;
	if (n < 0)
		{
			n = n * -1;
			i++;
		}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
void	ft_putnbr(int n)
{
	int		sign;
	char	c;

	sign = 1;
	if (n == -2147483648)
	{
		ft_putmax("-2147483648");
		return ;
	}
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
		write(1, "-", 1);
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		return ;
	}
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
}
void	ft_putmax(char *str)
{
	size_t i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i--);
}
int		ft_strlen(char *str)   //return con \0
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
