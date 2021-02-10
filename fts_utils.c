/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:23:57 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/10 15:54:06 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_space_nbr(int y, t_strutt *strutt)
{
	int i;

	i = 0;
	while (i++ < y)
		ft_putchar(" ", 1, strutt);
}

void	ft_zero_nbr(int x, t_strutt *strutt)
{
	int i;

	i = 0;
		while (i++ < x)
			ft_putchar("0", 1, strutt);

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
