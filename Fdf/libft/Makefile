# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glopez-c <glopez-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 14:55:07 by glopez-c          #+#    #+#              #
#    Updated: 2024/02/07 20:42:21 by glopez-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs

RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper \
	ft_printf/ft_printf ft_printf/ft_printchar_fd ft_printf/ft_printnbr_base_fd ft_printf/ft_printnbr_fd ft_printf/ft_printstr_fd 
	
BSRC = ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus

SRCS = $(addsuffix .c, ${SRC})

BSRCS = $(addsuffix .c, ${BSRC})

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

%.o: %.c libft.h
	@${CC} ${CCFLAGS} -I. -c $< -o ${<:.c=.o}

all:  ${NAME}

$(NAME): ${OBJS}
	@${AR} ${NAME} ${OBJS}

bonus:  ${BOBJS}
	@${AR} ${NAME} ${BOBJS}

clean: 
	@${RM} ${OBJS} ${BOBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
