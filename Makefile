NAME_C = client
NAME_S = server

BONUS_C = client_bonus
BONUS_S = server_bonus

CFLAGS = -Wextra -Wall -Werror

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRCS_C = client.c minitalk.c
OBJS_C = $(SRCS_C:.c=.o)
SRCS_S = server.c minitalk.c
OBJS_S = $(SRCS_S:.c=.o)

BONUS_DIR = ./bonus
BONUS_SRCS_C = client_bonus.c minitalk_bonus.c
BONUS_OBJS_C = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS_C:.c=.o))
BONUS_SRCS_S = server_bonus.c minitalk_bonus.c
BONUS_OBJS_S = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS_S:.c=.o))

all: $(LIBFT_A) $(NAME_C) $(NAME_S)

%.o: %.c
	@cc $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(NAME_C): $(OBJS_C) 
	cc $(CFLAGS) $(OBJS_C) $(LIBFT_A) -o $@

$(NAME_S): $(OBJS_S) $(LIBFT_A)
	cc $(CFLAGS) $(OBJS_S) $(LIBFT_A) -o $@

bonus: .bonus $(LIBFT_A) $(BONUS_C) $(BONUS_S)
	@touch .bonus

.bonus: 
	@if [ -f $(NAME_C) ] || [ -f $(NAME_S) ]; then \
		$(MAKE) fclean; \
	fi

$(BONUS_C): $(BONUS_OBJS_C)
	cc $(CFLAGS) $(BONUS_OBJS_C) $(LIBFT_A) -o $@

$(BONUS_S): $(BONUS_OBJS_S)
	cc $(CFLAGS) $(BONUS_OBJS_S) $(LIBFT_A) -o $@

clean:
	@rm -rf $(OBJS_C) $(OBJS_S) $(BONUS_OBJS_C) $(BONUS_OBJS_S)
	@make -C $(LIBFT_DIR) clean
	@rm -rf .bonus

fclean: clean
	@rm -rf $(NAME_C) $(NAME_S) $(BONUS_C) $(BONUS_S)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
