/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:23:57 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/04 18:35:28 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_space(int len, int width, int precision)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (precision == -1) //PER BYPASSARE IL -1
		precision++;
	if (width > precision && width > len)
	{
		if (precision > len)
			y = width - precision;
		if (precision <= len)
			y = width - len;
	}
	while (x++ < y)
		write(1, " ", 1);
}

void	ft_zero(int len, int width, int precision)
{
	int x;

	x = 0;
	if (precision > len)
		while (x++ < precision - len)
			write(1, "0", 1);
}

void	ft_space_str(int len, int width, int precision)
{
	int x;
	int y;

	x = 0;
	//	if (len > precision) ///////////////////// FARE PROVE
		y = width - precision;
	while (x++ < y)
		write(1, "8", 1);
}

void	ft_putstr(char *str, int len, int width, int precision)
{
	int y;

	y = 0;
	if (width > precision)
		write(1, str, precision);
}
