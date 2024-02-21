# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 20:01:25 by glopez-c          #+#    #+#              #
#    Updated: 2024/02/07 13:01:30 by glopez-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server
#NAME_B = pipex_bonus

SRC_C = client.c
SRC_S = server.c
OBJS_C = ${SRC_C:.c=.o}
OBJS_S= ${SRC_S:.c=.o}

#SRCS_B = pipex_bonus.c pipex_utils.c
#OBJS_B = ${SRCS_B:.c=.o}
#MAIN_B = pipex_bonus.c

CC = gcc
FLAGS = -Wall -Werror -Wextra

%.o: %.c minitalk.h
	@${CC} ${FLAGS} -I. -c $< -o ${<:.c=.o}

all: ${NAME_C} ${NAME_S}

$(NAME_C): ${OBJS_C}
	@make re -C ./libft
	@${CC} -fsanitize=address -L./libft -lft ${OBJS_C} -o ${NAME_C}

$(NAME_S): ${OBJS_S}
	@make re -C ./libft
	@${CC} -fsanitize=address -L./libft -lft ${OBJS_S} -o ${NAME_S}

#$(NAME_B): ${OBJS_B}
#	@make re -C ./libft
#	@${CC} ${OBJS_B} -Llibft -lft -o ${NAME_B}

#bonus: ${NAME_B}
#	@make re -C ./libft
#	@${CC} ${OBJS_B} -Llibft -lft -o ${NAME_B}

clean: 
	@make clean -C ./libft
	@rm -f ${OBJS_C} ${OBJS_S} # ${OBJS_B}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME_C} ${NAME_S} # ${NAME_B}

re: fclean all

#re_bonus: fclean bonus

.PHONY: all clean fclean re #re_bonus bonus

