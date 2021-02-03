/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:28:03 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/03 13:36:29 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_option
{
	int 	flag_minus;
	int 	flag_zero;
	int 	width;
	int 	dot;
	int 	precision;
	int 	flag_pre_va;
	int 	num_m;
	int 	type;
} 			t_strutt;

int			ft_printf(const char *str, ...);
int			ft_strlen(char *str);
int			ft_numarg(char *str);
int			ft_typeflag(t_strutt *strutt, const char *str,
	int i, va_list ap);
int			ft_typearg(t_strutt *strutt, const char *str,
	int i, va_list ap);
int			ft_typewidthprec(t_strutt *strutt, const char *str,
	int i, va_list ap);
void		ft_putnbr(int n);
void		ft_putstr(char *str);
int			ft_check_num_arg(va_list ap, int n);
void		ft_init_strutt(t_strutt *strutt);
void		ft_printstrutt(t_strutt *strutt);



#endif
