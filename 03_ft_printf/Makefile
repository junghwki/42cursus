# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwki <junghwki@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 21:14:45 by junghwki          #+#    #+#              #
#    Updated: 2020/11/10 17:57:00 by junghwki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./ft_printf.c \
			  ./ft_printf_utils.c \
			  ./ft_diu_format.c \
			  ./ft_px_format.c \
			  ./ft_cpct_format.c \
			  ./ft_s_format.c \
			  ./ft_llitoa.c \
			  ./ft_itoa_base.c \
			  ./ft_putstr.c

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_LIB = libft.a

all : $(NAME)

$(NAME) : $(SRCS:.c=.o)
	make bonus -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

#bonus : $(NAME) $(BONUS:.c=.o) 
#	ar rcs $(NAME) $(BONUS:.c=.o)

clean :
	rm -f $(SRCS:.c=.o) $(BONUS:.c=.o)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all
