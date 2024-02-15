# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 10:26:06 by glopez-c          #+#    #+#              #
#    Updated: 2023/12/13 21:48:53 by glopez-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs

RM = rm -f

SRC = ft_printf ft_printchar_fd ft_printstr_fd ft_printnbr_fd ft_printnbr_base_fd

SRCS = $(addsuffix .c, ${SRC})

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

%.o: %.c ft_printf.h
	${CC} ${CCFLAGS} -I. -c $< -o ${<:.c=.o}

all:  ${NAME}

$(NAME): ${OBJS} ft_printf.h
	${AR} ${NAME} ${OBJS}

clean: 
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
