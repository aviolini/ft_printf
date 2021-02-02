/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:15:37 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/02 18:28:06 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_struct(t_struct *struct)
{
	struct->flag_minus = 0;
	struct->flag_zero = 0;
	struct->width = 0;
	struct->dot = 0;
	struct->precision = -1;   // initially set as -1 instead of 0
	struct->flag_pre_va = 0; // if precision is a variable argument
	struct->num_m = 0;	     // is number negative?
	struct->type = 0;
}
