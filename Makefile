# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 16:17:40 by robrodri          #+#    #+#              #
#    Updated: 2021/09/15 17:00:40 by robrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	philo.c \
		philo_utils.c \
		philo_lst_utils.c \
		philo_routine.c \
		philo_prints.c \
		philo_more_utils.c

OBJS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -g -fsanitize=address

HEADER = philo.h

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME) -lpthread
$(OBJS): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean :
		rm -rf $(OBJS);
fclean : clean
		rm -rf $(NAME);
re : fclean all
norm :
	norminette $(SRC) $(HEADER)

.PHONY: all re m clean fclean bonus norm
