
SRCS =	cub3d_parsing/map_utils.c\
		cub3d_parsing/parsing_utils1.c\
		cub3d_parsing/parsing_utils2.c\
		cub3d_parsing/parsing.c\
		cub3d_parsing/sprt_utils.c\
		cub3d_srcs/bmp.c\
		cub3d_srcs/calc.c\
		cub3d_srcs/dda.c\
		cub3d_srcs/get_next_line.c\
		cub3d_srcs/key_function.c\
		cub3d_srcs/main.c\
		cub3d_srcs/move.c\
		cub3d_srcs/sprite.c\
		cub3d_srcs/texture_addr.c\
		cub3d_srcs/texture.c\
		cub3d_srcs/utils.c\
		cub3d_libft/ft_atoi.c\
		cub3d_libft/ft_isdigit.c\
		cub3d_libft/ft_split.c\
		cub3d_libft/ft_strcmp.c\
		cub3d_libft/ft_strdup.c\
		cub3d_libft/ft_strjoin.c\
		cub3d_libft/ft_strlcat.c\
		cub3d_libft/ft_strlcpy.c\
		cub3d_libft/ft_strlen.c

NAME	= cub3D
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)
	make -C	opengl
	make -C minilibx_mms
	cp opengl/libmlx.a ./
	cp minilibx_mms/libmlx.dylib ./
	gcc $(CFLAGS) -L ./opengl -lmlx -framework OpenGL -framework Appkit	$(SRCS) libmlx.dylib -o $(NAME) 

clean : 
	make -C opengl clean
	make -C minilibx_mms clean

fclean : clean
	rm -f libmlx.a
	rm -f libmlx.dylib
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re