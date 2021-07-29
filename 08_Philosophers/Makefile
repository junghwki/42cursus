SRCS	= ./srcs/main.c \
		  ./srcs/philo.c \
		  ./srcs/utils.c

NAME	= philosophers
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS:.c=.o)
	ar rcs $(NAME) $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(SRCS:.c=.o)

fclean : clean
	rm -f $(NAME)

re : fclean all
