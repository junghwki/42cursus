/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:49:32 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/06 16:24:02 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double 	ft_wall_check(t_box *box, double theta)
{
	t_vec	delta;
	t_vec	side;
	double	rotate_theta;

	// rotate_theta = ft_rot_angle(box->pos.theta, theta);
	// ft_calc_dda(box, &delta, &side, rotate_theta);
	ft_calc_dda(box, &delta, &side, ft_rot_angle(box->pos.theta, theta));
	while (box->win.map[box->pos.map_y][box->pos.map_x] != '1')
		if (side.x < side.y)
		{
			box->pos.map_x += box->pos.dir.x;
			if (box->win.map[box->pos.map_y][box->pos.map_x] == '1')
			{
				box->comp.y = 1;
				box->pos.tex = box->pos.y + (side.x * sin(ft_rot_angle(box->pos.theta, theta))) - box->pos.map_y;
				// box->pos.tex = box->pos.y + (side.x * sin(rotate_theta)) - box->pos.map_y;
				return (side.x * cos(theta));
			}
			side.x += delta.x;
		}
		else
		{
			box->pos.map_y += box->pos.dir.y;
			if (box->win.map[box->pos.map_y][box->pos.map_x] == '1')
			{
				box->comp.x = 1;
				box->pos.tex = box->pos.x + (side.y * cos(ft_rot_angle(box->pos.theta, theta))) - box->pos.map_x;
				// box->pos.tex = box->pos.x + (side.y * cos(rotate_theta)) - box->pos.map_x;
				return (side.y * cos(theta));
			}
			side.y += delta.y;
		}
	return (0);
}
