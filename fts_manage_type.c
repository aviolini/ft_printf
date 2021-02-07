/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_manage_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:15:48 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/07 00:51:50 by aviolini         ###   ########.fr       */
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
	len = ft_size_nbr(num);
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
		ft_space_nbr(len, strutt);
		if(sign)
			write(1, "-", 1);
		ft_zero_nbr(len, strutt);
		ft_putnbr(num);
	}
	if (strutt->flag_minus == 1)
	{
		if(sign)
			write(1, "-", 1);
		ft_zero_nbr(len, strutt);
		ft_putnbr(num);
		ft_space_nbr(len, strutt);
	}
}

void	ft_s(t_strutt *strutt, va_list ap)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if (strutt->width <= len &&
		(strutt->precision >= len || strutt->precision == -1))
	{
		//write(1 , str, len);
		ft_putchar(str, len, strutt);
		return ;
	}
	if (strutt->flag_minus == 0)
	{
		ft_space_str(len, strutt);
		ft_putstr(str, len, strutt);
		return ;
	}
	if (strutt->flag_minus == 1)
	{
		ft_putstr(str, len, strutt);
		ft_space_str(len, strutt);
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
		ft_space_str(len, strutt);
		write(1, &c,1);
	}
	if (strutt->flag_minus == 1)
	{
		write(1, &c, 1);
		ft_space_str(len, strutt);
	}

}

void	ft_xXu(t_strutt *strutt, va_list ap, char *base)
{
	char			*str;
	unsigned int	n;
	int				len;

	n = va_arg(ap, unsigned int);
	len = ft_size_nbr_uns_diffbase(n, base);
	str = ft_itoa_base(n, len, base);
	if (strutt->precision <= len && strutt->width <= len)
	{
		write(1, str, len);
		return ;
	}
	if (strutt->flag_minus == 0)
	{
		ft_space_nbr(len, strutt);
		ft_zero_nbr(len, strutt);
		write(1, str, len);
	}
	if (strutt->flag_minus == 1)
	{
		ft_zero_nbr(len, strutt);
		write(1, str, len);
		ft_space_nbr(len, strutt);
	}
	free(str);
}

void	ft_p(t_strutt *strutt, va_list ap)
{
	char 				*str;
	unsigned long long	n;
	int					len;

	n = va_arg(ap, unsigned long long);
	len = ft_size_nbr_uns_diffbase(n, BASE16);
	str = ft_itoa_base(n, len, BASE16);
	if (strutt->precision <= len && strutt->width <= len)
	{
		write(1, "0x", 2);
		write(1, str, len);
		return ;
	}
	strutt->width = strutt->width - 2;
	if (strutt->flag_minus == 0)
	{
		ft_space_nbr(len, strutt);
		write(1, "0x", 2);
		ft_zero_nbr(len, strutt);
		write(1, str, len);
	}
	if (strutt->flag_minus == 1)
	{
		write(1, "0x", 2);
		ft_zero_nbr(len, strutt);
		write(1, str, len);
		ft_space_nbr(len, strutt);
	}
}
