NAME = cub3D

SRCS = ./cub3d.c \
		./get_next_line.c \
		./key_function.c \
		./move.c \
		./parsing.c \
		./utils.c \
		./vector.c \
		./utils/ft_atoi.c \
		./utils/ft_isdigit.c \
		./utils/ft_split.c \
		./utils/ft_strcmp.c \
		./utils/ft_strdup.c \
		./utils/ft_strjoin.c \
		./utils/ft_strlcat.c \
		./utils/ft_strlcpy.c \
		./utils/ft_strlen.c \
		./utils/parsing_util.c

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