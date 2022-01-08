LIBFT = ./libft/libft.a

LPATH = ./libft/

NAME = so_long

NAME_BONUS = so_long_bonus

SRC = ./src/so_long.c \

BSRC = ./src_bonus/so_long_bonus.c \

CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3

MLXFLAGS = -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC =	gcc

OBJS = $(SRC:.c=.o)

BOBJS = $(BSRC:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


all:	$(NAME)

bonus: $(NAME_BONUS)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			$(CC) $(OBJS) -L$(LPATH) -lft $(CFLAGS) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS):	$(BOBJS)
				$(MAKE) -C ./libft
				$(CC) $(BOBJS) -L$(LPATH) -lft $(CFLAGS) $(MLXFLAGS) -o $(NAME_BONUS)

clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS) $(BOBJS)

fclean:	clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY: all clean fclean re bonus
