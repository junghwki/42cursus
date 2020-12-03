/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:08:48 by junghwki          #+#    #+#             */
/*   Updated: 2020/12/03 14:14:49 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void			ft_player_set(t_b_list *box)
{
	int			start_x;
	int			start_y;

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
}

int				ft_grid_set(t_b_list *box)
{
	int			x;
	int			y;

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

int				ft_key_press(int keycode, t_b_list *box)
{
	// mlx_clear_window(box->ft_mlx, box->ft_win);
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
	ft_player_set(box);
	return (0);
}

int				ft_exit(t_b_list *box)
{
	exit(0);
	return (0);
}

void			ft_box_set(t_b_list *box)
{
	box->win_width = 800;
	box->win_height = 800;
	box->ft_mlx = mlx_init();
	box->ft_win = mlx_new_window(box->ft_mlx, box->win_width, box->win_height, "cub3D");
	box->player_x = box->win_width / 2;
	box->player_y = box->win_height / 2;
}
int				main(void)
{
	t_b_list	*box;
	
	box = (t_b_list *)malloc(sizeof(t_b_list));
	ft_box_set(box);
	ft_player_set(box);
	mlx_loop_hook(box->ft_mlx, ft_grid_set, box);
	mlx_hook(box->ft_win, 2, 0, &ft_key_press, box);
	mlx_hook(box->ft_win, 17, 0, &ft_exit, box);
////////////////////////////////////////////////////////////////////
	mlx_loop(box->ft_mlx);
	return (0);
}