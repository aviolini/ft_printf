/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:42:19 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/07 01:13:06 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	int			ret;
	int			i;
	va_list		ap;
	t_strutt	*strutt;

	i = 0;
	ret = 0;
	va_start(ap,str);
	strutt = (t_strutt *)malloc(sizeof(t_strutt));
	while (str[i])
		{
			if (str[i] == '%' && str[i + 1] == '%')
				i = i + 1;
			if (str[i] == '%' && str[i + 1] != '%' && str[i - 1] != '%')
			{
				//strutt = (t_strutt *)malloc(sizeof(t_strutt));
				i = ft_fill_strutt(strutt, str, i, ap);
				ft_use_strutt(strutt, str, i, ap);
				ret = ret + strutt->total_chars;
				//i++;
			}
			else
			{
				write(1,&str[i],1);
				ret++;
			}

			i++;
		}
	//ft_printstrutt(strutt);
	free(strutt);
	va_end(ap);
	return (ret);
}

int		ft_fill_strutt(t_strutt *strutt, const char *str, int i, va_list ap)
{
	ft_init_strutt(strutt);
	i = ft_typeflag(strutt, str, i + 1, ap);
	i = ft_typewidth(strutt, str, i, ap);
	i = ft_typeprecision(strutt, str, i,ap);
	strutt->type = ft_typearg(strutt, str, i, ap);
	return (i);
}

void	ft_init_strutt(t_strutt *strutt)
{
	strutt->flag_minus = 0;
	strutt->flag_zero = 0;
	strutt->width = 0;
	strutt->dot = 0;
	strutt->precision = -1;
	strutt->total_chars = 0;
	strutt->type = 0;
}

void	ft_use_strutt(t_strutt *strutt,const char *str, int i, va_list ap)
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
	if (strutt->type == '%')
		ft_perc(strutt, ap);
	if (strutt->type == 0)
		ft_not_type(strutt, str, i, ap);

}






void	ft_printstrutt(t_strutt	*strutt)
{
	printf("------strutt--------\n");
	printf("strutt->flagminus : %i\n", strutt->flag_minus);
	printf("strutt->flag_zero : %i\n", strutt->flag_zero);
	printf("strutt->width : %i\n", strutt->width);
	printf("strutt->dot : %i\n", strutt->dot);
	printf("strutt->precision : %i\n", strutt->precision);
	printf("strutt->total_chars : %i\n", strutt->total_chars);
	printf("type : %c\n", strutt->type);
	printf("------------------------\n");
}
