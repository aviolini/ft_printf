/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:12:12 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/05 11:56:53 by aviolini         ###   ########.fr       */
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
	if (strutt->type == 'x')
		ft_xXu(strutt, ap, BASE16);
	if (strutt->type == 'X')
		ft_xXu(strutt, ap, BASE16X);
	if (strutt->type == 'u')
		ft_xXu(strutt, ap , BASE10);
	if (strutt->type == 'p')
		ft_p(strutt, ap);
}
