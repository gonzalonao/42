# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 17:23:27 by glopez-c          #+#    #+#              #
#    Updated: 2024/05/07 21:15:39 by glopez-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs

RM = rm -f

SRCS = main.c radix.c sort_5.c ft_split.c\
	 str_utils.c memory_utils.c arg_checks.c\
	 init_stacks.c	moves_utils.c stack_utils.c\
	 swap.c push.c rotate.c reverse_rotate.c
	 

OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

%.o: %.c push_swap.h
	${CC} ${CCFLAGS} -I. -g -c $< -o ${<:.c=.o}

all:  ${NAME}

$(NAME): ${OBJS} push_swap.h
	@${CC} ${OBJS} -o ${NAME}

clean: 
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
