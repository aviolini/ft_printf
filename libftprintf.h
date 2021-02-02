/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:28:03 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/02 17:11:02 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(char *str);
int		ft_numarg(char *str);
char	*ft_typearg(char c, va_list ap);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		ft_check_num_arg(va_list ap, int n);
int		ft_check_value_arg(char *str);

#endif
