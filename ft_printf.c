/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:42:19 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/11 12:54:48 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	int			i;
	va_list		ap;
	t_strutt	*strutt;

	i = 0;
	va_start(ap,str);
	strutt = (t_strutt *)malloc(sizeof(t_strutt));
		strutt->total_chars = 0;
	while (str[i])
		{
			if (str[i] == '%' && str[i + 1] == '%')
			{
				ft_putchar((char *)&(str[i]),1, strutt);
				i = i + 1;
				strutt->prev_was_perc = 1;
			}
		 	else if (str[i] == '%' && str[i + 1] != '%' && (str[i - 1] != '%'
			|| strutt->prev_was_perc == 1))
			{
				if ((i = ft_fill_strutt(strutt, str, i, ap)) == 0)
					break;
				ft_use_strutt(strutt, str, i, ap);
			}
			else
				ft_putchar((char *)&(str[i]),1, strutt);
			i++;
		}
	i = strutt->total_chars;
	free(strutt);
	va_end(ap);
	return (i);
}

int		ft_fill_strutt(t_strutt *strutt, const char *str, int i, va_list ap)
{
	ft_init_strutt(strutt);
	i = ft_typeflag(strutt, str, i + 1, ap);
	i = ft_typewidth(strutt, str, i, ap);
	i = ft_typeprecision(strutt, str, i,ap);
	if ((strutt->type = ft_typearg(strutt, str, i, ap)) == 0)
		return 0;

	return (i);
}

void	ft_init_strutt(t_strutt *strutt)
{
	strutt->flag_minus = 0;
	strutt->flag_zero = 0;
	strutt->width = 0;
	strutt->dot = 0;
	strutt->precision = -1;
	//strutt->total_chars = 0;
	strutt->num_is_zero = 0;
	strutt->num_is_neg = 0;
	strutt->prec_is_arg = 0;
	strutt->prev_was_perc = 0;
	strutt->type = 0;
}

void	ft_use_strutt(t_strutt *strutt,const char *str, int i, va_list ap)
{
	(void)str;
	(void)i;
	if (strutt->type == 0)
		//ft_not_type(strutt, str, i, ap);
		return ;
	if (strutt->type == 'd')
		ft_d(strutt, ap);
	if (strutt->type == 'c')
		ft_c(strutt, ap);
	if (strutt->type == 's')
		ft_s(strutt, ap);
	if (strutt->type == 'x')
		ft_xu(strutt, ap, BASE16);
	if (strutt->type == 'X')
		ft_xu(strutt, ap, BASE16X);
	if (strutt->type == 'u')
		ft_xu(strutt, ap , BASE10);
	if (strutt->type == 'p')
		ft_p(strutt, ap);
	if (strutt->type == '%')
		ft_perc(strutt);


}
