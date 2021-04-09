/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:09:41 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/09 12:48:02 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_vec		ft_comp_check(double theta)
{
	if (theta > ft_deg2rad(0) && theta < ft_deg2rad(90))
		return (ft_new_vec(1, 1));
	else if (theta > ft_deg2rad(90) && theta < ft_deg2rad(180))
		return (ft_new_vec(-1, 1));
	else if (theta > ft_deg2rad(-180) && theta < ft_deg2rad(-90))
		return (ft_new_vec(-1, -1));
	else if (theta > ft_deg2rad(-90) && theta < ft_deg2rad(0))
		return (ft_new_vec(1, -1));
	else if (theta == ft_deg2rad(90))
		return (ft_new_vec(0, 1));
	else if (theta == ft_deg2rad(180) || theta == ft_deg2rad(-180))
		return (ft_new_vec(-1, 0));
	else if (theta == ft_deg2rad(-90))
		return (ft_new_vec(0, -1));
	else if (theta == ft_deg2rad(360) || theta == ft_deg2rad(0))
		return (ft_new_vec(1, 0));
	else
		return (ft_new_vec(0, 0));
}

void		ft_calc_dda(t_box *box, double rot_theta)
{
	box->pos.map_x = (int)box->pos.x;
	box->pos.map_y = (int)box->pos.y;
	box->pos.dir = ft_comp_check(rot_theta);
	box->dda.delta_x = fabs(1 / cos(rot_theta));
	box->dda.delta_y = fabs(1 / sin(rot_theta));
	if (box->pos.dir.x < 0)
		box->dda.side_x = (box->pos.x - box->pos.map_x) * box->dda.delta_x;
	else
		box->dda.side_x = (box->pos.map_x + 1 - box->pos.x) * box->dda.delta_x;
	if (box->pos.dir.y < 0)
		box->dda.side_y = (box->pos.y - box->pos.map_y) * box->dda.delta_y;
	else
		box->dda.side_y = (box->pos.map_y + 1 - box->pos.y) * box->dda.delta_y;
}

double		ft_wall_check(t_box *box, double theta)
{
	while (1)
		if (box->dda.side_x < box->dda.side_y)
		{
			box->pos.map_x += box->pos.dir.x;
			if (box->win.map[box->pos.map_y][box->pos.map_x] == '1')
			{
				box->comp.y = 1;
				box->pos.tex = box->pos.y + (box->dda.side_x\
				* sin(ft_rot_angle(box->pos.theta, theta))) - box->pos.map_y;
				return (box->dda.side_x * cos(theta));
			}
			box->dda.side_x += box->dda.delta_x;
		}
		else
		{
			box->pos.map_y += box->pos.dir.y;
			if (box->win.map[box->pos.map_y][box->pos.map_x] == '1')
			{
				box->comp.x = 1;
				box->pos.tex = box->pos.x + (box->dda.side_y\
				* cos(ft_rot_angle(box->pos.theta, theta))) - box->pos.map_x;
				return (box->dda.side_y * cos(theta));
			}
			box->dda.side_y += box->dda.delta_y;
		}
}

void		ft_draw_fov(t_box *box)
{
	int		x;
	int		ray;
	double	theta;

	x = 0;
	ray = -1 * (box->win.width / 2);
	while (x < box->win.width)
	{
		theta = atan(ray / box->win.dis);
		ft_calc_dda(box, ft_rot_angle(box->pos.theta, theta));
		box->pos.x_height[x] = (box->win.height\
		/ ft_wall_check(box, atan(ray / box->win.dis))) / 2;
		if (box->comp.y && box->pos.dir.x >= 0)
			draw_ea_tex(box, box->pos.x_height[x], x);
		else if (box->comp.y && box->pos.dir.x < 0)
			draw_we_tex(box, box->pos.x_height[x], x);
		else if (box->comp.x && box->pos.dir.y >= 0)
			draw_so_tex(box, box->pos.x_height[x], x);
		else if (box->comp.x && box->pos.dir.y < 0)
			draw_no_tex(box, box->pos.x_height[x], x);
		box->comp.x = 0;
		box->comp.y = 0;
		ray++;
		x++;
	}
}
