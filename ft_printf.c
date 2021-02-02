/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:42:19 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/02 18:47:43 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	int			t;
	int			i;
	va_list		ap;
	t_struct	*struct;

	i = 0;
	va_start(ap,str);
	while (str[i])
		{

			if (str[i] == '%' && str[i + 1] != '%' && str[i - 1] != '%')
			{
				struct = (t_struct *)malloc(sizeof(t_struct));
				ft_init_struct(struct);
				ft_typearg(struct, str,i + 1, ap);
				free(struct);
			//	i = i + 1;
			}
			else
				write(1,&str[i],1);
			i++;
		}
	va_end(ap);
	return (0);
}

void	ft_typearg(t_struct *struct, char *s, int i, va_list ap)
{
	int		x;
	char	*txt;
	int		z;

	if (str[i] == '-')
	{
		struct->flag_minus = 1;
		i++;
	}
	if (str[i] == '0')
	{
		struct->flag_zero = 1;
		i++;
	}
	if (str[i] == )    ///vedere se lo 0 sta prima del -

	return NULL;
}
