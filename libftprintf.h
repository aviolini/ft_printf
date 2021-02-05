/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:28:03 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/05 14:38:01 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define BASE16 "0123456789abcdef"
# define BASE16X "0123456789ABCDEF"
# define BASE10 "0123456789"
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
void		ft_putmax(char *str);
int			ft_check_num_arg(va_list ap, int n);
void		ft_init_strutt(t_strutt *strutt);
void		ft_printstrutt(t_strutt *strutt);
void		ft_use_strutt(t_strutt *strutt, const char *str,
	int i, va_list ap);
void		ft_d(t_strutt *strutt, va_list ap);
void		ft_c(t_strutt *strutt, va_list ap);
void		ft_s(t_strutt *strutt, va_list ap);
void		ft_xXu(t_strutt *strutt, va_list ap, char *base);
void		ft_p(t_strutt *strutt, va_list ap);
void		ft_space(int len, int width, int precision);
void		ft_zero(int len, int width, int precision);
void		ft_space_str(int len, int width, int precision);
void		ft_putstr(char *str, int len, int width, int precision);
char		*ft_itoa_base(size_t n, int len, char *base);
int			ft_size_number_uns_diffbase(size_t n, char *base);
char		*ft_add_0x(char *str);
#endif

/*
CONTROLLARE CHAR * E CONST CHAR *
CONTROLLARE SE IL TYPE ARG E DIVERSO DA QUELLI DA SUBJECT
IL MALLOC FUORI DAL CICLO? ANCHE FT_INIT_STRUTT
RETURN INCREMENTATO DEGLI ARGOMENTI
TOGLIERE AP E ALTRI ARGOMENTI DOVE NON SERVONO
WIDTH NUMERO FORSE > 0 INVECE CHE = 0
FREE MALLOC ITOA, CASO LIMITE ITOA
NON FUNZIONA CON UN PERCENTUALE APPENA FINTIO IL TYPE ARG PRECEDENTE ES: ft_printf("my   - %07.7d%*.*d\n",56789,7,7,56789);
se e' = u
SU FT_SPACE E ALTRE FARE TEST E OTTIMIZZARE LE CONDIZIONI
FUNZIONE TYPEARG INUTILE?
CASO:(BISOGNA AUMENTARE LA PRECISION DI 1 IN FT_SPACE FLAG_MINUS 0)
	ft_printf("m%10.5d\n",-555);
	printf("o%10.5d\n",-555);
STANDARDIZZARE SPACE
TYPE_D CON ITOA
SI PUO USARE LÍTOA BASE ANCHE PER GLI INT VISTO CHE BISOGNA GESTIRLI SOLO POSTITIVI
*/
