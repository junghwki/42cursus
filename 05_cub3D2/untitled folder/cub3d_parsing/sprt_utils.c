/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprt_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:59:54 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/05 17:44:24 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double		ft_dist_calc(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

void		ft_visible_init(t_box *box)
{
	int		i;

	i = 0;
	while (i < box->pars.s_cnt)
	{
		box->sprt[i].visible = 0;
		box->sprt[i].angle = 0;
		box->sprt[i].dist = 0;
		i++;
	}
}

void		ft_make_visible_array(t_box *box)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < box->pars.s_cnt)
	{
		if (box->sprt[i].visible)
		{
			box->visible[j] = box->sprt[i];
			j++;
		}
		i++;
	}
}

void		ft_sort_sprt(t_box *box)
{
	int		i;
	int		j;

	j = 0;
	while (j < box->pos.visible_num - 1)
	{
		i = 0;
		while (i < box->pos.visible_num - j - 1)
		{
			if (box->visible[i].dist < box->visible[i + 1].dist)
				ft_sprt_swap(&box->visible[i], &box->visible[i + 1]);
			i++;
		}
		j++;
	}
}
