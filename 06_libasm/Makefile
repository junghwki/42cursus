# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 16:48:45 by junghwki          #+#    #+#              #
#    Updated: 2021/04/22 17:46:45 by junghwki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =  ./ft_strlen.s \
        ./ft_strcpy.s \
        ./ft_strcmp.s \
        ./ft_write.s \
        ./ft_strdup.s \
        ./ft_read.s

NAME	= libasm.a
OBJS	= $(SRCS:.s=.o)

%.o : %.s
	nasm -f macho64 $<

$(NAME) : $(OBJS)
	ar r $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(OBJS)
	
re : fclean all

.PHONY : all clean fclean re