/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:41 by junghwki          #+#    #+#             */
/*   Updated: 2021/03/29 19:45:57 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 10

// # include "./libft/libft.h"
# include "./opengl/mlx.h"
# include "./opengl_beta/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_mlx {
	void		*ft_mlx;
	void		*ft_win;
}				t_mlx;

typedef struct	s_vector {
	double		x;
	double		y;
}				t_vec;

typedef struct	s_window {
	int			width;
	int			height;
	char		**map;
	int			row;
	int			col;
	double		width_len;
	double		height_len;
	double		move_speed;
	double		fov;
	double		dis;
	double		rotate_angle;
	int			c_color;
	int			f_color;
}				t_win;

typedef struct	s_image {
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_texture {
	char		*route;
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
	double		*x_height;
	t_vec		dir;
	int			map_x;
	int			map_y;
	int			visible_num;
}				t_pos;

typedef struct	s_sprite {
	double		x;
	double		y;
	int			visible;
	double		angle;
	double		dist;
}				t_sprt;

typedef struct	s_parsing {
	int			r_flag;
	int			ea_flag;
	int			we_flag;
	int			so_flag;
	int			no_flag;
	int			s_flag;
	int			f_flag;
	int			c_flag;
	int			s_cnt;
	char		*line;
	char		**word;
	char		*map;
}				t_pars;

typedef struct	s_key {
	int			w;
	int			s;
	int			a;
	int			d;
	int			left;
	int			right;
	int			m;
}				t_key;

typedef struct	s_box {
	t_mlx		mlx;
	t_win		win;
	t_img		img;
	t_pos		pos;
	t_pars		pars;
	t_key		key;
	t_tex		ea;
	t_tex		we;
	t_tex		so;
	t_tex		no;
	t_tex		s;
	t_sprt		*sprt;
	t_sprt		*visible;
	t_vec		comp;
}				t_box;

void		ft_draw_dir(t_box *box);
void		ft_draw_tex(t_box *box, double wall_height, int x);
double		ft_wall_check(t_box *box, double theta);
void		ft_draw_fov(t_box *box);
void		ft_box_set(t_box *box);
int			ft_main_loop(t_box *box);
int			ft_key_press(int keycode, t_box *box);
int			ft_key_release(int keycode, t_box *box);
int 		ft_key_function(t_box *box);

void 		ft_box_set(t_box *box);
void 		ft_sprt_swap(t_sprt *a, t_sprt *b);
void			ft_pixel_put(t_box *box, int x, int y, int color);//utils
void			ft_clear_image(t_box *box);
void			ft_background_init(t_box *box);
double			ft_gradient_cmp(double x, double y);
int				ft_exit(t_box *box);
double			ft_deg_to_rad(double x);
double			ft_dist_calc(double x, double y);
double			ft_rot_angle(double angle, double theta);
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

int				get_next_line(int fd, char **line);//gnl
////////////////////libft
int		ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlcat(char *dst, const char *src, int dstsize);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
///////////////////////////////sprt
void 	ft_sprt_pos(t_box *box);

//////////////////////////////sprt

///////////////////////////////parsing
void 	ft_nbr_check(char *nbr);
void 	ft_map_print(t_box *box);
void 	ft_make_base(t_box *box);
void 	ft_get_map(t_box *box, int fd);
int		ft_check_flag(t_box *box);
int		ft_rowlen(char **array);
void	ft_pars_init(t_box *box);
void	ft_map_dup(t_box *box, char **src);
void	ft_map_check(t_box *box);
void	ft_error();
void	ft_dir_check(t_box *box);
void	ft_array_free(char **array);
///////////////////////////////parsing
///////////////////////////////////////지워야될것
void	ft_map_print(t_box *box);
void	ft_make_sprt(t_box *box, int x, int y);
void 	ft_draw_dir(t_box *box);
double		theta_change(double theta);
//////////////////////////////////////
#endif
