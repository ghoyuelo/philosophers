# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 23:56:37 by ghoyuelo          #+#    #+#              #
#    Updated: 2023/03/02 13:08:01 by ghoyuelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

RM = rm -f

CC = gcc

CFLAGS = -Wall -Werror -Wextra -pthread #-g3 -fsanitize=address

SRC =	philo.c\
		checker.c\
		utils.c\
		init.c\
		time.c\
		actions.c\

OBJS = $(SRC:.c=.o)

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all re clean fclean