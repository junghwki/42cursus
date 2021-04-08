NAME = cub3D

SRCS = *.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)
	make -C	opengl
	cp opengl/libmlx.a ./
	gcc $(FLAGS) -L ./opengl -lmlx -framework openGL -framework Appkit	$(SRCS) -o $(NAME)

clean : 
	make -C opengl clean

fclean : clean
	rm -f libmlx.dylib
	rm -f libmlx.a
	rm -f $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus