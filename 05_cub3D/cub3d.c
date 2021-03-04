/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:20 by junghwki          #+#    #+#             */
/*   Updated: 2021/03/04 16:29:13 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			map[10][10] =//row,col
	{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
	 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

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
				ft_make_wall(box, col, row);
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

void		ft_draw_dir(t_box *box)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	x = box->pos.x * box->win.width_len;
	y = box->pos.y * box->win.height_len;
	while(i < box->win.width_len / 2)
	{
		ft_pixel_put(box, x, y, 0x00FF00);
		i++;
		x += cos(box->pos.theta);
		y += sin(box->pos.theta);
	}
}

void		ft_draw_tex(t_box *box, double wall_height, int x)
{
	int		tex_index;
	int		y_index;
	int		y;
	int		height;
	int		y_tmp;

	y = 0;
	height = (box->win.height / 2) - wall_height;
	y_index = 0;
	if(height < 0)
	{
		y = 0;
		y_tmp = (int)((wall_height * 2) / height * -1);
		y_index = (int)box->e.height / y_tmp;
		height = 0;
	}
	if (box->comp.y && box->dir.x >= 0)//동쪽text = 1 buf[1][x]
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			if((int)(y_index * (wall_height * 2)) < (int)(y * box->e.height) && y_index < 63)
			{
				y_index = (int)(box->e.height * (double)(y / (wall_height * 2)));
			}
			tex_index = (int)((box->pos.tex * box->e.width) + (box->e.width * y_index));
			ft_pixel_put(box, x, y + height, box->e.addr[tex_index]);
			y++;
		}
	}
	// if (box->comp.y && box->dir.x >= 0)//동쪽text = 1 buf[1][x]
	// {
	// 	while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
	// 	{
	// 		if((int)(y_index / box->e.height) < (int)(y / wall_height * 2) && y_index < 63)
	// 		{
	// 			y_index++;
	// 			printf("y_i=%d y=%d\n",y_index,y);
	// 		}
	// 		tex_index = (int)((box->pos.tex * box->e.width) + (box->e.width * y_index));
	// 		ft_pixel_put(box, x, y + height, box->e.addr[tex_index]);
	// 		y++;
	// 	}
	// }
	else if (box->comp.y && box->dir.x < 0) //서쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			if((int)(y_index * (wall_height * 2)) <= (int)(y * box->w.height) && y_index < 63)
			{
				y_index = (int)(box->w.height * (double)(y / (wall_height * 2)));
			}
			tex_index = (int)(box->w.width - (box->pos.tex * box->w.width) + (box->w.width * y_index));
			ft_pixel_put(box, x, y + height, box->w.addr[tex_index]);
			y++;
		}
	}
	else if (box->comp.x && box->dir.y >= 0)//남쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			tex_index = (int)(box->s.width - (box->pos.tex * box->s.width) + (box->s.width * y_index));
			if((int)(y_index * (wall_height * 2)) <= (int)(y * box->s.height) && y_index < 63)
			{
				y_index = (int)(box->s.height * (double)(y / (wall_height * 2)));
			}
			ft_pixel_put(box, x, y + height, box->s.addr[tex_index]);
			y++;
		}
	}
	else if (box->comp.x && box->dir.y < 0)//북쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			tex_index = (int)((box->pos.tex * box->n.width) + (box->n.width * y_index));
			if((int)(y_index * (wall_height * 2) ) <= (int)(y * box->n.height) && y_index < 63)
			{
				y_index = (int)(box->n.height * (double)(y / (wall_height * 2)));
			}
			ft_pixel_put(box, x, y + height, box->n.addr[tex_index]);
			y++;
		}
	}
}

double		ft_wall_check(t_box *box, double theta)
{
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	rotate_theta;

	box->pos.map_x = (int)box->pos.x;
	box->pos.map_y = (int)box->pos.y;
	rotate_theta = ft_rot_theta(box, theta);
	box->dir = ft_theta_check(rotate_theta);
	delta_x = fabs(1 / cos(rotate_theta));
	delta_y = fabs(1 / sin(rotate_theta));
	// ft_draw_dir(box);
	if(box->dir.x < 0)
		side_x = (box->pos.x - box->pos.map_x) * delta_x;
	else
		side_x = (box->pos.map_x + 1 - box->pos.x) * delta_x;
	if(box->dir.y < 0)
		side_y = (box->pos.y - box->pos.map_y) * delta_y;
	else
		side_y = (box->pos.map_y + 1 - box->pos.y) * delta_y;
	box->comp.x = 0;
	box->comp.y = 0;
	while(map[box->pos.map_y][box->pos.map_x] == 0)
	{
		if(side_x < side_y)
		{
			box->pos.map_x += box->dir.x;
			if(map[box->pos.map_y][box->pos.map_x] == 1)
			{
				box->comp.y = 1;
				box->pos.tex = box->pos.y + (side_x * sin(rotate_theta)) - box->pos.map_y;
				return(side_x * cos(theta));
			}
			side_x += delta_x;
		}
		else
		{
			box->pos.map_y += box->dir.y;
			if(map[box->pos.map_y][box->pos.map_x] == 1)
			{        
				box->comp.x = 1;
				box->pos.tex = box->pos.x + (side_y * cos(rotate_theta)) - box->pos.map_x;
				return(side_y * cos(theta));
			}
			side_y += delta_y;
		}
	}
	return (0);
}

// void		ft_draw_3d(t_box *box)
// {
// 	int		x;
// 	double	ray_theta;
// 	double	wall_height;

// 	ray_theta = box->win.width / 2;
// 	x = box->win.width - 1;
// 	while (x >= 0)
// 	{
// 		wall_height = (box->win.height / ft_wall_check(box, ft_deg_to_rad((66 / (double)box->win.width) * ray_theta))) * 0.34;
// 		ft_draw_tex(box,wall_height, x);
// 		ray_theta--;
// 		x--;
// 	}
// }

void		ft_draw_3d(t_box *box)
{
	int		x;
	int		a;
	double	ray_theta;
	double	wall_height;

	a = -1 * (box->win.width / 2);
	x = 0;
	while (x < box->win.width)
	{
		ray_theta = atan(a / box->win.dis);
		wall_height = (box->win.height / (ft_wall_check(box, ray_theta))) * 0.66;
		ft_draw_tex(box, wall_height, x);
		a++;
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
	box->win.width = 400;
	box->win.height = 400;
	box->win.col = 10;
	box->win.row = 10;
	box->win.width_len = box->win.width / box->win.col;
	box->win.height_len = box->win.height / box->win.row;
	box->win.move_speed = 0.05;
	box->win.fov = ft_deg_to_rad(66);
	box->win.dis = box->win.width / tan(box->win.fov / 2);
	box->win.rotate_angle = ft_deg_to_rad(5);
	box->mlx.ft_mlx = mlx_init();
	box->mlx.ft_win = mlx_new_window(box->mlx.ft_mlx, box->win.width, box->win.height, "cub3D");
	box->img.img = mlx_new_image(box->mlx.ft_mlx, box->win.width, box->win.height);
	box->img.addr = (int *)mlx_get_data_addr(box->img.img, &box->img.bits_per_pixel, &box->img.size_line, &box->img.endian);

	box->e.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, "./texture/e.xpm", &box->e.width, &box->e.height);
	box->e.addr = (int *)mlx_get_data_addr(box->e.ptr, &box->e.bits_per_pixel, &box->e.size_line, &box->e.endian);
	box->w.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, "./texture/w.xpm", &box->w.width, &box->w.height);
	box->w.addr = (int *)mlx_get_data_addr(box->w.ptr, &box->img.bits_per_pixel, &box->w.size_line, &box->w.endian);
	box->s.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, "./texture/s.xpm", &box->s.width, &box->s.height);
	box->s.addr = (int *)mlx_get_data_addr(box->s.ptr, &box->img.bits_per_pixel, &box->s.size_line, &box->s.endian);
	box->n.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, "./texture/n.xpm", &box->n.width, &box->n.height);
	box->n.addr = (int *)mlx_get_data_addr(box->n.ptr, &box->img.bits_per_pixel, &box->n.size_line, &box->n.endian);
	
	box->pos.x = box->win.col / 2;
	box->pos.y = box->win.row / 2;
	box->pos.theta = ft_deg_to_rad(180);
}

int			ft_main_loop(t_box *box)
{
	mlx_clear_window(box->mlx.ft_mlx, box->mlx.ft_win);
	ft_background_init(box);
	// ft_clear_image(box);
	ft_draw_3d(box);
	// ft_draw_wall(box);
	// ft_draw_grid(box);
	// ft_draw_player(box);
	// ft_make_ray(box, 0);
	mlx_put_image_to_window(box->mlx.ft_mlx, box->mlx.ft_win, box->img.img, 0, 0);
	// mlx_put_image_to_window(box->mlx.ft_mlx, box->mlx.ft_win, box->w.ptr, 0, 0);
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
