/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:20 by junghwki          #+#    #+#             */
/*   Updated: 2021/03/17 21:58:14 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_sprt_swap(t_sprt *a, t_sprt *b)
{
	t_sprt temp;

	if (a->dist < b->dist)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

double ft_dist_calc(double x, double y)
{
	return (fabs(sqrt(pow(x, 2) + pow(y, 2))));
}

void ft_sprt_pos(t_box *box)
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

void ft_sprt_calc(t_box *box)
{
	int i;
	int j;

	i = 0;
	j = 0;
	box->pos.visible_num = 0;
	while (i < box->pars.s_cnt)
	{
		box->sprt[i].angle = ft_rot_angle(0, atan2(box->sprt[i].y - box->pos.y, box->sprt[i].x - box->pos.x));
		if (box->sprt[i].angle >= ft_rot_angle(box->pos.theta, -1 * (box->win.fov / 2)) && box->sprt[i].angle <= ft_rot_angle(box->pos.theta, (box->win.fov / 2)))
		{
			box->pos.visible_num++;
			box->sprt[i].visible = 1;
			box->sprt[i].dist = ft_dist_calc(box->sprt[i].y - box->pos.y, box->sprt[i].x - box->pos.x) * cos(box->sprt[i].angle -  box->pos.theta);
			// printf("x=%f\n",box->sprt[i].dist);
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < box->pars.s_cnt)//////////시야안에 있는 구조체를 visible구조체로 복사
	{
		if (box->sprt[i].visible)
		{
			box->visible[j] = box->sprt[i];
			j++;
		}
		i++;
	}
	j = 0;
	while (j < box->pos.visible_num - 1)///////////구조체 정렬
	{
		i = 0;
		while (i < box->pos.visible_num - j - 1)
		{
			ft_sprt_swap(&box->visible[i], &box->visible[i + 1]);
			i++;
		}
		j++;
	}
	// i = 0;
	// while(i < box->pos.visible_num)
	// {
	// 	printf("%f  %d\n",box->visible[i].dist,i);
	// 	i++;
	// }
}

void ft_nbr_check(char *nbr)
{
	while (*nbr)
	{
		if (!(ft_isdigit(*nbr)))
			ft_error();
		nbr++;
	}
}

void ft_map_print(t_box *box)
{
	int i;

	i = 0;
	while (i < box->win.row)
	{
		printf("%s\n", box->win.map[i]);
		i++;
	}
}

void ft_make_base(t_box *box)
{
	int i;
	int j;

	i = 0;
	box->win.map = (char **)malloc(sizeof(char *) * (box->win.row + 1));
	while (i < box->win.row)
	{
		box->win.map[i] = (char *)malloc(box->win.col + 1);
		i++;
	}
	j = 0;
	while (j < box->win.row)
	{
		i = 0;
		while (i < box->win.col)
		{
			box->win.map[j][i] = ' ';
			i++;
		}
		box->win.map[j][i] = '\0';
		j++;
	}
}

void ft_get_map(t_box *box, int fd)
{
	char **temp;

	ft_pars_init(box);
	while (get_next_line(fd, &box->pars.line) > 0)
	{
		box->pars.word = ft_split(box->pars.line, ' ');
		if (!(*box->pars.word)) //개행 처리
			continue;
		if (ft_check_flag(box)) //플래그 다들어왔나 확인
		{
			if (!(box->pars.map))
				box->pars.map = ft_strdup(box->pars.line);
			else
			{
				if (box->win.col < ft_strlen(box->pars.line))
					box->win.col = ft_strlen(box->pars.line);
				box->pars.map = ft_strjoin(box->pars.map, "#");
				box->pars.map = ft_strjoin(box->pars.map, box->pars.line);
			}
			box->win.row++;
		}
		else if (!(ft_strcmp(box->pars.word[0], "R")) && ft_rowlen(box->pars.word) == 3)
		{
			if (box->pars.r_flag)
				ft_error();
			ft_nbr_check(box->pars.word[1]);
			ft_nbr_check(box->pars.word[2]);
			box->win.width = ft_atoi(box->pars.word[1]);
			box->win.height = ft_atoi(box->pars.word[2]);
			box->pars.r_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "EA")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.ea_flag)
				ft_error();
			box->ea.route = ft_strdup(box->pars.word[1]);
			if (open(box->ea.route, O_RDONLY) < 0)
				ft_error();
			box->pars.ea_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "WE")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.we_flag)
				ft_error();
			box->we.route = ft_strdup(box->pars.word[1]);
			if (open(box->we.route, O_RDONLY) < 0)
				ft_error();
			box->pars.we_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "SO")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.so_flag)
				ft_error();
			box->so.route = ft_strdup(box->pars.word[1]);
			if (open(box->so.route, O_RDONLY) < 0)
				ft_error();
			box->pars.so_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "NO")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.no_flag)
				ft_error();
			box->no.route = ft_strdup(box->pars.word[1]);
			if (open(box->no.route, O_RDONLY) < 0)
				ft_error();
			box->pars.no_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "S")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.s_flag)
				ft_error();
			box->s.route = ft_strdup(box->pars.word[1]);
			if (open(box->s.route, O_RDONLY) < 0)
				ft_error();
			box->pars.s_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "C")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.c_flag)
				ft_error();
			temp = ft_split(box->pars.word[1], ',');
			if (ft_rowlen(temp) != 3)
				ft_error();
			ft_nbr_check(temp[0]);
			ft_nbr_check(temp[1]);
			ft_nbr_check(temp[2]);
			if (ft_atoi(temp[0]) > 255)
				ft_error();
			box->win.c_color = ft_atoi(temp[0]);
			box->win.c_color *= 256;
			if (ft_atoi(temp[1]) > 255)
				ft_error();
			box->win.c_color += ft_atoi(temp[1]);
			box->win.c_color *= 256;
			if (ft_atoi(temp[2]) > 255)
				ft_error();
			box->win.c_color += ft_atoi(temp[2]);
			// ft_array_free(temp);
			box->pars.c_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "F")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.f_flag)
				ft_error();
			temp = ft_split(box->pars.word[1], ',');
			if (ft_rowlen(temp) != 3)
				ft_error();
			ft_nbr_check(temp[0]);
			ft_nbr_check(temp[1]);
			ft_nbr_check(temp[2]);
			if (ft_atoi(temp[0]) > 255)
				ft_error();
			box->win.f_color = ft_atoi(temp[0]);
			box->win.f_color *= 256;
			if (ft_atoi(temp[1]) > 255)
				ft_error();
			box->win.f_color += ft_atoi(temp[1]);
			box->win.f_color *= 256;
			if (ft_atoi(temp[2]) > 255)
				ft_error();
			box->win.f_color += ft_atoi(temp[2]);
			// ft_array_free(temp);
			box->pars.f_flag = 1;
		}
		else
			ft_error();
		// ft_array_free(box->pars.word);
	}
	temp = ft_split(box->pars.map, '#');
	ft_make_base(box);
	ft_map_dup(box, temp);
	// ft_array_free(temp);
	// ft_map_print(box);
	ft_map_check(box);
	box->sprt = (t_sprt *)malloc(sizeof(t_sprt) * box->pars.s_cnt);
	box->visible = (t_sprt *)malloc(sizeof(t_sprt) * box->pars.s_cnt);
	// printf("%d\n",box->pars.s_cnt);
	ft_sprt_pos(box);
}

void ft_draw_dir(t_box *box)
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

void ft_draw_tex(t_box *box, double wall_height, int x)
{
	int y;
	int height;
	int y_index;
	int tex_index;

	y = 0;
	height = (box->win.height / 2) - wall_height;
	y_index = 0;
	if (box->comp.y && box->dir.x >= 0) //동쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			if ((int)(y_index * (wall_height * 2)) < (int)(y * box->ea.height))
				y_index = (int)(box->ea.height * (double)(y / (wall_height * 2)));
			tex_index = (int)((box->pos.tex * box->ea.width) + (box->ea.width * y_index));
			if (y + height >= 0 && tex_index < box->ea.width * box->ea.height)
				ft_pixel_put(box, x, y + height, box->ea.addr[tex_index]);
			y++;
		}
	}
	else if (box->comp.y && box->dir.x < 0) //서쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			if ((int)(y_index * (wall_height * 2)) < (int)(y * box->we.height))
				y_index = (int)(box->we.height * (double)(y / (wall_height * 2)));
			tex_index = (int)(box->we.width - (box->pos.tex * box->we.width) + (box->we.width * y_index));
			if (y + height >= 0 && tex_index < box->we.width * box->we.height)
				ft_pixel_put(box, x, y + height, box->we.addr[tex_index]);
			y++;
		}
	}
	else if (box->comp.x && box->dir.y >= 0) //남쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			if ((int)(y_index * (wall_height * 2)) < (int)(y * box->so.height))
				y_index = (int)(box->so.height * (double)(y / (wall_height * 2)));
			tex_index = (int)(box->so.width - (box->pos.tex * box->so.width) + (box->so.width * y_index));
			if (y + height >= 0 && tex_index < box->so.width * box->so.height)
				ft_pixel_put(box, x, y + height, box->so.addr[tex_index]);
			y++;
		}
	}
	else if (box->comp.x && box->dir.y < 0) //북쪽
	{
		while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
		{
			if ((int)(y_index * (wall_height * 2)) < (int)(y * box->no.height))
				y_index = (int)(box->no.height * (double)(y / (wall_height * 2)));
			tex_index = (int)((box->pos.tex * box->no.width) + (box->no.width * y_index));
			if (y + height >= 0 && tex_index < box->no.width * box->no.height)
				ft_pixel_put(box, x, y + height, box->no.addr[tex_index]);
			y++;
		}
	}
}

double ft_wall_check(t_box *box, double theta)
{
	double delta_x;
	double delta_y;
	double side_x;
	double side_y;
	double rotate_theta;

	box->pos.map_x = (int)box->pos.x;
	box->pos.map_y = (int)box->pos.y;
	rotate_theta = ft_rot_angle(box->pos.theta, theta);
	box->dir = ft_theta_check(rotate_theta);
	delta_x = fabs(1 / cos(rotate_theta));
	delta_y = fabs(1 / sin(rotate_theta));
	ft_draw_dir(box);
	if (box->dir.x < 0)
		side_x = (box->pos.x - box->pos.map_x) * delta_x;
	else
		side_x = (box->pos.map_x + 1 - box->pos.x) * delta_x;
	if (box->dir.y < 0)
		side_y = (box->pos.y - box->pos.map_y) * delta_y;
	else
		side_y = (box->pos.map_y + 1 - box->pos.y) * delta_y;
	while (box->win.map[box->pos.map_y][box->pos.map_x] != '1')
	{
		if (side_x < side_y)
		{
			box->pos.map_x += box->dir.x;
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
			box->pos.map_y += box->dir.y;
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

void	ft_draw_sprite(t_box *box, double sprt_height, int x, double tex_x)
{
	int y;
	int height;
	int y_index;
	int tex_index;

	y = 0;
	height = (box->win.height / 2) - sprt_height;
	y_index = 0;
	while ((y < (sprt_height * 2) - 1) && (y + height < box->win.height))
	{
		if ((int)(y_index * (sprt_height * 2)) < (int)(y * box->s.height))
			y_index = (int)(box->s.height * (double)(y / (sprt_height * 2)));
		tex_index = (int)((tex_x * box->s.width) + (box->s.width * y_index));
		if (y + height >= 0 && tex_index < box->s.width * box->s.height && box->s.addr[tex_index])
			ft_pixel_put(box, x, y + height, box->s.addr[tex_index]);
		y++;
	}
}

void	ft_sprite_check(t_box *box)
{
	double	sprt_angle;
	int		sprt_dis;
	int 	i;
	int		start_x;
	double	sprt_height;
	int k;
	int j;

	j = 0;

	i = 0;
	while(i < box->pos.visible_num)
	{
		sprt_angle = box->pos.theta - box->visible[i].angle;
		sprt_height = (box->win.height / box->visible[i].dist) / 2;
		{
			sprt_dis = (sprt_angle * box->win.width) / box->win.fov;
			start_x = (int)((box->win.width / 2) + sprt_dis - (sprt_height / 2));
			k = -1 * sprt_height / 2;
			while (k < sprt_height / 2)
			{
				if(start_x + k >= 0)
					ft_draw_sprite(box, sprt_height, start_x + k, j / sprt_height);
				k++;
				j++;
			}		
		}
		i++;
	}
}

void ft_draw_fov(t_box *box)
{
	int x;
	int ray;
	double ray_theta;
	double wall_height;

	x = 0;
	ray = -1 * (box->win.width / 2);
	// box->pos.min_angle = box->pos.tehta - 45;
	// box->pos.max_angle = box->pos.theta + 45;
	while (x < box->win.width)
	{
		ray_theta = atan(ray / box->win.dis);
		wall_height = (box->win.height / (ft_wall_check(box, ray_theta))) / 2;
		ft_draw_tex(box, wall_height, x);
		box->comp.x = 0;
		box->comp.y = 0;
		ray++;
		x++;
	}
}

int ft_key_press(int keycode, t_box *box)
{
	if (keycode == 13) //W
		box->key.w = 1;
	else if (keycode == 1) //S
		box->key.s = 1;
	else if (keycode == 0) //A
		box->key.a = 1;
	else if (keycode == 2) //D
		box->key.d = 1;
	else if (keycode == 123) //좌측 방향키123
		box->key.left = 1;
	else if (keycode == 124) //우측 방향키124
		box->key.right = 1;
	else if (keycode == 53) //esc
		exit(0);
	return (0);
}

int ft_key_release(int keycode, t_box *box)
{
	if (keycode == 13) //W
		box->key.w = 0;
	else if (keycode == 1) //S
		box->key.s = 0;
	else if (keycode == 0) //A
		box->key.a = 0;
	else if (keycode == 2) //D
		box->key.d = 0;
	else if (keycode == 123) //좌측 방향키123
		box->key.left = 0;
	else if (keycode == 124) //우측 방향키124
		box->key.right = 0;
	return (0);
}

int ft_player_move(t_box *box)
{
	if (box->key.w) //W
		ft_move_up(box);
	if (box->key.s) //S
		ft_move_down(box);
	if (box->key.a) //A
		ft_move_left(box);
	if (box->key.d) //D
		ft_move_right(box);
	if (box->key.left) //좌측 방향키
		ft_rotate_left(box);
	if (box->key.right) //우측 방향키
		ft_rotate_right(box);
	return (0);
}

void ft_box_set(t_box *box)
{
	box->win.width_len = box->win.width / box->win.col;
	box->win.height_len = box->win.height / box->win.row;
	box->win.move_speed = 0.06;
	box->win.fov = ft_deg_to_rad(90);
	box->win.dis = box->win.width / tan(box->win.fov / 2);
	box->win.rotate_angle = ft_deg_to_rad(3);
	box->mlx.ft_mlx = mlx_init();
	box->mlx.ft_win = mlx_new_window(box->mlx.ft_mlx, box->win.width, box->win.height, "cub3D");
	// box->pos.visible_num = 0;
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
}

int ft_main_loop(t_box *box)
{
	mlx_clear_window(box->mlx.ft_mlx, box->mlx.ft_win);
	ft_player_move(box);
	ft_background_init(box);
	// ft_clear_image(box);
	ft_draw_fov(box);
		ft_sprt_calc(box);
		ft_sprite_check(box);
	// ft_draw_wall(box);
	// ft_draw_grid(box);
	// ft_draw_player(box);
	mlx_put_image_to_window(box->mlx.ft_mlx, box->mlx.ft_win, box->img.img, 0, 0);
	mlx_put_image_to_window(box->mlx.ft_mlx, box->mlx.ft_win, box->s.addr, 0, 0);
	return (0);
}

int main(void) //int argc, char *argv[])
{
	t_box *box;
	int fd;

	fd = open("./test.cub", O_RDONLY);
	// if(argc == 2)
	// {
	box = (t_box *)malloc(sizeof(t_box));
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
