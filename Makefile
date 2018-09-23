#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 10:10:15 by ykaplien          #+#    #+#              #
#    Updated: 2018/05/21 13:48:41 by vkorniie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRCS = 	ft_bzero.c \
		ft_putstr.c \
		ft_strlen.c \
		mmoves.c \
		s_operations.c \
		vdv.c \
		backtrack.c \
		ft_putchar.c \
		ft_strcpy.c \
		main.c \
		research.c \
		security.c

OBJ =	$(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

HEADER = fillit.h

all: $(NAME)

%.o:%.c
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

$(NAME): $(OBJ) 
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(HEADER)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
