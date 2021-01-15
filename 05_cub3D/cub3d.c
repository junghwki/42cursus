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

int g_map[10][10] =
	{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int ft_player_set(t_box *box)
{
	int start_x;
	int start_y;

	start_y = box->player_y + 5;
	while (start_y >= box->player_y - 5)
	{
		start_x = box->player_x + 5;
		while (start_x >= box->player_x - 5)
		{
			mlx_pixel_put(box->ft_mlx, box->ft_win, start_x, start_y, 0xFF0000);
			start_x -= 1;
		}
		start_y -= 1;
	}
	return (0);
}

int ft_grid_set(t_box *box)
{
	int x;
	int y;

	y = box->win_height;
	while (y > 0)
	{
		x = box->win_width;
		while (x >= 0)
		{
			mlx_pixel_put(box->ft_mlx, box->ft_win, x, y, 0x00FF00);
			x -= 1;
		}
		y -= (box->win_height / 10);
	}
	x = box->win_width;
	while (x > 0)
	{
		y = box->win_height;
		while (y >= 0)
		{
			mlx_pixel_put(box->ft_mlx, box->ft_win, x, y, 0x00FF00);
			y -= 1;
		}
		x -= (box->win_width / 10);
	}
	return (0);
}

int ft_key_press(int keycode, t_box *box)
{
	if (keycode == 13)
		box->player_y -= 10;
	else if (keycode == 1)
		box->player_y += 10;
	else if (keycode == 0)
		box->player_x -= 10;
	else if (keycode == 2)
		box->player_x += 10;
	else if (keycode == 53)
		exit(0);
	return (0);
}

int ft_exit(t_box *box)
{
	exit(0);
	return (0);
}

int ft_fill_square(int x, int y, t_box *box)
{
	int start_x;
	int start_y;

	start_x = x;
	start_y = y;
	while (y < start_y + box->win_height / 10)
	{
		x = start_x;
		while (x < start_x + box->win_width / 10)
		{
			mlx_pixel_put(box->ft_mlx, box->ft_win, x, y, 0xFF00FF);
			x++;
		}
		y++;
	}
	return (0);
}

int ft_make_wall(t_box *box)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (g_map[i][j] == 1)
				ft_fill_square((box->win_width / 10) * j, (box->win_height / 10) * i, box);
			j++;
		}
		i++;
	}
	return (0);
}

int ft_make_img(t_box *box)
{
	int bits_per_pixel;
	int size_line;
	int endian;
	int i;
	int j;

	printf("why");
	box->img = mlx_new_image(box->ft_mlx, box->win_width / 10, box->win_height / 10);
	box->img_addr = (int *)mlx_get_data_addr(box->img, &bits_per_pixel, &size_line, &endian);
	printf("\nwhy?");
	// printf("%p, %p,%p,%p", box->img_addr, &bits_per_pixel, &size_line, &endian);
	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			box->img_addr[i * 50 + j] = 0xFFFF00;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(box->ft_mlx, box->ft_win, box->img, 0, 0);
	return (0);

}

void ft_box_set(t_box *box)
{
	box->win_width = 600;
	box->win_height = 600;
	box->ft_mlx = mlx_init();
	box->ft_win = mlx_new_window(box->ft_mlx, box->win_width, box->win_height, "cub3D");
	box->player_x = 100;//box->win_width / 2;
	box->player_y = 100;//box->win_height / 2;
}

int ft_main_loop(t_box *box)
{
	mlx_clear_window(box->ft_mlx, box->ft_win);
	ft_player_set(box);
	// ft_make_wall(box);
	ft_grid_set(box);
	ft_make_img(box);
	return (0);
}

int main(void)
{
	t_box *box;

	box = (t_box *)malloc(sizeof(t_box));
	ft_box_set(box);
	// ft_make_img(box);
	mlx_loop_hook(box->ft_mlx, ft_main_loop, box);
	mlx_hook(box->ft_win, 2, 0, &ft_key_press, box);//버튼이 눌렸을때
	mlx_hook(box->ft_win, 17, 0, &ft_exit, box);//x눌렀을때
	////////////////////////////////////////////////////////////////////
	mlx_loop(box->ft_mlx);
	return (0);
}
