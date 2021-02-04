/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:12:12 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/04 12:51:18 by aviolini         ###   ########.fr       */
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
		ft_d(strutt, str, i, ap);
/*	if (strutt->type == 'c')
		ft_c(strutt, str, i, ap);
	if (strutt->type == 's')
		ft_s(strutt, str, i, ap);
	if (strutt->type == 'x')
		ft_x(strutt, str, i, ap);
	if (strutt->type == 'p')
		ft_p(strutt, str, i, ap);
*/		//MANCA ft_X
}

void	ft_d(t_strutt *strutt, const char *str, int i, va_list ap)
{
	int len;
	int num;
	int x;
	int z;
	int y;

	y = 0;
	z = 0;
	num = va_arg(ap, int);
	len = ft_size_number(num);
	
}
