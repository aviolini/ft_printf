/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:23:57 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/08 18:33:49 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_space_nbr(int len, t_strutt *strutt)
{
	int x;
	int y;

	x = 0;
	y = 0;
		if (strutt->width > len)
			y = strutt->width - strutt->precision;
		if (strutt->precision <= len)
			y = strutt->width - len;

		while (x++ < y)
			ft_putchar(" ", 1, strutt);
}

void	ft_zero_nbr(int len, t_strutt *strutt)
{
	int x;

	x = 0;
	//ft_printstrutt(strutt);
//	printf("len ; %d\n",len);
	if (strutt->precision > len)
		while (x++ < strutt->precision - len)
			ft_putchar("0", 1, strutt);

	if (strutt->flag_zero == 1 && strutt->flag_minus == 0 && strutt->precision != 0)
		while(x++ < strutt->width - len)
			//{
				ft_putchar("0", 1, strutt);
			//	x++;
			//}
}

void	ft_putnbr_str(char *str, t_strutt *strutt)
{
	(void)str;
	(void)strutt;
	//int i;

//	i = 0;

}

void	ft_space_str(int len, t_strutt *strutt)
{
	int x;
	int y;

	x = 0;
	if (strutt->precision <= len)
		y = strutt->width - strutt->precision;
	if (strutt->precision > len || strutt->precision == -1)
		y = strutt->width - len;
	if (len == -1)
		y = strutt->width - 1;
	while (x++ < y)
		ft_putchar(" ", 1, strutt);
}

void	ft_putstr(char *str, int len, t_strutt *strutt)
{
	if (strutt->precision <= len)
		ft_putchar(str, strutt->precision, strutt);
		//write(1, str, strutt->precision);
	if (strutt->precision > len || strutt->precision == -1)
		ft_putchar(str, len, strutt);
		//write(1, str, len);
}
