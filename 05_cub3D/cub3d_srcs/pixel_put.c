/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:44:04 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/05 16:44:42 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_pixel_put(t_box *box, int x, int y, int color)
{
	box->img.addr[(box->win.width * y) + x] = color;
}

void		ft_background_init(t_box *box)
{
	int		index;

	index = 0;
	while (index < (box->win.width) * (box->win.height) / 2)
	{
		box->img.addr[index] = box->win.c_color;
		index++;
	}
	while (index < (box->win.width) * (box->win.height))
	{
		box->img.addr[index] = box->win.f_color;
		index++;
	}
}
