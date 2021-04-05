/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:20 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/05 18:40:43 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	ft_sprt_pos(t_box *box)
{
	int i;
	int j;
	int k;

	k = 0;
	j = 0;
	while (j < box->win.row)
	{
		i = 0;
		while (i < box->win.col)
		{
			if (box->win.map[j][i] == '2')
			{
				box->sprt[k].x = i + 0.5;
				box->sprt[k].y = j + 0.5;
				k++;
			}
			i++;
		}
		j++;
	}
}

void	ft_sprt_calc(t_box *box)
{
	int i;
	int j;

	i = 0;
	box->pos.visible_num = 0;
	ft_visible_init(box);
	while (i < box->pars.s_cnt)
	{
		box->sprt[i].angle = atan2(box->sprt[i].y - box->pos.y, box->sprt[i].x - box->pos.x);
		if ((box->sprt[i].angle < box->pos.theta + ft_deg_to_rad(70) && box->sprt[i].angle > box->pos.theta + ft_deg_to_rad(-70)) ||
		(box->sprt[i].angle + M_PI * 2 < box->pos.theta + (ft_deg_to_rad(70)) && box->sprt[i].angle + M_PI * 2 > box->pos.theta + (ft_deg_to_rad(-70))) ||
		(box->sprt[i].angle - M_PI * 2 < box->pos.theta + (ft_deg_to_rad(70)) && box->sprt[i].angle - M_PI * 2 > box->pos.theta + (ft_deg_to_rad(-70))))
		{
			box->pos.visible_num++;
			box->sprt[i].visible = 1;
			box->sprt[i].dist = ft_dist_calc(box->sprt[i].y - box->pos.y, box->sprt[i].x - box->pos.x) * cos(box->sprt[i].angle - box->pos.theta);
		}
		i++;
	}
	ft_make_visible_array(box);
	ft_sort_sprt(box);;
}

void 	ft_draw_tex(t_box *box, double wall_height, int x)
{
	int y;
	int height;
	int y_idx;
	int tex_idx;

	y = 0;
	height = (box->win.height / 2) - wall_height;
	y_idx = 0;
	if (box->comp.y && box->pos.dir.x >= 0) //동쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			if ((int)(y_idx * (wall_height * 2)) < (int)(y * box->ea.height))
				y_idx = (int)(box->ea.height * (double)(y / (wall_height * 2)));
			tex_idx = (int)((box->pos.tex * box->ea.width) + (box->ea.width * y_idx));
			if (y + height >= 0 && tex_idx < box->ea.width * box->ea.height)
				ft_pixel_put(box, x, y + height, box->ea.addr[tex_idx]);
			y++;
		}
	}
	else if (box->comp.y && box->pos.dir.x < 0) //서쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			if ((int)(y_idx * (wall_height * 2)) < (int)(y * box->we.height))
				y_idx = (int)(box->we.height * (double)(y / (wall_height * 2)));
			tex_idx = (int)(box->we.width - (box->pos.tex * box->we.width) + (box->we.width * y_idx));
			if (y + height >= 0 && tex_idx < box->we.width * box->we.height)
				ft_pixel_put(box, x, y + height, box->we.addr[tex_idx]);
			y++;
		}
	}
	else if (box->comp.x && box->pos.dir.y >= 0) //남쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			if ((int)(y_idx * (wall_height * 2)) < (int)(y * box->so.height))
				y_idx = (int)(box->so.height * (double)(y / (wall_height * 2)));
			tex_idx = (int)(box->so.width - (box->pos.tex * box->so.width) + (box->so.width * y_idx));
			if (y + height >= 0 && tex_idx < box->so.width * box->so.height)
				ft_pixel_put(box, x, y + height, box->so.addr[tex_idx]);
			y++;
		}
	}
	else if (box->comp.x && box->pos.dir.y < 0) //북쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			if ((int)(y_idx * (wall_height * 2)) < (int)(y * box->no.height))
				y_idx = (int)(box->no.height * (double)(y / (wall_height * 2)));
			tex_idx = (int)((box->pos.tex * box->no.width) + (box->no.width * y_idx));
			if (y + height >= 0 && tex_idx < box->no.width * box->no.height)
				ft_pixel_put(box, x, y + height, box->no.addr[tex_idx]);
			y++;
		}
	}
}

