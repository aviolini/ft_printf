/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:15:37 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/03 13:42:59 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_strutt(t_strutt *strutt)
{
	strutt->flag_minus = 0;
	strutt->flag_zero = 0;
	strutt->width = 0;
	strutt->dot = 0;
	strutt->precision = -1;   // initially set as -1 instead of 0
	strutt->flag_pre_va = 0; // if precision is a variable argument
	strutt->num_m = 0;	     // is number negative?
	strutt->type = 0;
}

int		ft_typeflag(t_strutt *strutt, const char *str, int i, va_list ap)
{
	int		x;
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

int		ft_typewidthprec(t_strutt *strutt, const char *str, int i, va_list ap)
{
	if (str[i] == '*')
	{
		strutt->width = -2;
		i++;
	}
/*	if (str[i] >= 0 && str[i] <= 9)
	{
		x = va_arg(ap, int);
		strutt->width = x;
		i++;
	}
*/	if (str[i] == '.')
	{
		strutt->dot = 1;
		i++;
	}
	if (str[i] == '*')
	{
		strutt->precision = -2;
		i++;
	}
/*	if (str[i] >= 0 && str[i] <= 9)
	{
		x = va_arg(ap, int);
		strutt->precision = x;
		i++;
	}
*/	return (i);
}

int		ft_typearg(t_strutt *strutt, const char *str, int i, va_list ap)
{
	(void)ap;
//	(void)str;         //cspdiuxX%

	if((str[i]) == 'c')
		return (1);
	if((str[i]) == 's')
		return (2);
	if((str[i]) == 'p')
		return (3);
	if((str[i]) == 'd' || (str[i]) == 'i')
		return (4);
	if((str[i]) == 'x')
		return (5);
	if ((str[i]) == 'X')
		return (6);
	return (0);
}
