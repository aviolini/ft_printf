/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_manage_not_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 23:15:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/11 12:15:34 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_perc(t_strutt *strutt)
{
	if (strutt->flag_minus == 0)
	{
		if (strutt->flag_zero)
		{
			ft_zero(strutt->width - 1, strutt);
			ft_putchar("%", 1, strutt);
			return ;
		}
		ft_space(strutt->width - 1, strutt);
		ft_putchar("%", 1, strutt);
	}
	if (strutt->flag_minus == 1)
	{
		ft_putchar("%", 1, strutt);
		ft_space(strutt->width - 1, strutt);
	}
}
