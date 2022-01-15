LIBFT = ./libft/libft.a

LPATH = ./libft/

NAME = so_long

NAME_BONUS = so_long_bonus

SRC =	./src/so_long.c \
		./character/character_mov.c \
		./events/exit_game.c \
		./events/keypress.c \
		./events/validation.c \
		./events/start_game.c \
		./events/game_init.c \

BSRC =	./src_bonus/so_long_bonus.c \
		./character/character_mov_bonus.c \
		./events/exit_game_bonus.c \
		./events/keypress_bonus.c \
		./events/validation_bonus.c \
		./events/start_game_bonus.c \
		./events/game_init_bonus.c \

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -lX11 -lXext

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
