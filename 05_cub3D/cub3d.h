/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:15:29 by junghwki          #+#    #+#             */
/*   Updated: 2021/02/18 18:16:16 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./opengl/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

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
	double		rotate_angle;
}				t_win;

typedef struct	s_image {
	void		*img;
	int			*img_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_position {
	double		x;
	double		y;
	double		theta;
}				t_pos;

typedef struct	s_vector {
	double		x;
	double		y;
}				t_vec;

typedef struct	s_box {
	t_mlx		mlx;
	t_win		win;
	t_img		img;
	t_pos		pos;
	t_vec		step;
	t_vec		dir;
	t_vec		end_ray;
}				t_box;

void			ft_pixel_put(t_box *box, int x, int y, int color);
void			ft_clear_image(t_box *box);
void			ft_background_init(t_box *box);
double			ft_gradient_cmp(double x, double y);
int				ft_exit(t_box *box);
double			ft_deg_to_rad(double x);//utils
double			ft_rot_theta(t_box *box, double theta);
t_vec			ft_theta_check(double theta);

void    		ft_move_up(t_box *box);
void		    ft_move_down(t_box *box);
void	    	ft_move_left(t_box *box);
void    		ft_move_right(t_box *box);
void			ft_rotate_left(t_box *box);
void			ft_rotate_right(t_box *box);//move

// void			ft_make_wall(t_box *box, int x, int y);
// void			ft_draw_wall(t_box *box);
// void			ft_draw_grid(t_box *box);
// void			ft_draw_player(t_box *box);//draw

t_vec           ft_new_vec(double x, double y);
t_vec           ft_add_vec(t_vec a, t_vec b);
t_vec           ft_sub_vec(t_vec a, t_vec b);
t_vec           ft_mul_vec(t_vec a, double k);
t_vec           ft_rot_vec(t_vec a, double theta);//vector
#endif
