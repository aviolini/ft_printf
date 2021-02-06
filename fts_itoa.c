/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:46:49 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/07 00:37:24 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_size_nbr(int n)
{
	int i;

	i = 0;
	if ( n == 0)
		i++;
	if (n < 0)
		{
			n = n * -1;
			i++;
		}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char *str;
	int i;
	int len;

	len = ft_size_nbr(n);
	str = (char *)malloc(sizeof(char) * len);
	i = -1;
	if (n < 0)
	{
		n = n * - 1;
		str[0] = '-';
		i++;
	}
	while (--len > i)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}

int		ft_size_nbr_uns_diffbase(size_t n, char *base)
{
	int i;
	int x;

	x = ft_strlen(base);
	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / x;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(size_t n, int len, char *base)
{
	char	*str;
	int		x;
	int		size_base;

	size_base = ft_strlen(base);
	x = 0;
	str = (char *)malloc(sizeof(char) * len);
	while(len-- >= x)
	{
		str[len] = base[(n % size_base)];
		n = n / size_base;
	}
	return (str);
}
