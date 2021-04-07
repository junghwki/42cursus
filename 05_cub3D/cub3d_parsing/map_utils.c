/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:05:43 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/07 15:06:57 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_is_valid(char c)
{
	if (c != '0' && c != '1' && c != '2')
		return (1);
	return (0);
}

void		ft_map_check(t_box *box)
{
	int		x;
	int		y;

	y = 0;
	while (y < box->win.row)
	{
		x = 0;
		while (x < box->win.col)
		{
			if (box->win.map[y][x] == '0' || box->win.map[y][x] == '2')
			{
				if (y == 0 || y == box->win.row || x == 0 || x == box->win.col)
					ft_error();
				if (ft_is_valid(box->win.map[y + 1][x])\
				|| ft_is_valid(box->win.map[y - 1][x])\
				|| ft_is_valid(box->win.map[y][x + 1])\
				|| ft_is_valid(box->win.map[y][x - 1]))
					ft_error();
				if (box->win.map[y][x] == '2')
					box->pars.s_cnt++;
			}
			x++;
		}
		y++;
	}
}

int			ft_set_player_pos(t_box *box, int x, int y)
{
	if (box->win.map[y][x] == 'E')
		box->pos.theta = ft_deg2rad(0);
	else if (box->win.map[y][x] == 'S')
		box->pos.theta = ft_deg2rad(90);
	else if (box->win.map[y][x] == 'W')
		box->pos.theta = ft_deg2rad(-180);
	else if (box->win.map[y][x] == 'N')
		box->pos.theta = ft_deg2rad(-90);
	else
		ft_error();
	box->win.map[y][x] = '0';
	box->pos.x = x + 0.5;
	box->pos.y = y + 0.5;
	return (1);
}

void		ft_dir_check(t_box *box)
{
	int		flag;
	int		x;
	int		y;

	flag = 0;
	y = 0;
	while (y < box->win.row)
	{
		x = 0;
		while (x < box->win.col)
		{
			if (box->win.map[y][x] == 'E' || box->win.map[y][x] == 'W' ||\
			box->win.map[y][x] == 'S' || box->win.map[y][x] == 'N')
			{
				if (flag == 0)
					flag = ft_set_player_pos(box, x, y);
			}
			x++;
		}
		y++;
	}
	if (!flag)
		ft_error();
}
