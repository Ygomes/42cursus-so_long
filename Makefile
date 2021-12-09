LIBFT = ./libft/libft.a

NAME = so_long

SRC = so_long.c \

CFLAGS = -Wall -Werror -Wextra -g

MLXFLAGS = -lmlx -lXext -lX11

CC =	gcc

OBJS = $(SRC:.o=.c)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME)


clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean:	clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
