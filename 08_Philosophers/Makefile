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

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re : fclean all
