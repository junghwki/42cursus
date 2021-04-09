/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:05:15 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/09 11:43:12 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		draw_ea_tex(t_box *box, double wall_height, int x)
{
	int		y;
	int		height;
	int		y_idx;
	int		tex_idx;

	y = 0;
	height = (box->win.height / 2) - wall_height;
	y_idx = 0;
	while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
	{
		if ((int)(y_idx * (wall_height * 2)) < (int)(y * box->ea.height))
			y_idx = (int)(box->ea.height * (double)(y / (wall_height * 2)));
		tex_idx = (int)((box->pos.tex * box->ea.width)\
		+ (box->ea.width * y_idx));
		if (y + height >= 0 && tex_idx < box->ea.width * box->ea.height)
			ft_pixel_put(box, x, y + height, box->ea.addr[tex_idx]);
		y++;
	}
}

void		draw_we_tex(t_box *box, double wall_height, int x)
{
	int		y;
	int		height;
	int		y_idx;
	int		tex_idx;

	y = 0;
	height = (box->win.height / 2) - wall_height;
	y_idx = 0;
	while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
	{
		if ((int)(y_idx * (wall_height * 2)) < (int)(y * box->we.height))
			y_idx = (int)(box->we.height * (double)(y / (wall_height * 2)));
		tex_idx = (int)(box->we.width - (box->pos.tex * box->we.width)\
		+ (box->we.width * y_idx));
		if (y + height >= 0 && tex_idx < box->we.width * box->we.height)
			ft_pixel_put(box, x, y + height, box->we.addr[tex_idx]);
		y++;
	}
}

void		draw_so_tex(t_box *box, double wall_height, int x)
{
	int		y;
	int		height;
	int		y_idx;
	int		tex_idx;

	y = 0;
	height = (box->win.height / 2) - wall_height;
	y_idx = 0;
	while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
	{
		if ((int)(y_idx * (wall_height * 2)) < (int)(y * box->so.height))
			y_idx = (int)(box->so.height * (double)(y / (wall_height * 2)));
		tex_idx = (int)(box->so.width - (box->pos.tex * box->so.width)\
		+ (box->so.width * y_idx));
		if (y + height >= 0 && tex_idx < box->so.width * box->so.height)
			ft_pixel_put(box, x, y + height, box->so.addr[tex_idx]);
		y++;
	}
}

void		draw_no_tex(t_box *box, double wall_height, int x)
{
	int		y;
	int		height;
	int		y_idx;
	int		tex_idx;

	y = 0;
	height = (box->win.height / 2) - wall_height;
	y_idx = 0;
	while ((y < (wall_height * 2) - 1) && (y + height < box->win.height))
	{
		if ((int)(y_idx * (wall_height * 2)) < (int)(y * box->no.height))
			y_idx = (int)(box->no.height * (double)(y / (wall_height * 2)));
		tex_idx = (int)((box->pos.tex * box->no.width)\
		+ (box->no.width * y_idx));
		if (y + height >= 0 && tex_idx < box->no.width * box->no.height)
			ft_pixel_put(box, x, y + height, box->no.addr[tex_idx]);
		y++;
	}
}
