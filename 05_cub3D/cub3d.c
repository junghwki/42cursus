/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:08:48 by junghwki          #+#    #+#             */
/*   Updated: 2021/02/18 21:10:05 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			map[10][10] =//row,col
	{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void		ft_make_wall(t_box *box, int x, int y)
{
	int		first_x;
	int		first_y;

	first_y = y;
	while (first_y < (box->win.height_len + y))
	{
		first_x = x;
		while (first_x < (box->win.width_len + x))
		{
			ft_pixel_put(box, first_x, first_y, 0x666666);
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
			if(map[row][col] == 1)
				ft_make_wall(box, col * box->win.width_len, row * box->win.height_len);
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
	// ft_pixel_put(box, box->pos.x, box->pos.y, 0xFF0000);
	int 	first_x;
	int 	first_y;
	int		player_size;

	player_size = 3;
	first_y = box->pos.y + player_size;
	while (first_y >= box->pos.y - player_size)
	{
		first_x = box->pos.x + player_size;
		while (first_x >= box->pos.x - player_size)
		{
			ft_pixel_put(box, first_x, first_y, 0xFF0000);
			first_x -= 1;
		}
		first_y -= 1;
	}
}

double		ft_make_ray(t_box *box, double theta)
{
	double	dis_x;
	double	dis_y;
	double	rotate_theta;

	box->end_ray.x = box->pos.x;
	box->end_ray.y = box->pos.y;
	rotate_theta = box->pos.theta + theta;
	// while((int)box->end_ray.x % (int)box->win.width_len != 0 && (int)box->end_ray.y % (int)box->win.height_len != 0)
	// {
	// 	ft_pixel_put(box, box->end_ray.x, box->end_ray.y, 0x00FF00);
	// 	box->end_ray.x += cos(rotate_theta);
	// 	box->end_ray.y += sin(rotate_theta);
	// }
	////////////////////////////////////////////////////////////////////////////////////////////////
	while(map[(int)(box->end_ray.y / box->win.height_len)][(int)(box->end_ray.x / box->win.width_len)] == 0)
	{
		ft_pixel_put(box, box->end_ray.x, box->end_ray.y, 0x00FF00);
		box->end_ray.x += cos(rotate_theta);
		box->end_ray.y += sin(rotate_theta);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	box->end_ray.x -= cos(rotate_theta);
	box->end_ray.y -= sin(rotate_theta);
	// dis_x = box->end_ray.x;
	// dis_y = box->end_ray.y;
	// return (0);
	// printf("%f\n",theta);
	// return (cos(theta) * sqrt(pow((box->pos.x - box->end_ray.x), 2) + pow((int)(box->pos.y - (int)box->end_ray.y), 2)));
	return (cos(theta) * sqrt(pow(((int)box->pos.y - (int)box->end_ray.y) / tan(rotate_theta) , 2) + pow(((int)box->pos.y - (int)box->end_ray.y), 2)));
	// return (cos(atan2(box->end_ray.y - box->pos.y,box->end_ray.x - box->pos.x) - atan2(box->dir.y, box->dir.x)) * sqrt((int)(pow((box->pos.x - box->end_ray.x), 2) + (int)pow((box->pos.y - box->end_ray.y), 2))));
}

////////////

// double		ft_make_ray(t_box *box)
// {
// 	double	dis_x;
// 	double	dis_y;
// 	double	delta_x;
// 	double	delta_y;
// 	t_vec	rotate_dis;

// 	box->end_ray.x = box->pos.x;
// 	box->end_ray.y = box->pos.y;
// 	rotate_dis = ft_rot_vec(box->dis, 0);
// 	while(map[(int)(box->end_ray.y / box->win.height_len)][(int)(box->end_ray.x / box->win.width_len)] == 0)
// 	{
// 		ft_pixel_put(box, box->end_ray.x, box->end_ray.y, 0x00FF00);
// 		box->end_ray.x += rotate_dir.x;
// 		box->end_ray.y += rotate_dir.y;
// 		if((int)box->end_ray.x % (int)box->win.width_len == 0)
// 		{
// 			if(map[(int)(box->end_ray.y / box->win.height_len)][(int)(box->end_ray.x / box->win.width_len)] == 0)//x축에 닿았을때
// 			{
// 				if(map[(int)(box->end_ray.y / box->win.height_len)][(int)(box->end_ray.x / box->win.width_len)] == 0)
// 					continue;
// 				else
// 					break;	
// 			}
// 		}
// 		else if((int)box->end_ray.y % (int)box->win.height_len == 0)
// 		{
// 			if(map[(int)(box->end_ray.y / box->win.height_len)][(int)(box->end_ray.x / box->win.width_len)] == 0)//y축에 닿았을때
// 			break;
// 		}
// 		else
// 		{
// 			break;
// 		}
		
// 	}
// 	box->end_ray.x -= box->dir.x;
// 	box->end_ray.y -= box->dir.y;
// 	return (0);
// 	// return (cos(atan2(box->end_ray.y - box->pos.y,box->end_ray.x - box->pos.x) - atan2(box->dir.y, box->dir.x)) * sqrt((int)(pow((box->pos.x - box->end_ray.x), 2) + (int)pow((box->pos.y - box->end_ray.y), 2))));
// }

//////////////


// double		ft_make_ray(t_box *box, double theta)
// {
// 	double	dis_x;
// 	double	dis_y;
// 	t_vec	rotate_dis;

// 	box->end_ray.x = box->pos.x;
// 	box->end_ray.y = box->pos.y;
// 	rotate_dis = ft_rot_vec(box->dis, theta);
// 	while(map[(int)(box->end_ray.y / box->win.height_len)][(int)(box->end_ray.x / box->win.width_len)] == 0)
// 	{
// 		ft_pixel_put(box, box->end_ray.x, box->end_ray.y, 0x00FF00);
// 		box->end_ray.x += rotate_dir.x;
// 		box->end_ray.y += rotate_dir.y;
// 	}
// 	box->end_ray.x -= box->dir.x;
// 	box->end_ray.y -= box->dir.y;
// 	// printf("%f\n",theta);
// 	return (cos(theta) * (sqrt(pow((box->end_ray.x - box->pos.x), 2) + pow((box->end_ray.y - box->pos.y), 2))));
// 	// return (cos(atan2(box->end_ray.y - box->pos.y,box->end_ray.x - box->pos.x) - atan2(box->dir.y, box->dir.x)) * sqrt((int)(pow((box->pos.x - box->end_ray.x), 2) + (int)pow((box->pos.y - box->end_ray.y), 2))));
// }

// double		ft_make_ray(t_box *box, double theta)
// {
// 	double	dis_x;
// 	double	dis_y;
// 	t_vec	rotate_dis;

// 	dis_x = box->pos.x;
// 	dis_y = box->pos.y;
// 	rotate_dis = ft_rot_vec(box->dis, theta);
// 	while(map[(int)(dis_y / box->win.height_len)][(int)(dis_x / box->win.width_len)] == 0)
// 	{
// 		ft_pixel_put(box, dis_x, dis_y, 0x00FF00);
// 		dis_x += rotate_dir.x;
// 		dis_y += rotate_dir.y;
// 	}
// 	dis_x -= box->dir.x;
// 	dis_y -= box->dir.y;
// 	return (cos(theta) * sqrt(pow(box->pos.x - dis_x, 2) + pow(box->pos.y - dis_y, 2)));
// }


// void		ft_draw_ray(t_box *box)
// {
// 	int		i;
// 	int		x;
// 	int		y;
// 	double	wall_height;

// 	i = box->win.width / -2;
// 	x = 0;
// 	while (i <= (box->win.width / 2))
// 	{
// 		wall_height = (box->win.height / ft_make_ray(box, ft_deg_to_rad((66 / (double)(box->win.width) * i)))) / 2;
// 		while(x < box->win.width)
// 		{
// 			y = (box->win.height / 2) - wall_height;
// 			while(y < (box->win.height / 2) + wall_height)
// 			{
// 				ft_pixel_put(box, x, y, 0xFF0000);
// 				y++;
// 			}
// 			x++;
// 		}
// 		i++;
// 	}
// }

void		ft_draw_3d(t_box *box)
{
	int		i;
	int		x;
	int		y;
	double		wall_height;

	i = box->win.width / 2;
	x = 0;
	while (x < box->win.width)
	{
		wall_height = (2 * box->win.height / ft_make_ray(box, ft_deg_to_rad((66 / (double)(box->win.width)) * i))) * 20;
		// ft_make_ray(box, ft_deg_to_rad((66 / (double)(box->win.width)) * i)) * 20;
		y = (box->win.height / 2) - wall_height;
		while (y < (box->win.height / 2) + wall_height)
		{
			if ((int)box->end_ray.x % (int)box->win.width_len == (box->win.width_len - 1))
				ft_pixel_put(box, x, y, 0xFF0000);
			else if ((int)box->end_ray.x % (int)box->win.width_len == 0)
				ft_pixel_put(box, x, y, 0x00FF00);
			else if ((int)box->end_ray.y % (int)box->win.height_len == (box->win.height_len - 1))
				ft_pixel_put(box, x, y, 0x0000FF);
			else if ((int)box->end_ray.y % (int)box->win.height_len == 0)
				ft_pixel_put(box, x, y, 0x000000);
			y++;
		}
		i--;
		x++;
	}
}


int			ft_key_press(int keycode, t_box *box)
{
	if (keycode == 13) //W
		ft_move_up(box);
	else if (keycode == 1) //S
		ft_move_down(box);
	else if (keycode == 0) //A
		ft_move_left(box);
	else if (keycode == 2) //D
		ft_move_right(box);
	else if (keycode == 123) //좌측 방향키
		ft_rotate_left(box);
	else if (keycode == 124) //우측 방향키
		ft_rotate_right(box);
	else if (keycode == 53) //esc
		exit(0);
	return (0);
}

void		ft_box_set(t_box *box)
{
	box->win.width = 1000;
	box->win.height = 1000;
	box->win.col = 10;
	box->win.row = 10;
	box->win.width_len = box->win.width / box->win.col;
	box->win.height_len = box->win.height / box->win.row;
	box->win.move_speed = 5;
	box->win.rotate_angle = ft_deg_to_rad(3);
	box->mlx.ft_mlx = mlx_init();
	box->mlx.ft_win = mlx_new_window(box->mlx.ft_mlx, box->win.width, box->win.height, "cub3D");
	box->img.img = mlx_new_image(box->mlx.ft_mlx, box->win.width, box->win.height);
	box->img.img_addr = (int *)mlx_get_data_addr(box->img.img, &box->img.bits_per_pixel, &box->img.size_line, &box->img.endian);
	box->pos.x = box->win.width / 2;
	box->pos.y = box->win.height / 2;
	box->pos.theta = ft_deg_to_rad(90);
	box->dir.x = cos(box->pos.theta);
	box->dir.y = sin(box->pos.theta);
}

// void		ft_box_set(t_box *box)
// {
// 	box->win.width = 1000;
// 	box->win.height = 1000;
// 	box->win.col = 10;
// 	box->win.row = 10;
// 	box->win.width_len = box->win.width / box->win.col;
// 	box->win.height_len = box->win.height / box->win.row;
// 	box->win.move_speed = 5;
// 	box->win.rotate_angle = ft_deg_to_rad(3);
// 	box->mlx.ft_mlx = mlx_init();
// 	box->mlx.ft_win = mlx_new_window(box->mlx.ft_mlx, box->win.width, box->win.height, "cub3D");
// 	box->img.img = mlx_new_image(box->mlx.ft_mlx, box->win.width, box->win.height);
// 	box->img.img_addr = (int *)mlx_get_data_addr(box->img.img, &box->img.bits_per_pixel, &box->img.size_line, &box->img.endian);
// 	box->pos.x = box->win.width / 2;
// 	box->pos.y = box->win.height / 2;
// 	box->dir.x = 1;
// 	box->dir.y = 0;
// }

int			ft_main_loop(t_box *box)
{
	mlx_clear_window(box->mlx.ft_mlx, box->mlx.ft_win);
	ft_background_init(box);
	// ft_clear_image(box);
	ft_draw_wall(box);
	ft_draw_grid(box);
	ft_draw_player(box);
	// ft_make_ray(box);
	ft_draw_3d(box);
	mlx_put_image_to_window(box->mlx.ft_mlx, box->mlx.ft_win, box->img.img, 0, 0);
	return (0);
}

int			main(void)
{
	t_box	*box;

	box = (t_box *)malloc(sizeof(t_box));
	ft_box_set(box);
	mlx_loop_hook(box->mlx.ft_mlx, ft_main_loop, box);
	mlx_hook(box->mlx.ft_win, 2, 0, &ft_key_press, box);//버튼이 눌렸을때
	mlx_hook(box->mlx.ft_win, 17, 0, &ft_exit, box);//창닫기 눌렀을때

	mlx_loop(box->mlx.ft_mlx);
	free(box);
	return (0);
}
