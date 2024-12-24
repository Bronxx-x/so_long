LIBFT_DIR = ./libft
SRC_DIR = ./src
LIBFT = $(LIBFT_DIR)/libftprintf.a

SRCS = $(SRC_DIR)/fllood_fill.c $(SRC_DIR)/moves.c $(SRC_DIR)/images.c \
       $(SRC_DIR)/map_render.c $(SRC_DIR)/errors.c $(SRC_DIR)/map_ch.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
LDFLAGS = -lmlx -lX11 -lXext -L $(LIBFT_DIR) -lft

NAME = so_long

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

