
SRCS =	cub3d_parsing/map_utils.c\
		cub3d_parsing/parsing_utils1.c\
		cub3d_parsing/parsing_utils2.c\
		cub3d_parsing/parsing.c\
		cub3d_parsing/sprt_utils.c\
		cub3d_srcs/bmp.c\
		cub3d_srcs/calc.c\
		cub3d_srcs/cub3d.c\
		cub3d_srcs/dda.c\
		cub3d_srcs/get_next_line.c\
		cub3d_srcs/key_function.c\
		cub3d_srcs/main.c\
		cub3d_srcs/move.c\
		cub3d_srcs/pixel_put.c\
		cub3d_srcs/sprite.c\
		cub3d_srcs/texture_addr.c\
		cub3d_srcs/texture.c\
		cub3d_srcs/utils.c\
		libft/ft_atoi.c\
		libft/ft_isdigit.c\
		libft/ft_split.c\
		libft/ft_strcmp.c\
		libft/ft_strdup.c\
		libft/ft_strjoin.c\
		libft/ft_strlcat.c\
		libft/ft_strlcpy.c\
		libft/ft_strlen.c

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

bonus : all

.PHONY : all clean fclean re bonus