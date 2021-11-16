# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwki <junghwki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 15:04:49 by junghwki          #+#    #+#              #
#    Updated: 2021/10/20 15:05:15 by junghwki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philosophers
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./srcs/main.c \
		  ./srcs/philo.c \
		  ./srcs/utils.c

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
