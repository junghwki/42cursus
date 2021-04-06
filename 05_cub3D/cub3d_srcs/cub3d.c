/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:21:20 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/06 17:16:23 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	int		j;

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
