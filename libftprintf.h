/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:28:03 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/04 08:37:05 by aviolini         ###   ########.fr       */
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
	char 	type;
} 			t_strutt;

int			ft_printf(const char *str, ...);
int			ft_strlen(char *str);
int			ft_numarg(char *str);
char		*ft_itoa(int n);
int 		ft_size_number(int n);
int			ft_typeflag(t_strutt *strutt, const char *str,
	int i, va_list ap);
char		ft_typearg(t_strutt *strutt, const char *str,
	int i, va_list ap);
int			ft_typeprecision(t_strutt *strutt, const char *str,
	int i, va_list ap);
int			ft_typewidth(t_strutt *strutt, const char *str,
	int i, va_list ap);
int			ft_fill_strutt(t_strutt *strutt, const char *str,
		int i, va_list ap);
void		ft_putnbr(int n);
void		ft_putstr(char *str);
int			ft_check_num_arg(va_list ap, int n);
void		ft_init_strutt(t_strutt *strutt);
void		ft_printstrutt(t_strutt *strutt);



#endif

/*
CONTROLLARE CHAR * E CONST CHAR *
CONTROLLARE SE IL TYPE ARG E DIVERSO DA QUELLI DA SUBJECT
IL MALLOC FUORI DAL CICLO? ANCHE FT_INIT_STRUTT
RETURN INCREMENTATO DEGLI ARGOMENTI
TOGLIERE AP E ALTRI ARGOMENTI DOVE NON SERVONO
WIDTH NUMERO FORSE > 0 INVECE CHE = 0
FREE MALLOC ITOA, CASO LIMITE ITOA
*/
