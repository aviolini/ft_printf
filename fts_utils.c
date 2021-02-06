/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:23:57 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/06 12:08:16 by aviolini         ###   ########.fr       */
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
	(void)width;

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
	if (precision <= len)
		y = width - precision;
	if (precision > len)
		y = width - len;
	if (len == -1)
		y = width-1;
	while (x++ < y)
		write(1, " ", 1);
}

void	ft_putstr(char *str, int len,int width, int precision)
{
	(void)width;
	if (precision <= len)
		write(1, str, precision);
	if (precision > len)
		write(1, str, len);
}

int		ft_strlen(char *str)   //return con \0
{
	int i;
	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
