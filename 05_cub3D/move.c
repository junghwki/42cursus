/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:20:31 by junghwki          #+#    #+#             */
/*   Updated: 2021/03/09 16:25:42 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map_2[20][20] = //row,col
	{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void        ft_move_up(t_box *box)
{
	box->pos.x += box->win.move_speed * cos(box->pos.theta);
	box->pos.y += box->win.move_speed * sin(box->pos.theta);
	if (map_2[(int)(box->pos.y)][(int)(box->pos.x)] == 1)
	{
		box->pos.x -= box->win.move_speed * cos(box->pos.theta);
		box->pos.y -= box->win.move_speed * sin(box->pos.theta);
	}
}

void        ft_move_down(t_box *box)
{
	box->pos.x -= box->win.move_speed * cos(box->pos.theta);
	box->pos.y -= box->win.move_speed * sin(box->pos.theta);
	if (map_2[(int)(box->pos.y)][(int)(box->pos.x)] == 1)
	{
		box->pos.x += box->win.move_speed * cos(box->pos.theta);
		box->pos.y += box->win.move_speed * sin(box->pos.theta);
	}
}

void        ft_move_left(t_box *box)
{
    double	left_dir;

    left_dir = box->pos.theta - ft_deg_to_rad(90);
    box->pos.x += box->win.move_speed * cos(left_dir);
    box->pos.y += box->win.move_speed * sin(left_dir);
    if (map_2[(int)(box->pos.y)][(int)(box->pos.x)] == 1)
    {
    	box->pos.x -= box->win.move_speed * cos(left_dir);
    	box->pos.y -= box->win.move_speed * sin(left_dir);
    }
}

void        ft_move_right(t_box *box)
{
    double	right_dir;

	right_dir = box->pos.theta + ft_deg_to_rad(90);
	box->pos.x += box->win.move_speed * cos(right_dir);
	box->pos.y += box->win.move_speed * sin(right_dir);
	if (map_2[(int)(box->pos.y)][(int)(box->pos.x)] == 1)
	{
		box->pos.x -= box->win.move_speed * cos(right_dir);
		box->pos.y -= box->win.move_speed * sin(right_dir);
	}
}

void        ft_rotate_left(t_box *box)
{
    box->pos.theta = ft_rot_theta(box, box->win.rotate_angle * -1);
}

void        ft_rotate_right(t_box *box)
{
    box->pos.theta = ft_rot_theta(box, box->win.rotate_angle);
}
