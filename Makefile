LIBFT = ./libft/libft.a

LPATH = ./libft/

NAME = so_long

NAME_BONUS = so_long_bonus

SRC =	./src/so_long.c \
		./src/character_mov.c \
		./src/exit_game.c \
		./src/keypress.c \
		./src/validation.c \
		./src/start_game.c \
		./src/game_init.c \
		./src/img_update.c \

BSRC =	./src_bonus/so_long_bonus.c \
		./src_bonus/character_mov_bonus.c \
		./src_bonus/exit_game_bonus.c \
		./src_bonus/keypress_bonus.c \
		./src_bonus/validation_bonus.c \
		./src_bonus/start_game_bonus.c \
		./src_bonus/game_init_bonus.c \
		./src_bonus/img_update_bonus.c \
		./src_bonus/moves_bonus.c \

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
