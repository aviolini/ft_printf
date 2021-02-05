# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 15:49:37 by aviolini          #+#    #+#              #
#    Updated: 2021/02/05 16:10:20 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			libftprintf.a

SRCS			=			ft_printf.c \
							ft_printf_utils0.c \
							ft_printf_utils1.c \
							ft_printf_utils2.c \
							ft_printf_utils3.c \
							ft_printf_utils4.c \
							ft_printf_utils5.c

OBJS			=			$(SRCS:.c=.o)

CC				=			gcc

CFLAGS			=			-Wall -Wextra -Werror

RM				=			rm -f

.c.o			:
							$(CC) $(CFLAGS) -c $<

$(NAME)			:			$(OBJS)
							ar rc $(NAME) $(OBJS)

all				:			$(NAME)

clean			:
							$(RM) $(OBJS)

fclean			:			clean
							$(RM) $(NAME)

re				:			fclean all

.PHONY			:			all clean fclean re
