/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:12:12 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/04 19:51:59 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_fill_strutt(t_strutt *strutt, const char *str, int i, va_list ap)
{
	ft_init_strutt(strutt);
	i = ft_typeflag(strutt, str, i + 1, ap);
	i = ft_typewidth(strutt, str, i, ap);
	i = ft_typeprecision(strutt, str, i,ap);
	strutt->type = ft_typearg(strutt, str, i, ap);
	return (i);
}

void	ft_use_strutt(t_strutt *strutt, const char *str, int i, va_list ap)
{
	if (strutt->type == 'd')
		ft_d(strutt, ap);
	if (strutt->type == 'c')
		ft_c(strutt, ap);
	if (strutt->type == 's')
		ft_s(strutt, ap);
/*	if (strutt->type == 'x')
		ft_x(strutt, ap);
	if (strutt->type == 'p')
		ft_p(strutt, ap);
*/		//MANCA ft_X
}

void	ft_d(t_strutt *strutt, va_list ap)
{
	int len;
	int num;

	num = va_arg(ap, int);
	len = ft_size_number(num);
	if (strutt->precision <= len && strutt->width <= len)
	{
		ft_putnbr(num);
		return ;
	}
	if (strutt->flag_minus == 0)
	{
		ft_space(len, strutt->width, strutt->precision);
		ft_zero(len, strutt->width, strutt->precision);
		ft_putnbr(num);
	}
	if (strutt->flag_minus == 1)
	{
		ft_zero(len, strutt->width, strutt->precision);
		ft_putnbr(num);
		ft_space(len, strutt->width, strutt->precision);
	}
}

void	ft_s(t_strutt *strutt, va_list ap)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if (strutt->width <= len &&
		(strutt->precision >= len || strutt->precision == -1))
	{
		write(1 ,str, len);
		return ;
	}
	if (strutt->flag_minus == 0)
	{
		ft_space_str(len, strutt->width, strutt->precision);
		ft_putstr(str, len, strutt->width, strutt->precision);
		return ;
	}
	if (strutt->flag_minus == 1)
	{
		ft_putstr(str, len, strutt->width, strutt->precision);
		ft_space_str(len, strutt->width, strutt->precision);
		return ;
	}

}

void	ft_c(t_strutt *strutt, va_list ap)
{
	char c;
	int len;

	len = -1;
	c = va_arg(ap, int);
	if (strutt->flag_minus == 0)
	{
		ft_space_str(len, strutt->width, strutt->precision);
		write(1, &c,1);
	}
	if (strutt->flag_minus == 1)
	{
		write(1, &c, 1);
		ft_space_str(len, strutt->width, strutt->precision);
	}

}
