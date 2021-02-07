/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:05:38 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/07 01:45:59 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char *str, int size, t_strutt *strutt)
{
	write(1, str, size);
	strutt->total_chars = strutt->total_chars + size;
}
int		ft_strlen(char *str)
{
	int i;
	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_putnbr(int n, t_strutt *strutt)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putmax("2147483648");
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchar("-", 1, strutt);
		//write(1, "-", 1);
	}
	if (n < 10)
	{
		c = n + '0';
		ft_putchar(&c, 1, strutt);
		//write(1, &c, 1);
		return ;
	}
	ft_putnbr(n / 10, strutt);
	ft_putnbr(n % 10, strutt);
}
void	ft_putmax(char *str)
{
	size_t i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i--);
}
