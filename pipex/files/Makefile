# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 13:54:05 by glopez-c          #+#    #+#              #
#    Updated: 2024/02/06 16:40:24 by glopez-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
#NAME_B = pipex_bonus

SRC = pipex.c utils.c
OBJS = ${SRC:.c=.o}
MAIN = pipex.c

#SRCS_B = pipex_bonus.c pipex_utils.c
#OBJS_B = ${SRCS_B:.c=.o}
#MAIN_B = pipex_bonus.c

CC = gcc
FLAGS = -Wall -Werror -Wextra -g

%.o: %.c pipex.h
	@${CC} ${FLAGS} -I. -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	@make re -C ./libft
	@${CC} -g -L./libft -lft ${OBJS} -ggdb3 -o ${NAME}

#$(NAME_B): ${OBJS_B}
#	@make re -C ./libft
#	@${CC} ${OBJS_B} -Llibft -lft -o ${NAME_B}

#bonus: ${NAME_B}
#	@make re -C ./libft
#	@${CC} ${OBJS_B} -Llibft -lft -o ${NAME_B}

clean: 
	@make clean -C ./libft
	@rm -f ${OBJS}# ${OBJS_B}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME}# ${NAME_B}

re: fclean all

#re_bonus: fclean bonus

.PHONY: all clean fclean re #re_bonus bonus
