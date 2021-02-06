/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_manage_not_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 23:15:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/06 23:52:57 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_perc(t_strutt *strutt, va_list ap)
{
	write (1, "%", 1);
}

void	ft_not_type(t_strutt *strutt, const char *str, int i, va_list ap)
{
	int x;

	x = 0;
	while (str[i--] != '%')
		x++;
	while (x-- >= 0)
		write(1, &str[++i], 1);


}
