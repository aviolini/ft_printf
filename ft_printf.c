/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:42:19 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/03 15:50:48 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	int			ret;
	int			i;
	va_list		ap;
	t_strutt	*strutt;
	char			type_arg;

	i = 0;
	ret = 0;
	va_start(ap,str);
	while (str[i])
		{
			if (str[i] == '%' && str[i + 1] != '%' && str[i - 1] != '%')
			{
				strutt = (t_strutt *)malloc(sizeof(t_strutt));
				ft_init_strutt(strutt);
				i = ft_typeflag(strutt, str, i + 1, ap);
				i = ft_typewidth(strutt, str, i, ap);
				i = ft_typeprecision(strutt,str, i,ap);
				strutt->type = ft_typearg(strutt,str, i, ap);
				i++;
			}
			else if (str[i] == '%' && str[i + 1] == '%')
				i = i + 1;
			write(1,&str[i],1);
			ret++;
			i++;
		}
	ft_printstrutt(strutt);
	va_end(ap);
	return (ret);
}

void	ft_printstrutt(t_strutt	*strutt)
{
	printf("------strutt--------\n");
	printf("strutt->flagminus : %i\n", strutt->flag_minus);
	printf("strutt->flag_zero : %i\n", strutt->flag_zero);
	printf("strutt->width : %i\n", strutt->width);
	printf("strutt->dot : %i\n", strutt->dot);
	printf("strutt->precision : %i\n", strutt->precision);
	printf("strutt->flag_pre_va : %i\n", strutt->flag_pre_va);
	printf("strutt->num_m : %i\n", strutt->num_m);
	printf("type : %c\n", strutt->type);
	printf("------------------------\n");
}
