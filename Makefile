# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 16:17:40 by robrodri          #+#    #+#              #
#    Updated: 2021/10/14 15:24:00 by robrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	philo.c \
		philo_init_table.c \
		philo_routine.c \
		philo_utils.c \
		philo_utils_2.c \
		philo_utils_3.c

OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Ofast -Werror

HEADER = philo.h

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME) -lpthread

clean :
		rm -rf $(OBJS);
fclean : clean
		rm -rf $(NAME);
re : fclean all
norm :
	norminette $(SRC) $(HEADER)

.PHONY: all re m clean fclean bonus norm
