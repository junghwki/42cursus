/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:20:31 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/05 16:52:15 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_vec		ft_new_vec(double x, double y)
{
	t_vec	result;

	result.x = x;
	result.y = y;
	return (result);
}

void		ft_move_up(t_box *box)
{
	double	next_x;
	double	next_y;
	double	thick_x;
	double	thick_y;

	next_x = box->pos.x + box->win.move_speed * cos(box->pos.theta);
	next_y = box->pos.y + box->win.move_speed * sin(box->pos.theta);
	if (next_x > box->pos.x)
		thick_x = 0.1;
	else
		thick_x = -0.1;
	if (next_y > box->pos.y)
		thick_y = 0.1;
	else
		thick_y = -0.1;
	if (box->win.map[(int)(next_y + thick_y)][(int)(box->pos.x)] == '0')
		box->pos.y = next_y;
	if (box->win.map[(int)(box->pos.y)][(int)(next_x + thick_x)] == '0')
		box->pos.x = next_x;
}

void		ft_move_down(t_box *box)
{
	double	next_x;
	double	next_y;
	double	thick_x;
	double	thick_y;

	next_x = box->pos.x - box->win.move_speed * cos(box->pos.theta);
	next_y = box->pos.y - box->win.move_speed * sin(box->pos.theta);
	if (next_x > box->pos.x)
		thick_x = 0.1;
	else
		thick_x = -0.1;
	if (next_y > box->pos.y)
		thick_y = 0.1;
	else
		thick_y = -0.1;
	if (box->win.map[(int)(next_y + thick_y)][(int)(box->pos.x)] == '0')
		box->pos.y = next_y;
	if (box->win.map[(int)(box->pos.y)][(int)(next_x + thick_x)] == '0')
		box->pos.x = next_x;
}

void		ft_move_left(t_box *box)
{
	double	left_dir;
	double	next_x;
	double	next_y;
	double	thick_x;
	double	thick_y;

	left_dir = ft_rot_angle(box->pos.theta, ft_deg_to_rad(-90));
	next_x = box->pos.x + box->win.move_speed * cos(left_dir);
	next_y = box->pos.y + box->win.move_speed * sin(left_dir);
	if (next_x > box->pos.x)
		thick_x = 0.1;
	else
		thick_x = -0.1;
	if (next_y > box->pos.y)
		thick_y = 0.1;
	else
		thick_y = -0.1;
	if (box->win.map[(int)(next_y + thick_y)][(int)(box->pos.x)] == '0')
		box->pos.y = next_y;
	if (box->win.map[(int)(box->pos.y)][(int)(next_x + thick_x)] == '0')
		box->pos.x = next_x;
}

void		ft_move_right(t_box *box)
{
	double	right_dir;
	double	next_x;
	double	next_y;
	double	thick_x;
	double	thick_y;

	right_dir = ft_rot_angle(box->pos.theta, ft_deg_to_rad(90));
	next_x = box->pos.x + box->win.move_speed * cos(right_dir);
	next_y = box->pos.y + box->win.move_speed * sin(right_dir);
	if (next_x > box->pos.x)
		thick_x = 0.1;
	else
		thick_x = -0.1;
	if (next_y > box->pos.y)
		thick_y = 0.1;
	else
		thick_y = -0.1;
	if (box->win.map[(int)(next_y + thick_y)][(int)(box->pos.x)] == '0')
		box->pos.y = next_y;
	if (box->win.map[(int)(box->pos.y)][(int)(next_x + thick_x)] == '0')
		box->pos.x = next_x;
}
