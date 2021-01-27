# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburton <rburton@student.21-schoo>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 16:51:43 by mspinnet          #+#    #+#              #
#    Updated: 2020/10/07 21:42:09 by mspinnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(shell find . -name '*.c')

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

GCC		= gcc

CFLAGS	= -Wall -Wextra -Werror -Isrcs

RM		= rm -f

ARRC	= ar rc

FT_H	= libft.h

LIB		= libft.a

all:	${NAME}

bonus:	all

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${ARRC} ${LIB} ${OBJS}
		${ARRC} ${LIB} ${FT_H}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} ${LIB}

re:		fclean all
