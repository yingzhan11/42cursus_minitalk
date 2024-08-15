NAME_C = client
NAME_S = server

CFLAGS = -Wextra -Wall -Werror

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
HEADERS = -I $(LIBFT_DIR)


SRCS_C = client.c minitalk.c
OBJS_C = $(SRCS_C:.c=.o)
SRCS_S = server.c minitalk.c
OBJS_S = $(SRCS_S:.c=.o)

all: $(NAME_C) $(NAME_S)

%.o: %.c
	@cc $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(NAME_C): $(OBJS_C) $(LIBFT_A)
	cc $(CFLAGS) $(OBJS_C) $(LIBFT_A) -o $(NAME_C)

$(NAME_S): $(OBJS_S) $(LIBFT_A)
	cc $(CFLAGS) $(OBJS_S) $(LIBFT_A) -o $(NAME_S)

clean:
	@rm -rf $(OBJS_C) $(OBJS_S)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME_C) $(NAME_S)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
