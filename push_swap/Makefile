# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 17:23:27 by glopez-c          #+#    #+#              #
#    Updated: 2024/04/22 17:29:01 by glopez-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs

RM = rm -f

SRCS = moves.c main.c radix.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

%.o: %.c push_swap.h
	${CC} ${CCFLAGS} -I. -c $< -o ${<:.c=.o}

all:  ${NAME}

$(NAME): ${OBJS} push_swap.h
	@${CC} ${OBJS} -o ${NAME}

clean: 
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
