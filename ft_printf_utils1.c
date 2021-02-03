/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:05:38 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/03 08:57:48 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n)
{
	int		sign;
	char	c;

	sign = 1;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
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
void	ft_putstr(char *str)
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
