NAME_C = client
NAME_S = server

CFLAGS = -Wextra -Wall -Werror

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
HEADERS = -I $(LIBFT_DIR)

SRCS_C = client.c
OBJS_C = $(SRCS_C:.c=.o)
SRCS_S = server.c
OBJS_S = $(SRCS_S:.c=.o)

all: $(NAME_C) $(NAME_S) 

%.o: %.c
	@cc $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(NAME_C): $(OBJS_C) $(LIBFT_A)
	cc $(OBJS_C) $(LIBFT_A) -o $(NAME_C)

$(NAME_S): $(OBJS_S) $(LIBFT_A)
	cc $(OBJS_S) $(LIBFT_A) -o $(NAME_S)

clean:
	@rm -rf $(OBJS_C) $(OBJS_S)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME_C) $(NAME_S)
	@make -C $(LIBFT_DIR) fclean

re: clean all

.PHONY: all clean fclean re
