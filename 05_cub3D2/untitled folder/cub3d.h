/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:41 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/09 12:44:42 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 100

# include "./opengl/mlx.h"
# include "./minilibx_mms/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct		s_bfh
{
    unsigned int	bf_size;
    unsigned short	bf_reserved1;
    unsigned short	bf_reserved2;
    unsigned int	bf_off_bits;
}					t_bfh;

typedef struct		s_bih
{
    unsigned int	bi_size;
    int				bi_width;
    int				bi_height;
    unsigned short	bi_planes;
    unsigned short	bi_bit_count;
    unsigned int	bi_compression;
    unsigned int	bi_size_image;
    int				bi_x_pels_per_meter;
    int				bi_y_pels_per_meter;
    unsigned int	bi_clr_used;
    unsigned int	bi_clr_important;
}					t_bih;

typedef struct		s_mlx {
	void			*ft_mlx;
	void			*ft_win;
}					t_mlx;

typedef struct		s_vector {
	double			x;
	double			y;
}					t_vec;

typedef struct		s_window {
	int				width;
	int				height;
	char			**map;
	int				row;
	int				col;
	double			width_len;
	double			height_len;
	double			move_speed;
	double			fov;
	double			dis;
	double			rotate_angle;
	int				c_color;
	int				f_color;
}					t_win;

typedef struct		s_image {
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_texture {
	int				*addr;
	void			*ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	double			x_idx;
	double			y_idx;
}					t_tex;

typedef struct		s_position {
	double			x;
	double			y;
	double			theta;
	double			tex;
	double			*x_height;
	t_vec			dir;
	int				map_x;
	int				map_y;
	int				visible_num;
}					t_pos;

typedef struct		s_sprite {
	double			x;
	double			y;
	int				visible;
	double			angle;
	double			dist;
}					t_sprt;

typedef struct		s_parsing {
	int				r_flag;
	int				ea_flag;
	int				we_flag;
	int				so_flag;
	int				no_flag;
	int				s_flag;
	int				f_flag;
	int				c_flag;
	int				s_cnt;
	char			*line;
	char			**word;
	char			*map;
}					t_pars;

typedef struct		s_key {
	int				w_flag;
	int				s_flag;
	int				a_flag;
	int				d_flag;
	int				left_flag;
	int				right_flag;
	int				m_flag;
}					t_key;

typedef struct		s_dda {
	double			delta_x;
	double			delta_y;
	double			side_x;
	double			side_y;
}					t_dda;

typedef struct		s_box {
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_pos			pos;
	t_pars			pars;
	t_key			key;
	t_tex			ea;
	t_tex			we;
	t_tex			so;
	t_tex			no;
	t_tex			s;
	t_dda			dda;
	t_sprt			*sprt;
	t_sprt			*visible;
	t_vec			comp;
	t_bfh			bfh;
	t_bih			bih;
}					t_box;


//////////cub3d libft
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				**ft_split(const char *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlcat(char *dst, const char *src, int dstsize);
int					ft_strlcpy(char *dst, const char *src, int dstsize);
int					ft_strlen(const char *s);
///////////////cub3d_parsing///////////////
//map_utils.c
int					ft_is_valid(char c);
void				ft_map_check(t_box *box);
int					ft_set_player_pos(t_box *box, int x, int y);
void				ft_dir_check(t_box *box);
//-parsing_utils1.c
void				ft_array_free(char **array);
int					ft_rowlen(char **array);
void				ft_nbr_check(char *nbr);
void				ft_element_check(char *nbr);
//-parsing_utils2.c
void				ft_map_dup(t_box *box);
void				ft_make_base(t_box *box);
void				ft_resolution(t_box *box);
void				ft_c_color(t_box *box);
void				ft_f_color(t_box *box);
//-parsing.c
int					ft_check_flag(t_box *box);
void				ft_pars_init(t_box *box);
void				ft_parsing_data(t_box *box);
void				ft_parsing_map(t_box *box, int eof);
void				ft_parsing_cub(t_box *box, int fd);
//-sprt_utils.c
double				ft_dist_calc(double x, double y);
void				ft_visible_init(t_box *box);
void				ft_make_visible_array(t_box *box);
void				ft_sort_sprt(t_box *box);
///////////////cub_3d_srcs///////////////
//-bmp.c
void				ft_bitmap_file_header(t_box *box, int fd);
void				ft_bitmap_info_header(t_box *box, int fd);
void				ft_write_bmp(t_box *box);
void				ft_save_bmp(t_box *box);
//-calc.c
double				ft_deg2rad(double x);
double				ft_rot_angle(double angle, double theta);
void				ft_rotate_left(t_box *box);
void				ft_rotate_right(t_box *box);
//-dda.c
t_vec				ft_theta_check(double theta);
void				ft_calc_dda(t_box *box, double rot_theta);
double				ft_wall_check(t_box *box, double theta);
void				ft_draw_fov(t_box *box);
//get_next_line.c
int					get_next_line(int fd, char **line);
//key_function.c
int					ft_key_press(int keycode, t_box *box);
int					ft_key_release(int keycode, t_box *box);
int					ft_key_function(t_box *box);
//main.c
void				ft_box_set(t_box *box);
int					ft_main_loop(t_box *box);
int					main(int argc, char *argv[]);
//move.c
t_vec				ft_new_vec(double x, double y);
void				ft_move_up(t_box *box);
void				ft_move_down(t_box *box);
void				ft_move_left(t_box *box);
void				ft_move_right(t_box *box);
//sprite.c
void				ft_draw_sprt(t_box *box, double sprt_len, int x, int y);
void				ft_sprt_check(t_box *box);
void				ft_sprt_pos(t_box *box);
int					ft_visible_check(t_box *box, double sprt_angle);
void				ft_sprt_calc(t_box *box);
//texture_addr.c
void				ft_ea_route(t_box *box);
void				ft_we_route(t_box *box);
void				ft_so_route(t_box *box);
void				ft_no_route(t_box *box);
void				ft_s_route(t_box *box);
//texture.c
void				draw_ea_tex(t_box *box, double wall_height, int x);
void				draw_we_tex(t_box *box, double wall_height, int x);
void				draw_so_tex(t_box *box, double wall_height, int x);
void				draw_no_tex(t_box *box, double wall_height, int x);
//utils.c
void				ft_sprt_swap(t_sprt *a, t_sprt *b);
int					ft_exit(t_box *box);
void				ft_error(void);
void				ft_pixel_put(t_box *box, int x, int y, int color);
void				ft_background_init(t_box *box);
////
int					mlx_get_screen_size(void *mlx, int *x, int *y);
#endif
