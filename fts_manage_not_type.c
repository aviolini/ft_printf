/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_manage_not_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 23:15:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/11 11:43:03 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_perc(t_strutt *strutt)
{
	if (strutt->flag_minus == 0)
	{
		if (strutt->flag_zero)
		{
			ft_zero_nbr(strutt->width - 1, strutt);
			ft_putchar("%", 1, strutt);
			return ;
		}
		ft_space_nbr(strutt->width - 1, strutt);
		ft_putchar("%", 1, strutt);
	}
	if (strutt->flag_minus == 1)
	{
		ft_putchar("%", 1, strutt);
		ft_space_nbr(strutt->width - 1, strutt);
	}
}

void	ft_num_is_null(t_strutt *strutt, va_list ap)
{
	(void)ap;
	int x;

	x = 0;
	strutt->num_is_zero = 1;

	if(!strutt->width)
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
	ft_putchar("0x", 2, strutt);
}
