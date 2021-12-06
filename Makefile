NAME = so_long

SRC = so_long.c \

MLXFLAGS = -lmlx -lXext -lX11

CC = gcc

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


all:	$(NAME)

$(NAME):$(CC) $(MLXFLAGS) -o $(NAME)
