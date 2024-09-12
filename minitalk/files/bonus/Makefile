# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 20:01:25 by glopez-c          #+#    #+#              #
#    Updated: 2024/08/08 18:10:44 by glopez-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server

LIBFT = ./libft

SRC_C = client.c
SRC_S = server.c
OBJS_C = ${SRC_C:.c=.o}
OBJS_S= ${SRC_S:.c=.o}

CC = gcc
FLAGS = -Wall -Werror -Wextra

%.o: %.c minitalk.h
	@${CC} ${FLAGS} -I. -c $< -o ${<:.c=.o}

all: ${NAME_C} ${NAME_S}

libft:
	@make re -C $(LIBFT)

$(NAME_C): ${OBJS_C} libft
	@${CC} ${OBJS_C} -o ${NAME_C} -L$(LIBFT) -lft

$(NAME_S): ${OBJS_S} libft
	@${CC} ${OBJS_S} -o ${NAME_S} -L$(LIBFT) -lft 

clean: 
	@make fclean -C $(LIBFT)
	@rm -f ${OBJS_C} ${OBJS_S}

fclean: clean
	@rm -f ${NAME_C} ${NAME_S}

re: fclean all

.PHONY: all clean libft fclean re
