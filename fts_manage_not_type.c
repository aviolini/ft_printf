/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_manage_not_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 23:15:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/09 16:06:09 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_perc(t_strutt *strutt, va_list ap)
{
	(void)strutt;
	(void)ap;
	ft_putchar("%", 1, strutt);
	//strutt->prev_was_perc = 1;
}

void	ft_not_type(t_strutt *strutt, const char *str, int i, va_list ap)
{
	(void)strutt;
	(void)ap;
	int x;

	x = 0;
	while (str[i--] != '%')
		x++;
	while (x-- >= 0)
	{
		write(1, &str[++i], 1);
		strutt->total_chars++;
	}

}

void	ft_num_is_zero(t_strutt *strutt, va_list ap)
{
//		int len;
//		char *str;
		(void)ap;
		int x;

	//	strutt->width = strutt->width + 1;
	x = 0;
	//printstrutt(strutt);
		strutt->num_is_zero = 1;
//		str = "0";
//		len = 1;
		if (strutt->width && strutt->precision <= 0)
			while (x++ < strutt->width)
				ft_putchar(" ",1, strutt);

}