double 	ft_wall_check(t_box *box, double theta)
{
	double delta_x;
	double delta_y;
	double side_x;
	double side_y;
	double rotate_theta;

	box->pos.map_x = (int)box->pos.x;
	box->pos.map_y = (int)box->pos.y;
	rotate_theta = ft_rot_angle(box->pos.theta, theta);
	box->pos.dir = ft_theta_check(rotate_theta);
	delta_x = fabs(1 / cos(rotate_theta));
	delta_y = fabs(1 / sin(rotate_theta));
	if (box->pos.dir.x < 0)
		side_x = (box->pos.x - box->pos.map_x) * delta_x;
	else
		side_x = (box->pos.map_x + 1 - box->pos.x) * delta_x;
	if (box->pos.dir.y < 0)
		side_y = (box->pos.y - box->pos.map_y) * delta_y;
	else
		side_y = (box->pos.map_y + 1 - box->pos.y) * delta_y;
	while (box->win.map[box->pos.map_y][box->pos.map_x] != '1')
	{
		if (side_x < side_y)
		{
			box->pos.map_x += box->pos.dir.x;
			if (box->win.map[box->pos.map_y][box->pos.map_x] == '1')
			{
				box->comp.y = 1;
				box->pos.tex = box->pos.y + (side_x * sin(rotate_theta)) - box->pos.map_y;
				return (side_x * cos(theta));
			}
			side_x += delta_x;
		}
		else
		{
			box->pos.map_y += box->pos.dir.y;
			if (box->win.map[box->pos.map_y][box->pos.map_x] == '1')
			{
				box->comp.x = 1;
				box->pos.tex = box->pos.x + (side_y * cos(rotate_theta)) - box->pos.map_x;
				return (side_y * cos(theta));
			}
			side_y += delta_y;
		}
	}
	return (0);
}

// void	ft_sprite(t_box *box, double sprt_len, int sprt_x)
// {
// 	int	x;
// 	int	y;
// 	double	x_idx;
// 	double	y_idx;
// 	int start_x;
// 	int start_y;

// 	x = 0;
// 	y = 0;
// 	start_x = sprt_x - sprt_len;
// 	start_y = (box->win.height / 2) - sprt_len;
// 	while (y < (2 * sprt_len) - 1)
// 	{
// 			x_idx = (double)(box->s.width / (sprt_len * 2));
// 			y_idx = (double)(box->s.height / (sprt_len * 2));
// 		x = 0;
// 		while (x < (2 * sprt_len) - 1)
// 		{
// 			if (start_x + x > 0 && start_x + x < box->win.width &&
// 				start_y + y > 0 && start_y + y < box->win.height &&
// 				box->s.addr[(int)(x_idx * x) + ((int)(y_idx * y) * box->s.width)] &&
// 				box->pos.x_height[start_x + x] < sprt_len)
// 				ft_pixel_put(box, start_x + x, start_y + y, box->s.addr[(int)(x_idx * x) + ((int)(y_idx * y) * box->s.width)]);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	ft_sprt_check(t_box *box)
// {
// 	double	sprt_angle;
// 	double	sprt_dis;
// 	int 	i;
// 	int		start_x;
// 	double	sprt_height;

// 	i = 0;
// 	while (i < box->pos.visible_num)
// 	{
// 		sprt_angle = ft_rot_angle(box->visible[i].angle, -1 * box->pos.theta);
// 		sprt_height = (box->win.height / box->visible[i].dist) / 2;
// 		sprt_dis = tan(sprt_angle) * box->win.dis;
// 		start_x = (int)((box->win.width / 2) + sprt_dis);
// 		ft_sprite(box, sprt_height, start_x);
// 		i++;
// 	}
// }

void 	ft_draw_fov(t_box *box)
{
	int x;
	int ray;
	double ray_theta;

	x = 0;
	ray = -1 * (box->win.width / 2);
	while (x < box->win.width)
	{
		ray_theta = atan(ray / box->win.dis);
		box->pos.x_height[x] = (box->win.height / ft_wall_check(box, ray_theta)) / 2;
		ft_draw_tex(box, box->pos.x_height[x], x);
		box->comp.x = 0;
		box->comp.y = 0;
		ray++;
		x++;
	}
}

int 	ft_main_loop(t_box *box)
{
	mlx_clear_window(box->mlx.ft_mlx, box->mlx.ft_win);
	ft_background_init(box);
	ft_draw_fov(box);
	ft_sprt_calc(box);
	ft_sprt_check(box);
	if (box->key.m)
	{
		ft_draw_wall(box);
		ft_draw_grid(box);
		ft_draw_dir(box);
		ft_draw_player(box);
	}
	ft_key_function(box);
	mlx_put_image_to_window(box->mlx.ft_mlx, box->mlx.ft_win, box->img.img, 0, 0);
	return (0);
}

int 	main(void) //int argc, char *argv[])
{
	t_box *box;
	int fd;

	fd = open("./test.cub", O_RDONLY);
	// if(argc == 2)
	// {
	box = (t_box *)malloc(sizeof(t_box));
	box->mlx.ft_mlx = mlx_init();
	ft_get_map(box, fd);
	ft_box_set(box);
	mlx_loop_hook(box->mlx.ft_mlx, ft_main_loop, box);
	mlx_hook(box->mlx.ft_win, 2, 0, &ft_key_press, box);   //버튼이 눌렸을때
	mlx_hook(box->mlx.ft_win, 3, 0, &ft_key_release, box); //버튼 땠을때
	mlx_hook(box->mlx.ft_win, 17, 0, &ft_exit, box);	   //창닫기 눌렀을때

	mlx_loop(box->mlx.ft_mlx);
	free(box);
	// }
	return (0);
}
