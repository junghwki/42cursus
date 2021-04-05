/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:38:21 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/05 17:38:23 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double		ft_deg_to_rad(double x)
{
	return (x * M_PI / 180);
}

double		ft_rot_angle(double angle, double theta)
{
	double	result;

	result = angle + theta;
	if (result < -1 * M_PI)
		result = (result + (2 * M_PI));
	else if (result > M_PI)
		result = (result - (2 * M_PI));
	return (result);
}

void		ft_rotate_left(t_box *box)
{
	box->pos.theta = ft_rot_angle(box->pos.theta, box->win.rotate_angle * -1);
}

void		ft_rotate_right(t_box *box)
{
	box->pos.theta = ft_rot_angle(box->pos.theta, box->win.rotate_angle);
}
