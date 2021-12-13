LIBFT = ./libft/libft.a

LPATH = ./libft/

NAME = so_long

NAME_BONUS = so_long_bonus

SRC = ./src/so_long.c \

BSRC = ./src_bonus/so_long_bonus.c \

CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -lmlx -lXext -lX11

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
