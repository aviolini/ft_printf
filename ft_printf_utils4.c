/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:15:48 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/05 16:15:43 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_d(t_strutt *strutt, va_list ap)
{
	int len;
	int num;
	int sign;

	sign = 0;
	num = va_arg(ap, int);
	len = ft_size_number(num);
	if (num < 0)
	{
		sign = 1;
	 	num = num * -1;
		len = len - 1;
		strutt->width = strutt->width - 1;
	}
	if (strutt->precision <= len && strutt->width <= len)
	{
		if(sign)
			write(1, "-", 1);
		ft_putnbr(num);
		return ;
	}
	if (strutt->flag_minus == 0)
	{
		ft_space(len, strutt->width, strutt->precision);
		if(sign)
			write(1, "-", 1);
		ft_zero(len, strutt->width, strutt->precision);
		ft_putnbr(num);
	}
	if (strutt->flag_minus == 1)
	{
		if(sign)
			write(1, "-", 1);
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

void	ft_xXu(t_strutt *strutt, va_list ap, char *base)
{
	char			*str;
	unsigned int	n;
	int				len;

	n = va_arg(ap, unsigned int);
	len = ft_size_number_uns_diffbase(n, base);
	str = ft_itoa_base(n, len, base);
	if (strutt->precision <= len && strutt->width <= len)
	{
		write(1, str, len);
		return ;
	}
	if (strutt->flag_minus == 0)
	{
		ft_space(len, strutt->width, strutt->precision);
		ft_zero(len, strutt->width, strutt->precision);
		write(1, str, len);
	}
	if (strutt->flag_minus == 1)
	{
		ft_zero(len, strutt->width, strutt->precision);
		write(1, str, len);
		ft_space(len, strutt->width, strutt->precision);
	}
	free(str);
}

void	ft_p(t_strutt *strutt, va_list ap)
{
	char 				*str;
	unsigned long long	n;
	int					len;

	n = va_arg(ap,unsigned long long);
	len = ft_size_number_uns_diffbase(n, BASE16);
	str = ft_itoa_base(n, len, BASE16);
	if (strutt->precision <= len && strutt->width <= len)
	{
		write(1, "0x", 2);
		write(1, str, len);
		return ;
	}
	if (strutt->flag_minus == 0)
	{
		ft_space(len, strutt->width - 2, strutt->precision);
		write(1, "0x", 2);
		ft_zero(len, strutt->width - 2, strutt->precision);
		write(1, str, len);
	}
	if (strutt->flag_minus == 1)
	{
		write(1, "0x", 2);
		ft_zero(len, strutt->width - 2, strutt->precision);
		write(1, str, len);
		ft_space(len, strutt->width - 2, strutt->precision);
	}
	free(str);
}
