/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:28:03 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/02 18:45:48 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_option
{
	int 	flag_minus;
	int 	flag_zero;
	int 	width;
	int 	dot;
	int 	precision;
	int 	flag_pre_va;
	int 	num_m;
	char 	type;
} 			t_struct;

int			ft_printf(const char *str, ...);
int			ft_strlen(char *str);
int			ft_numarg(char *str);
void		ft_typearg(t_struct *struct,char *s, int c, va_list ap);
void		ft_putnbr(int n);
void		ft_putstr(char *s);
int			ft_check_num_arg(va_list ap, int n);
void		ft_init_struct(t_struct *struct);

#endif
