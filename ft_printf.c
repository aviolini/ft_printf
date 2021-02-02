/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:42:19 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/02 16:56:54 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	int		t;
	int		i;
	va_list	ap;
//	int		x;

	i = 0;
	t = ft_numarg((char *)str);
	va_start(ap, str);
	if (ft_check_num_arg(ap, t) == 0)
		return (printf("errore_argomenti\n"));
//	ap = NULL;
	va_start(ap,str);
	while (str[i])
		{

			if (str[i] == '%' && str[i + 1] != '%' && str[i - 1] != '%')
			{
				ft_typearg(str[i + 1], ap);
				i = i + 1;
			}
			else
				write(1,&str[i],1);
			i++;
		}
	va_end(ap);
	return (0);
}

char	*ft_typearg(char c, va_list ap)
{
	int		x;
	char	*txt;
	int		z;

	if (c == 's')
	{
		txt = va_arg(ap, char *);
		z = ft_strlen(txt);
		write(1, txt, z);
	}
	if (c == 'd')
	{
		x = va_arg(ap, int);
		(ft_putnbr(x));
	}
	return NULL;
}
