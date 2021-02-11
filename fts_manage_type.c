/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_manage_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:15:48 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/11 11:03:50 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_d(t_strutt *strutt, va_list ap)
{
	int len;
	int num;
	char *str;

	num = va_arg(ap, int);
	if (num == 0 && ft_num_is_zero(strutt))
		return ;
	if (num < 0)
		num = ft_num_is_neg(strutt, num);
	str = ft_itoa(num);
	len = ft_strlen(str);
	if (strutt->flag_minus == 0 && ft_zero_rather_space_sdxu(str, len, strutt))
			return ;
	ft_print_dxu(str, len, strutt);
}

void	ft_s(t_strutt *strutt, va_list ap)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		len = 6;
		str = "(null)";
	}
	else
		len = ft_strlen(str);
	if (strutt->width <= len && ((strutt->dot &&
		(strutt->precision >= len || strutt->prec_is_arg)) || !strutt->dot))//strutt->precision == -1))
	{
		ft_putchar(str, len, strutt);
		return ;
	}

	if (strutt->flag_minus == 0)
	{
		if (ft_zero_rather_space_sdxu(str, len, strutt))
			return ;
		if(strutt->width > len && (strutt->precision >= len || strutt->precision <= -1))
			{
				ft_space_nbr(strutt->width - len, strutt);
				ft_putchar(str, len, strutt);
				return ;
			}
		if (strutt->precision < len && strutt->precision != -1)
			{
				ft_space_nbr(strutt->width - strutt->precision, strutt);
				ft_putchar(str, strutt->precision, strutt);
				return ;
			}
	}

	if (strutt->flag_minus == 1)
	{
		if(strutt->width > len && (strutt->precision >= len || strutt->precision <= -1))
			{
				ft_putchar(str, len, strutt);
				ft_space_nbr(strutt->width - len, strutt);
				return ;
			}
		if (strutt->precision < len && strutt->precision != -1)
			{
				ft_putchar(str, strutt->precision, strutt);
				ft_space_nbr(strutt->width - strutt->precision, strutt);
				return ;
			}
	}

	if(strutt->precision == -1)
		{
			ft_space_nbr(strutt->width, strutt);
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
	}
	if (strutt->flag_minus == 1)
	{
		ft_putchar(&c, 1, strutt);
		ft_space_str(len, strutt);
	}
}

void	ft_xu(t_strutt *strutt, va_list ap, char *base)
{
	char			*str;
	unsigned int	n;
	int				len;

	n = va_arg(ap, unsigned int);
	len = ft_size_nbr_uns_diffbase(n, base);
	str = ft_itoa_base(n, len, base);
	if (n == 0 && ft_num_is_zero(strutt))
		return ;
	if (strutt->flag_minus == 0 && ft_zero_rather_space_sdxu(str, len, strutt))
		return ;
	ft_print_dxu(str, len, strutt);
}

void	ft_p(t_strutt *strutt, va_list ap)
{
	char 				*str;
	unsigned long long	n;
	int					len;

	if ((n = va_arg(ap, unsigned long long)) == (unsigned long long)NULL)
		n = 0;
	len = ft_size_nbr_uns_diffbase(n, BASE16);
	str = ft_itoa_base(n, len, BASE16);
	strutt->width = strutt->width - 2;
	if (n == 0 && strutt->dot == 1 && (strutt->precision == 0 || strutt->precision == -1))
	{
		ft_num_is_null(strutt, ap);
		return ;
	}
	if (strutt->flag_minus == 0 && ft_zero_rather_space_p(str, len, strutt))
		return ;
	ft_print_p(str, len, strutt);
}
