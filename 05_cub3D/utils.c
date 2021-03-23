/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:20:38 by junghwki          #+#    #+#             */
/*   Updated: 2021/03/23 19:04:10 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_pixel_put(t_box *box, int x, int y, int color)
{
	box->img.addr[(box->win.width * y) + x] = color;
}

void		ft_make_wall(t_box *box, int x, int y)
{
	int		first_x;
	int		first_y;

	first_y = y * box->win.height_len;
	while(first_y < (box->win.height_len + (y * box->win.height_len)))
	{
		first_x = x * box->win.width_len;
		while(first_x < (box->win.width_len + (x * box->win.width_len)))
		{
			ft_pixel_put(box, first_x, first_y, 0x666666);
			first_x++;
		}
		first_y++;
	}
}

void 		ft_draw_dir(t_box *box)
{
	int i;
	double x;
	double y;

	i = 0;
	x = box->pos.x * box->win.width_len;
	y = box->pos.y * box->win.height_len;
	while (i < box->win.width_len / 2)
	{
		ft_pixel_put(box, x, y, 0x00FF00);
		i++;
		x += cos(box->pos.theta);
		y += sin(box->pos.theta);
	}
}

void		ft_make_sprt(t_box *box, int x, int y)
{
	int		first_x;
	int		first_y;

	first_y = y * box->win.height_len;
	while(first_y < (box->win.height_len + (y * box->win.height_len)))
	{
		first_x = x * box->win.width_len;
		while(first_x < (box->win.width_len + (x * box->win.width_len)))
		{
			ft_pixel_put(box, first_x, first_y, 0x5555FF);
			first_x++;
		}
		first_y++;
	}
}

void		ft_draw_wall(t_box *box)
{
	int		row;
	int		col;

	row = 0;
	while(row < box->win.row)
	{
		col = 0;
		while(col < box->win.col)
		{
			if(box->win.map[row][col] == '1')
				ft_make_wall(box, col, row);
				///////////
			if(box->win.map[row][col] == '2')
				ft_make_sprt(box, col, row);
				//////////
			col++;
		}
		row++;
	}
}

void		ft_draw_grid(t_box *box)
{
	int 	x;
	int 	y;

	y = box->win.height_len;
	while (y < box->win.height)
	{
		x = 0;
		while (x < box->win.width)
		{
			ft_pixel_put(box, x, y, 0xFFFFFF);
			x += 1;
		}
		y += box->win.height_len;
	}
	x = box->win.width_len;
	while (x < box->win.width)
	{
		y = 0;
		while (y < box->win.height)
		{
			ft_pixel_put(box, x, y, 0xFFFFFF);
			y += 1;
		}
		x += box->win.width_len;
	}
}

void		ft_draw_player(t_box *box)
{
	int 	first_x;
	int 	first_y;
	int		player_size;

	player_size = 3;
	first_y = (box->pos.y * box->win.height_len) + player_size;
	while (first_y >= (box->pos.y * box->win.height_len) - player_size)
	{
		first_x = (box->pos.x * box->win.width_len) + player_size;
		while (first_x >= (box->pos.x * box->win.width_len) - player_size)
		{
			ft_pixel_put(box, first_x, first_y, 0xFF0000);
			first_x -= 1;
		}
		first_y -= 1;
	}
}

void		ft_clear_image(t_box *box)
{
	int     index;

	index = 0;
	while (index < (box->win.width) * (box->win.height))
	{
		box->img.addr[index] = 0;
		index++;
	}
}

void		ft_background_init(t_box *box)
{
	int     index;

	index = 0;
	while (index < (box->win.width) * (box->win.height) / 2)
	{
		box->img.addr[index] = box->win.c_color;
		index++;
	}
	while (index < (box->win.width) * (box->win.height))
    {
        box->img.addr[index] = box->win.f_color;
        index++;
    }    
}

double		ft_gradient_cmp(double x, double y)
{
	return (fabs(x) >= fabs(y));
}

int         ft_exit(t_box *box)
{
	exit(0);
	return (0);
}

void		ft_error()
{
	printf("Error\n");
	exit(0);
}

double      ft_deg_to_rad(double x)
{
    return (x * M_PI / 180);
}

double		ft_dist_calc(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

t_vec		ft_theta_check(double theta)
{
	if (theta > ft_deg_to_rad(0) && theta < ft_deg_to_rad(90))
		return (ft_new_vec(1, 1));
	else if (theta > ft_deg_to_rad(90) && theta < ft_deg_to_rad(180))
		return (ft_new_vec(-1, 1));
	else if (theta > ft_deg_to_rad(180) && theta < ft_deg_to_rad(270))
		return (ft_new_vec(-1, -1));
	else if (theta > ft_deg_to_rad(270) && theta < ft_deg_to_rad(360))
		return (ft_new_vec(1, -1));
	else if (theta == ft_deg_to_rad(90))
		return (ft_new_vec(0, 1));
	else if (theta == ft_deg_to_rad(180))
		return (ft_new_vec(-1, 0));
	else if (theta == ft_deg_to_rad(270))
		return (ft_new_vec(0, -1));
	else if (theta == ft_deg_to_rad(360) || theta == ft_deg_to_rad(0))
		return (ft_new_vec(1, 0));
	else
		return (ft_new_vec(0, 0));
}

double		ft_rot_angle(double angle, double theta)
{
	double result;

	result = angle + theta;
	if (result <= 0)
		result = (result + (2 * M_PI));
	else if (result >= 2 * M_PI)
		result = (result - (2 * M_PI));
	return (result);
}

void 		ft_box_set(t_box *box)
{
	box->win.width_len = box->win.width / box->win.col;
	box->win.height_len = box->win.height / box->win.row;
	box->win.move_speed = 0.06;
	box->win.fov = ft_deg_to_rad(90);
	box->win.dis = box->win.width / tan(box->win.fov / 2);
	box->win.rotate_angle = ft_deg_to_rad(3);
	box->mlx.ft_mlx = mlx_init();
	box->mlx.ft_win = mlx_new_window(box->mlx.ft_mlx, box->win.width, box->win.height, "cub3D");
	box->img.img = mlx_new_image(box->mlx.ft_mlx, box->win.width, box->win.height);
	box->img.addr = (int *)mlx_get_data_addr(box->img.img, &box->img.bits_per_pixel, &box->img.size_line, &box->img.endian);
	box->ea.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, box->ea.route, &box->ea.width, &box->ea.height);
	box->ea.addr = (int *)mlx_get_data_addr(box->ea.ptr, &box->ea.bits_per_pixel, &box->ea.size_line, &box->ea.endian);
	box->we.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, box->we.route, &box->we.width, &box->we.height);
	box->we.addr = (int *)mlx_get_data_addr(box->we.ptr, &box->img.bits_per_pixel, &box->we.size_line, &box->we.endian);
	box->so.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, box->so.route, &box->so.width, &box->so.height);
	box->so.addr = (int *)mlx_get_data_addr(box->so.ptr, &box->img.bits_per_pixel, &box->so.size_line, &box->so.endian);
	box->no.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, box->no.route, &box->no.width, &box->no.height);
	box->no.addr = (int *)mlx_get_data_addr(box->no.ptr, &box->img.bits_per_pixel, &box->no.size_line, &box->no.endian);
	box->s.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, box->s.route, &box->s.width, &box->s.height);
	box->s.addr = (int *)mlx_get_data_addr(box->s.ptr, &box->img.bits_per_pixel, &box->s.size_line, &box->s.endian);
	box->pos.x_height = (double *)malloc(sizeof(double) * box->win.width);
}