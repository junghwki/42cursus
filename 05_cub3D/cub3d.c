/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:08:48 by junghwki          #+#    #+#             */
/*   Updated: 2020/12/04 17:11:46 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			map[10][10] =//row,col
	{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	 {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
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

void		ft_draw_ray(t_box *box)
{
	double	dis_x;
	double	dis_y;
	t_vec	left_dis;

	dis_x = (int)box->pos.x;
	dis_y = (int)box->pos.y;
	while(map[(int)(dis_y / box->win.height_len)][(int)(dis_x / box->win.width_len)] == 0)//(int)dis_x % (int)box->win.width_len && (int)dis_y % (int)box->win.height_len &&
	{
		ft_pixel_put(box, dis_x, dis_y, 0x00FF00);
		dis_x += box->dis.x; //++;
		dis_y += box->dis.y; // += (int)(box->dis.x / box->dis.y);
	}
	// dis_x = (int)box->pos.x;
	// dis_y = (int)box->pos.y;
	// left_dis = ft_rot_vec(box->dis, box->win.rotate_angle);
	// while(map[(int)(dis_y / box->win.height_len)][(int)(dis_x / box->win.width_len)] == 0)//(int)dis_x % (int)box->win.width_len && (int)dis_y % (int)box->win.height_len &&
	// {
	// 	ft_pixel_put(box, dis_x, dis_y, 0x00FF00);
	// 	dis_x += left_dis.x; //++;
	// 	dis_y += left_dis.y; // += (int)(box->dis.x / box->dis.y);
	// }
	// dis_x = (int)box->pos.x;
	// dis_y = (int)box->pos.y;
	// left_dis = ft_rot_vec(box->dis, (box->win.rotate_angle * -1));
	// while(map[(int)(dis_y / box->win.height_len)][(int)(dis_x / box->win.width_len)] == 0)//(int)dis_x % (int)box->win.width_len && (int)dis_y % (int)box->win.height_len &&
	// {
	// 	ft_pixel_put(box, dis_x, dis_y, 0x00FF00);
	// 	dis_x += left_dis.x; //++;
	// 	dis_y += left_dis.y; // += (int)(box->dis.x / box->dis.y);
	// }
}

// void		ft_draw_ray(t_box *box)
// {
// 	int		index;
// 	double	dis_x;
// 	double	dis_y;

// 	index = 0;
// 	dis_x = (int)box->pos.x;
// 	dis_y = (int)box->pos.y;
// 	if(ft_gradient_cmp(box->dis.x,box->dis.y))//x의 절대값이 크거나 같으면
// 	{
// 		while((int)dis_x % (int)box->win.width_len && index < 50)
// 		{
// 			ft_pixel_put(box, dis_x, dis_y, 0x00FF00);
// 			if(box->dis.y)
// 			{	
// 				dis_x++;
// 				dis_y += (int)(box->dis.x / box->dis.y);
// 			}
// 			index++;
// 			// if(map[(int)(dis_x - box->win.width_len) / (int)box->win.width_len][(int)(dis_y - box->win.width_len) / (int)box->win.width_len] == 0)
// 			// {
// 			// 	mlx_pixel_put(box->m.ft_mlx, box->m.ft_win, dis_x, dis_y, 0x00FF00);
// 				// dis_x += box->dis.x;
// 				// dis_y += box->dis.y;
// 			// }
// 		// ft_where_am_i(box, ft_new_vec(dis_x, dis_y));
// 		}
// 	}
// 	else//y의 절대값이 크면
// 	{
// 		while((int)dis_y % (int)box->win.height_len && index < 50)
// 		{
// 			ft_pixel_put(box, dis_x, dis_y, 0x00FF00);
// 			if(box->dis.x)
// 			{
// 				dis_y++;
// 				dis_x += (int)(box->dis.y / box->dis.x);
// 			}
// 			index++;
// 			// if(map[(int)(dis_x - box->win.width_len) / (int)box->win.width_len][(int)(dis_y - box->win.width_len) / (int)box->win.width_len] == 0)
// 			// {
// 			// 	mlx_pixel_put(box->m.ft_mlx, box->m.ft_win, dis_x, dis_y, 0x00FF00);
// 			// 	dis_x += box->dis.x;
// 			// 	dis_y += box->dis.y;
// 			// }
// 		}
// 	}
// }

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
	box->win.width = 500;
	box->win.height = 500;
	box->win.col = 10;
	box->win.row = 10;
	box->win.width_len = box->win.width / box->win.col;
	box->win.height_len = box->win.height / box->win.row;
	box->win.move_speed = 5;
	box->win.rotate_angle = ft_deg_to_rad(3);
	box->m.ft_mlx = mlx_init();
	box->m.ft_win = mlx_new_window(box->m.ft_mlx, box->win.width, box->win.height, "cub3D");
	box->i.img = mlx_new_image(box->m.ft_mlx, box->win.width, box->win.height);
	box->i.img_addr = (int *)mlx_get_data_addr(box->i.img, &box->i.bits_per_pixel, &box->i.size_line, &box->i.endian);
	box->pos.x = box->win.width / 2 + 25;
	box->pos.y = box->win.height / 2 + 25;
	box->dis.x = 0;
	box->dis.y = -1;
}

int			ft_main_loop(t_box *box)
{
	mlx_clear_window(box->m.ft_mlx, box->m.ft_win);
	// ft_background_init(box);
	ft_clear_image(box);
	ft_draw_wall(box);
	ft_draw_grid(box);
	ft_draw_player(box);
	ft_draw_ray(box);
	mlx_put_image_to_window(box->m.ft_mlx, box->m.ft_win, box->i.img, 0, 0);
	return (0);
}

int			main(void)
{
	t_box	*box;

	box = (t_box *)malloc(sizeof(t_box));
	ft_box_set(box);
	mlx_loop_hook(box->m.ft_mlx, ft_main_loop, box);
	mlx_hook(box->m.ft_win, 2, 0, &ft_key_press, box);//버튼이 눌렸을때
	mlx_hook(box->m.ft_win, 17, 0, &ft_exit, box);//창닫기 눌렀을때

	mlx_loop(box->m.ft_mlx);
	free(box);
	return (0);
}
