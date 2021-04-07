/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:19:49 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/07 14:19:50 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_ea_route(t_box *box)
{
	if (ft_rowlen(box->pars.word) != 2 || box->pars.ea_flag
	|| open(box->pars.word[1], O_RDONLY) < 0)
		ft_error();
	box->ea.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx,\
	box->pars.word[1], &box->ea.width, &box->ea.height);
	box->ea.addr = (int *)mlx_get_data_addr(box->ea.ptr,\
	&box->ea.bits_per_pixel, &box->ea.size_line, &box->ea.endian);
	box->pars.ea_flag = 1;
}

void		ft_we_route(t_box *box)
{
	if (ft_rowlen(box->pars.word) != 2 || box->pars.we_flag
	|| open(box->pars.word[1], O_RDONLY) < 0)
		ft_error();
	box->we.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx,\
	box->pars.word[1], &box->we.width, &box->we.height);
	box->we.addr = (int *)mlx_get_data_addr(box->we.ptr,\
	&box->we.bits_per_pixel, &box->we.size_line, &box->we.endian);
	box->pars.we_flag = 1;
}

void		ft_so_route(t_box *box)
{
	if (ft_rowlen(box->pars.word) != 2 || box->pars.so_flag
	|| open(box->pars.word[1], O_RDONLY) < 0)
		ft_error();
	box->so.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx,\
	box->pars.word[1], &box->so.width, &box->so.height);
	box->so.addr = (int *)mlx_get_data_addr(box->so.ptr,\
	&box->so.bits_per_pixel, &box->so.size_line, &box->so.endian);
	box->pars.so_flag = 1;
}

void		ft_no_route(t_box *box)
{
	if (ft_rowlen(box->pars.word) != 2 || box->pars.no_flag
	|| open(box->pars.word[1], O_RDONLY) < 0)
		ft_error();
	box->no.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx,\
	box->pars.word[1], &box->no.width, &box->no.height);
	box->no.addr = (int *)mlx_get_data_addr(box->no.ptr,\
	&box->no.bits_per_pixel, &box->no.size_line, &box->no.endian);
	box->pars.no_flag = 1;
}

void		ft_s_route(t_box *box)
{
	if (ft_rowlen(box->pars.word) != 2 || box->pars.s_flag
	|| open(box->pars.word[1], O_RDONLY) < 0)
		ft_error();
	box->s.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx,\
	box->pars.word[1], &box->s.width, &box->s.height);
	box->s.addr = (int *)mlx_get_data_addr(box->s.ptr,\
	&box->s.bits_per_pixel, &box->s.size_line, &box->s.endian);
	box->pars.s_flag = 1;
}
