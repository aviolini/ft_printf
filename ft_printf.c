/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:42:19 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/03 13:45:22 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
//	int			index;
	int			i;
	va_list		ap;
	t_strutt	*strutt;
	int			type_arg;

	i = 0;
	va_start(ap,str);
	while (str[i])
		{

			if (str[i] == '%' && str[i + 1] != '%' && str[i - 1] != '%')
			{
				strutt = (t_strutt *)malloc(sizeof(t_strutt));
			//	strutt = NULL;
				ft_init_strutt(strutt);
				ft_printstrutt(strutt);
				i = ft_typeflag(strutt, str, i + 1, ap);
				//printf("i: %d\n", i);
				i = ft_typewidthprec(strutt, str, i, ap);
				ft_printstrutt(strutt);
				type_arg = ft_typearg(strutt,str, i, ap);
				//if (type_arg != 0)
					//
				ft_printstrutt(strutt);
				printf("type_arg:%i\n",type_arg);
				i = i + 1;
			}
			else if (str[i] == '%' && str[i + 1] == '%')
				i = i + 1;
			write(1,&str[i],1);
			i++;
		}
	va_end(ap);
	return (0);
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
	printf("type : %i\n", strutt->type);
	printf("------------------------\n");
}
