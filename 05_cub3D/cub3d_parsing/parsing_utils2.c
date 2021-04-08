/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:21:20 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/08 18:02:12 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_map_dup(t_box *box)
{
	int		i;
	int		j;
	char	**src;

	src = ft_split(box->pars.map, '#');
	free(box->pars.map);
	j = 0;
	while (src[j])
	{
		i = 0;
		while (src[j][i])
		{
			box->win.map[j][i] = src[j][i];
			i++;
		}
		j++;
	}
	ft_array_free(src);
}

void		ft_make_base(t_box *box)
{
	int		i;
	int		j;

	i = 0;
	box->win.map = (char **)malloc(sizeof(char *) * (box->win.row + 1));
	while (i < box->win.row)
	{
		box->win.map[i] = (char *)malloc(box->win.col + 1);
		i++;
	}
	box->win.map[box->win.row] = NULL;
	j = 0;
	while (j < box->win.row)
	{
		i = 0;
		while (i < box->win.col)
		{
			box->win.map[j][i] = ' ';
			i++;
		}
		box->win.map[j][i] = '\0';
		j++;
	}
}

void		ft_resolution(t_box *box)
{
	int		width;
	int		height;

	mlx_get_screen_size(box->mlx.ft_mlx, &width, &height);
	if (ft_rowlen(box->pars.word) != 3 || box->pars.r_flag)
		ft_error();
	ft_nbr_check(box->pars.word[1]);
	ft_nbr_check(box->pars.word[2]);
	box->win.width = ft_atoi(box->pars.word[1]);
	if (box->win.width > width)
		box->win.width = width;
	box->win.height = ft_atoi(box->pars.word[2]);
	if (box->win.height > height)
		box->win.height = height;
	if (box->win.width == 0 || box->win.height == 0)
		ft_error();
	box->pars.r_flag = 1;
}

void		ft_c_color(t_box *box)
{
	char	**temp;

	if (ft_rowlen(box->pars.word) != 2 || box->pars.c_flag)
		ft_error();
	temp = ft_split(box->pars.word[1], ',');
	if (ft_rowlen(temp) != 3)
		ft_error();
	ft_nbr_check(temp[0]);
	ft_nbr_check(temp[1]);
	ft_nbr_check(temp[2]);
	if (ft_atoi(temp[0]) > 255)
		ft_error();
	box->win.c_color = ft_atoi(temp[0]);
	box->win.c_color *= 256;
	if (ft_atoi(temp[1]) > 255)
		ft_error();
	box->win.c_color += ft_atoi(temp[1]);
	box->win.c_color *= 256;
	if (ft_atoi(temp[2]) > 255)
		ft_error();
	box->win.c_color += ft_atoi(temp[2]);
	ft_array_free(temp);
	box->pars.c_flag = 1;
}

void		ft_f_color(t_box *box)
{
	char	**temp;

	if (ft_rowlen(box->pars.word) != 2 || box->pars.f_flag)
		ft_error();
	temp = ft_split(box->pars.word[1], ',');
	if (ft_rowlen(temp) != 3)
		ft_error();
	ft_nbr_check(temp[0]);
	ft_nbr_check(temp[1]);
	ft_nbr_check(temp[2]);
	if (ft_atoi(temp[0]) > 255)
		ft_error();
	box->win.f_color = ft_atoi(temp[0]);
	box->win.f_color *= 256;
	if (ft_atoi(temp[1]) > 255)
		ft_error();
	box->win.f_color += ft_atoi(temp[1]);
	box->win.f_color *= 256;
	if (ft_atoi(temp[2]) > 255)
		ft_error();
	box->win.f_color += ft_atoi(temp[2]);
	ft_array_free(temp);
	box->pars.f_flag = 1;
}
