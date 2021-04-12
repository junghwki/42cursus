/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:20 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/12 13:34:09 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_draw_sprt(t_box *box, double sprt_len, int x, int y)
{
	int		i;
	int		j;
	double	x_idx;
	double	y_idx;
	int		tex_idx;

	x_idx = (double)(box->s.width / (sprt_len * 2));
	y_idx = (double)(box->s.height / (sprt_len * 2));
	j = 0;
	while (j < (2 * sprt_len) - 1)
	{
		i = 0;
		while (i < (2 * sprt_len) - 1)
		{
			tex_idx = (int)(x_idx * i) + (int)(y_idx * j) * box->s.width;
			if (x + i >= 0 && x + i < box->win.width\
				&& y + j >= 0 && y + j < box->win.height\
				&& box->s.addr[tex_idx] && box->pos.x_height[x + i] < sprt_len)
				ft_pixel_put(box, x + i, y + j, box->s.addr[tex_idx]);
			i++;
		}
		j++;
	}
}

void		ft_sprt_check(t_box *box)
{
	double	sprt_angle;
	double	sprt_dis;
	int		i;
	int		start_x;
	double	sprt_height;

	i = 0;
	while (i < box->pos.visible_num)
	{
		sprt_angle = ft_rot_angle(box->visible[i].angle, -1 * box->pos.theta);
		sprt_height = (box->win.height / box->visible[i].dist) / 2;
		sprt_dis = tan(sprt_angle) * box->win.dis;
		start_x = (int)((box->win.width / 2) + sprt_dis);
		ft_draw_sprt(box, sprt_height,\
		start_x - sprt_height, (box->win.height / 2) - sprt_height);
		i++;
	}
}

void		ft_sprt_pos(t_box *box)
{
	int		i;
	int		j;
	int		k;

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

int			ft_visible_check(t_box *box, double sprt_angle)
{
	if ((sprt_angle < box->pos.theta + ft_deg2rad(70)\
		&& sprt_angle > box->pos.theta + ft_deg2rad(-70))\
		|| (sprt_angle + M_PI * 2 < box->pos.theta + (ft_deg2rad(70))\
		&& sprt_angle + M_PI * 2 > box->pos.theta + (ft_deg2rad(-70)))\
		|| (sprt_angle - M_PI * 2 < box->pos.theta + (ft_deg2rad(70))\
		&& sprt_angle - M_PI * 2 > box->pos.theta + (ft_deg2rad(-70))))
		return (1);
	return (0);
}

void		ft_sprt_calc(t_box *box)
{
	int		i;

	i = 0;
	box->pos.visible_num = 0;
	ft_visible_init(box);
	while (i < box->pars.s_cnt)
	{
		box->sprt[i].angle = atan2(box->sprt[i].y - box->pos.y,\
		box->sprt[i].x - box->pos.x);
		if (ft_visible_check(box, box->sprt[i].angle))
		{
			box->pos.visible_num++;
			box->sprt[i].visible = 1;
			box->sprt[i].dist = ft_dist_calc(box->sprt[i].y - box->pos.y,\
			box->sprt[i].x - box->pos.x) *\
			cos(box->sprt[i].angle - box->pos.theta);
		}
		i++;
	}
	ft_make_visible_array(box);
	ft_sort_sprt(box);
	;
}
