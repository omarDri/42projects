# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 16:31:45 by odouhri           #+#    #+#              #
#    Updated: 2023/06/14 01:50:19 by odouhri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OPTIONS = -Wall -Wextra -Werror

SRC = main.c arg_check.c stack_check.c ft_printerr.c stack.c instructions.c sort_big.c sort_small.c min_num.c ft_printf/libftprintf.a

FT_PRINTF = make -C ft_printf

all: $(NAME)

$(NAME):
	$(FT_PRINTF) && gcc $(OPTIONS) -o $(NAME) $(SRC)


cleanlib:
	make -C ft_printf clean

clean: cleanlib
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f ft_printf/libft/libft.a
	/bin/rm -f ft_printf/libftprintf.a
	/bin/rm -f $(NAME)

re: fclean all
