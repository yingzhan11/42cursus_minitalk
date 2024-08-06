# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 11:50:59 by yzhan             #+#    #+#              #
#    Updated: 2024/07/04 15:21:26 by yzhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c
OBJ = $(SRC:.c=.o)

PTF_DIR = ft_printf
PTF_SRC = ft_printf.c ft_print_char.c ft_print_digit.c ft_print_pointer.c
PTF_OBJ = $(addprefix $(PTF_DIR)/, $(PTF_SRC:.c=.o))

%.o : %.c
	@cc $(FLAGS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(PTF_OBJ)
	@ar -rc $@ $^

clean:
	@rm -f $(OBJ) $(GNL_OBJ) $(PTF_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
