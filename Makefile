# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 13:28:51 by rbulanad          #+#    #+#              #
#    Updated: 2023/03/15 12:57:43 by rbulanad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SOURCES		= ft_atol.c \
			  ft_split.c \
			  ft_strjoin.c \
			  instructions.c \
			  instructions2.c \
			  parsing.c \
			  push_swap.c \
			  sorting.c \
			  sorting2.c \
			  sorting3.c \
			  stacks.c \
			  stacks2.c 
OBJECTS		= ${SOURCES:.c=.o}
RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
