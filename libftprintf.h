/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:28:03 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/07 11:40:53 by aviolini         ###   ########.fr       */
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
	int 	total_chars;
	int		prev_was_perc;
	char 	type;
} 			t_strutt;

int			ft_printf(const char *str, ...);
int			ft_strlen(char *str);
int			ft_numarg(char *str);
char		*ft_itoa(int n);
int 		ft_size_nbr(int n);
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
void		ft_putnbr(int n, t_strutt *strutt);
void		ft_putmax(char *str);
int			ft_check_num_arg(va_list ap, int n);
void		ft_init_strutt(t_strutt *strutt);
void		ft_printstrutt(t_strutt *strutt);
void		ft_use_strutt(t_strutt *strutt, const char *str, int i, va_list ap);
void		ft_d(t_strutt *strutt, va_list ap);
void		ft_c(t_strutt *strutt, va_list ap);
void		ft_s(t_strutt *strutt, va_list ap);
void		ft_xXu(t_strutt *strutt, va_list ap, char *base);
void		ft_p(t_strutt *strutt, va_list ap);
void		ft_perc(t_strutt *strutt, va_list ap);
void		ft_not_type(t_strutt *strutt,const char *str, int i, va_list ap);
void		ft_space_nbr(int len, t_strutt *strutt);
void		ft_zero_nbr(int len, t_strutt *strutt);
void		ft_space_str(int len, t_strutt *strutt);
void		ft_putstr(char *str, int len, t_strutt *strutt);
char		*ft_itoa_base(size_t n, int len, char *base);
int			ft_size_nbr_uns_diffbase(size_t n, char *base);
void		ft_putchar(char *str, int size, t_strutt *strutt);
#endif

/*
WIDTH NUMERO FORSE > 0 INVECE CHE = 0
FREE MALLOC ITOA, CASO LIMITE ITOA
SU FT_SPACE E ALTRE FARE TEST E OTTIMIZZARE LE CONDIZIONI
STANDARDIZZARE SPACE
TYPE_D CON ITOA
SI PUO USARE L'ÍTOA BASE ANCHE PER GLI INT VISTO CHE BISOGNA GESTIRLI SOLO POSTITIVI
CASO LIMITE INT
STRLEN CON \0?
TOGLIERE VARI RETURN IN FT_MANAGE_TYPE?
TOGLIERE EVENUTALI (VOID)VARIABILE CHE NON SERVONO?
TOGLIERE FUNZIONI IN .h CHE NON SERVONO
I FREE NELLE FUNZIONI MANAGE_TYPE
TOGLIERE IL PRINT STRUTT
CASO:
ret = printf("or - %10.7%%d\n",str1);
ret2 = ft_printf("my - %-10.7%%d\n",str1);

*/
