/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_fill_strutt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:15:37 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/10 13:45:12 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_typeflag(t_strutt *strutt, const char *str, int i, va_list ap)
{
	(void)ap;

	if (str[i] == '0' && str[i + 1] != '-')
	{
		strutt->flag_zero = 1;
		i++;
	}
	if (str[i] == '-' && str[i + 1] != '0')
	{
		strutt->flag_minus = 1;
		i++;
	}
	if (((str[i]) == '0' && str[i + 1] == '-')
	|| (str[i] == '-' && str[i + 1] == '0'))
	{
		strutt->flag_zero = 1;
		strutt->flag_minus = 1;
		i = i + 2;
	}
	return (i);
}

int		ft_typewidth(t_strutt *strutt, const char *str, int i, va_list ap)
{
	int x;

	x = 0;
	while(str[i] == '0' || str[i] == '-')
		i++;
	if (str[i] == '*')
	{
		x = va_arg(ap, int);
		if (x < 0)
		{
			strutt->flag_minus = 1;
			x = x * -1;
		}
		strutt->width = x;
		i++;
		return (i);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = (str[i] - 48) + (x * 10);
		i++;
	}
	strutt->width = x;
	return (i);
}

int		ft_typeprecision(t_strutt *strutt, const char *str, int i, va_list ap)
{
	int x;

	x = 0;
	if (str[i] == '.')
	{
		strutt->dot = 1;
		i++;
	}
	if (str[i] == '*')
	{
		x = va_arg(ap, int);
		strutt->precision = x;
		if (x <= -1)
		{
			//strutt->precision = 0;
			strutt->prec_is_arg = 1;
		}
		i++; //FORSE CI VUOLE UN RETURN DI i DIRETTO
		return (i);
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			x = (str[i] - 48) + (x * 10);
			i++;
		}
		strutt->precision = x;
		return (i);
	}
	strutt->precision = -1;
	return (i);
}

char	ft_typearg(t_strutt *strutt, const char *str, int i, va_list ap)
{
	(void)ap;
	(void)strutt;

	if((str[i]) == 'c')
		return ('c');
	if((str[i]) == 's')
		return ('s');
	if((str[i]) == 'p')
		return ('p');
	if((str[i]) == 'd' || (str[i]) == 'i')
		return ('d');
	if((str[i]) == 'x')
		return ('x');
	if ((str[i]) == 'X')
		return ('X');
	if ((str[i]) == 'u')
		return ('u');
	if ((str[i]) == '%')
		return ('%');
	return (0);
}
