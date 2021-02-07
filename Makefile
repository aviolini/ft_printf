# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 15:49:37 by aviolini          #+#    #+#              #
#    Updated: 2021/02/07 01:28:11 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			libftprintf.a

SRCS			=			ft_printf.c \
							fts_fill_strutt.c \
							fts_manage_type.c \
							fts_manage_not_type.c \
							fts_utils.c \
							fts_utils2.c \
							fts_itoa.c

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
