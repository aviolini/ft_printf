/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_manage_not_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 23:15:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/10 14:25:42 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

void	ft_perc(t_strutt *strutt, va_list ap)
{
	(void)strutt;
	(void)ap;

	if(strutt->flag_minus == 0)
	{
		if(strutt->flag_zero)
			{
				ft_zero_nbr(strutt->width - 1, strutt);
				ft_putchar("%", 1, strutt);
				return ;

			}
		ft_space_nbr(strutt->width - 1, strutt);
		ft_putchar("%", 1, strutt);
	}
	if(strutt->flag_minus == 1)
	{
		ft_putchar("%", 1, strutt);
		ft_space_nbr(strutt->width - 1, strutt);
	}


	//strutt->prev_was_perc = 1;
}

void	ft_not_type(t_strutt *strutt, const char *str, int i, va_list ap)
{
	(void)strutt;
	(void)ap;
	int x;

	x = 0;
	while (str[i--] != '%')
		x++;
	while (x-- >= 0)
	{
		write(1, &str[++i], 1);
		strutt->total_chars++;
	}

}

void	ft_num_is_zero(t_strutt *strutt, va_list ap)
{
	(void)ap;
	int x;

	x = 0;
	strutt->num_is_zero = 1;

	if(!strutt->width && strutt->prec_is_arg)
	{
		ft_putchar("0", 1, strutt);
		return ;
	}
	if(strutt->width > 0 && strutt->prec_is_arg)
	{
		if (strutt->flag_minus == 0)
		{
			if(strutt->flag_zero)
			{
				while(x++ < strutt->width)
					ft_putchar("0", 1, strutt);
			}
			else
			{
				while(x++ < strutt->width - 1)
					ft_putchar(" ", 1, strutt);
				ft_putchar("0", 1, strutt);
			}
		}
		if(strutt->flag_minus == 1)
		{
			ft_putchar("0", 1, strutt);
			while(x++ < strutt->width - 1)
				ft_putchar(" ", 1, strutt);

		}
		return ;
	}
	if(strutt->width > 0 && (strutt->precision == -1 || strutt->precision == 0))
		{
			while(x++ < strutt->width)
				ft_putchar(" ", 1, strutt);
			return ;
		}

}

void	ft_num_is_null(t_strutt *strutt, va_list ap)
{
	(void)ap;
	int x;

	x = 0;
	strutt->num_is_zero = 1;

	if(!strutt->width)//&& strutt->prec_is_arg)
	{

		ft_putchar("0x", 2, strutt);
		return ;
	}
	if(strutt->width > 0 && (strutt->precision == -1 || strutt->precision == 0))
		{
			while(x++ < strutt->width)
				ft_putchar(" ", 1, strutt);
			ft_putchar("0x", 2, strutt);
			return ;
		}
	if (strutt->width > 2)
		strutt->width = strutt->width - 2;
	if(strutt->width > 0 && strutt->prec_is_arg)
	{
		if (strutt->flag_minus == 0)
		{
			if(strutt->flag_zero)
			{
				ft_putchar("0x", 2, strutt);
				while(x++ < strutt->width)
					ft_putchar("0", 2, strutt);
			}
			else
			{
				while(x++ < strutt->width)
					ft_putchar(" ", 1, strutt);
				ft_putchar("0x", 2, strutt);
			}
		}
		if(strutt->flag_minus == 1)
		{
			ft_putchar("0x", 2, strutt);
			while(x++ < strutt->width)
				ft_putchar(" ", 1, strutt);

		}

		return ;
	}
	ft_putchar("0x", 2, strutt);

}
