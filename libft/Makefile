# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 10:17:04 by ygomes-d          #+#    #+#              #
#    Updated: 2022/01/21 23:41:09 by ygomes-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

CC =	gcc

CFLAGS =	-Wall -Werror -Wextra

SRCS =	ft_bzero.c \
		ft_split.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strchr.c \
		ft_itoa.c \
		get_next_line.c \


BONUSOBJS = $(BSRCS:.c=.o)

OBJS =	$(SRCS:.c=.o)

RM =	rm -f

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)

all:	$(NAME)

clean:
		$(RM) $(OBJS) $(BONUSOBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
