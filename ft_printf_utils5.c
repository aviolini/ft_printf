/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:46:49 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/05 15:08:30 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_size_number_uns_diffbase(size_t n, char *base)
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
