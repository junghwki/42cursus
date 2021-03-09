/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:41 by junghwki          #+#    #+#             */
/*   Updated: 2021/03/09 22:05:36 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 10

# include "./libft/libft.h"
# include "./opengl/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_mlx {
	void		*ft_mlx;
	void		*ft_win;
}				t_mlx;

typedef struct	s_window {
	int			width;
	int			height;
	int			row;
	int			col;
	double		width_len;
	double		height_len;
	double		move_speed;
	double		fov;
	double		dis;
	double		rotate_angle;
}				t_win;

typedef struct	s_image {
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_texture {
	int			*addr;
	void		*ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_tex;

typedef struct	s_position {
	double		x;
	double		y;
	double		theta;
	double		tex;
	int			map_x;
	int			map_y;
}				t_pos;

typedef struct	s_sprite {
	int			x;
	int			y;
	int			**visible;
	int			tex;
	double		dist;

}				t_sprt;

typedef struct	s_key {
	int			w;
	int			s;
	int			a;
	int			d;
	int			left;
	int			right;
}				t_key;

typedef struct	s_vector {
	double		x;
	double		y;
}				t_vec;

typedef struct	s_box {
	t_mlx		mlx;
	t_win		win;
	t_img		img;
	t_pos		pos;
	t_key		key;
	t_tex		e;
	t_tex		w;
	t_tex		s;
	t_tex		n;
	t_sprt		sprt;
	t_vec		dir;
	t_vec		comp;
}				t_box;

void		ft_draw_dir(t_box *box);
void		ft_draw_tex(t_box *box, double wall_height, int x);
double		ft_wall_check(t_box *box, double theta);
void		ft_draw_fov(t_box *box);
void		ft_box_set(t_box *box);
int			ft_main_loop(t_box *box);


void			ft_pixel_put(t_box *box, int x, int y, int color);//utils
void			ft_clear_image(t_box *box);
void			ft_background_init(t_box *box);
double			ft_gradient_cmp(double x, double y);
int				ft_exit(t_box *box);
double			ft_deg_to_rad(double x);
double			ft_rot_theta(t_box *box, double theta);
t_vec			ft_theta_check(double theta);
void			ft_clear_sprt(t_box *box);//utils

void			ft_make_wall(t_box *box, int x, int y);
void			ft_draw_wall(t_box *box);
void			ft_draw_grid(t_box *box);
void			ft_draw_player(t_box *box);//utils

void    		ft_move_up(t_box *box);//move
void		    ft_move_down(t_box *box);
void	    	ft_move_left(t_box *box);
void    		ft_move_right(t_box *box);
void			ft_rotate_left(t_box *box);
void			ft_rotate_right(t_box *box);//move

t_vec           ft_new_vec(double x, double y);//vector
t_vec           ft_add_vec(t_vec a, t_vec b);
t_vec           ft_sub_vec(t_vec a, t_vec b);
t_vec           ft_mul_vec(t_vec a, double k);
t_vec           ft_rot_vec(t_vec a, double theta);//vector

size_t			ft_strlen(const char *s);//gnl
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *s1, char const *s2);
static int		ft_putline(char **line, char **next_buffer, int str_len);
static int		ft_strclen(char *str, char c);
int				get_next_line(int fd, char **line);//gnl

#endif
