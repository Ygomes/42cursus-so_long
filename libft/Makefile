# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 10:17:04 by ygomes-d          #+#    #+#              #
#    Updated: 2021/12/10 22:36:07 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

CC =	clang

CFLAGS =	-Wall -Werror -Wextra -fPIE

SRCS =	ft_bzero.c \
		ft_split.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strchr.c \
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
