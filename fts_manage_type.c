/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_manage_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:15:48 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/09 18:03:59 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_d(t_strutt *strutt, va_list ap)
{
	int len;
	int num;
	char *str;

	num = va_arg(ap, int);
	if (num == 0 && strutt->dot == 1 && (strutt->precision == 0 || strutt->precision == -1))
	{
		ft_num_is_zero(strutt, ap);
		return ;
	}
	if (num < 0)
	{
		num = num * -1;
		strutt->width = strutt->width - 1;
		strutt->num_is_neg = 1;
	}
	str = ft_itoa(num);
	len = ft_strlen(str);
	if (strutt->precision <= len && strutt->width <= len)
	{
		if(strutt->num_is_neg)
			ft_putchar("-", 1, strutt);
		ft_putchar(str, len, strutt);
		return ;
	}
	if (strutt->flag_minus == 0)
	{
		if(strutt->flag_zero && strutt->width > len
			&& (strutt->precision <= -1 || !strutt->dot))
		{
			if(strutt->num_is_neg)
				ft_putchar("-", 1, strutt);
			ft_zero_nbr(strutt->width - len, strutt);
			ft_putchar(str,len,strutt);
			return ;
		}

		if(strutt->width > len && strutt->precision <= len)
			ft_space_nbr(strutt->width - len, strutt);
		if(strutt->width > strutt->precision && strutt->precision > len)
			ft_space_nbr(strutt->width - strutt->precision, strutt);
		if(strutt->num_is_neg)
			ft_putchar("-", 1, strutt);
		if(strutt->precision > len)
			ft_zero_nbr(strutt->precision - len, strutt);
		ft_putchar(str,len,strutt);
	}
	if (strutt->flag_minus == 1)
	{
		if(strutt->num_is_neg)
			ft_putchar("-", 1, strutt);
		if (strutt->precision > len)
			ft_zero_nbr(strutt->precision - len, strutt);
		ft_putchar(str, len, strutt);
		if(strutt->width > len && strutt->precision <= len)
			ft_space_nbr(strutt->width - len, strutt);
		if(strutt->width > strutt->precision && strutt->precision > len)
			ft_space_nbr(strutt->width - strutt->precision, strutt);
	}
}

void	ft_s(t_strutt *strutt, va_list ap)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
//	if (str == NULL)
//	{
//		len = 7;
//		str = "(null)\0";
//	}
//	else
		len = ft_strlen(str);
	if (strutt->width <= len &&
		(strutt->precision >= len || strutt->precision == -1))
	{
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
		ft_putchar(&c, 1, strutt);
		//write(1, &c,1);
	}
	if (strutt->flag_minus == 1)
	{
		ft_putchar(&c, 1, strutt);
		//write(1, &c, 1);
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
		//write(1, str, len);
		ft_putchar(str, len, strutt);
		return ;
	}
	if (strutt->flag_minus == 0)
	{
		ft_space_nbr(len, strutt);
		ft_zero_nbr(len, strutt);
		//write(1, str, len);
		ft_putchar(str, len, strutt);
	}
	if (strutt->flag_minus == 1)
	{
		ft_zero_nbr(len, strutt);
		//write(1, str, len);
		ft_putchar(str, len, strutt);
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
		ft_putchar("0x", 2, strutt);
		//write(1, "0x", 2);
		ft_putchar(str, len, strutt);
		//write(1, str, len);
		return ;
	}
	strutt->width = strutt->width - 2;
	if (strutt->flag_minus == 0)
	{
		ft_space_nbr(len, strutt);
		ft_putchar("0x", 2, strutt);
		//write(1, "0x", 2);
		ft_zero_nbr(len, strutt);
		ft_putchar(str, len, strutt);
		//write(1, str, len);
	}
	if (strutt->flag_minus == 1)
	{
		ft_putchar("0x", 2, strutt);
		//write(1, "0x", 2);
		ft_zero_nbr(len, strutt);
		ft_putchar(str, len, strutt);
		//write(1, str, len);
		ft_space_nbr(len, strutt);
	}
}
