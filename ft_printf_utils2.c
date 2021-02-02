/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:22:52 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/02 17:12:32 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_num_arg(va_list ap, int n)
{
	int i;

	i = 0;
	while (va_arg(ap, void *) != 0)
		i++;
	va_end(ap);
	if (i != n)
		return (0);
	return (1);
}

int		ft_check_value_arg(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%' && str[i - 1] != '%')
		//	if(str[i] )
		i++;
	}
	return (ret);
}

int		ft_numarg(char *str)
{
	int i;
	int numarg;

	i = 0;
	numarg = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%' && str[i - 1] != '%')
			numarg++;
		i++;
	}
	return (numarg);
}
