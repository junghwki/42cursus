/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:20:38 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/08 17:28:46 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_sprt_swap(t_sprt *a, t_sprt *b)
{
	t_sprt	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int			ft_exit(t_box *box)
{
	system("leaks a.out");
	exit(0);
	return (0);
	box->pos.x = 0;
}

void		ft_error(void)
{
	printf("Error\n");
	exit(0);
}

t_vec		ft_theta_check(double theta)
{
	if (theta > ft_deg2rad(0) && theta < ft_deg2rad(90))
		return (ft_new_vec(1, 1));
	else if (theta > ft_deg2rad(90) && theta < ft_deg2rad(180))
		return (ft_new_vec(-1, 1));
	else if (theta > ft_deg2rad(-180) && theta < ft_deg2rad(-90))
		return (ft_new_vec(-1, -1));
	else if (theta > ft_deg2rad(-90) && theta < ft_deg2rad(0))
		return (ft_new_vec(1, -1));
	else if (theta == ft_deg2rad(90))
		return (ft_new_vec(0, 1));
	else if (theta == ft_deg2rad(180) || theta == ft_deg2rad(-180))
		return (ft_new_vec(-1, 0));
	else if (theta == ft_deg2rad(-90))
		return (ft_new_vec(0, -1));
	else if (theta == ft_deg2rad(360) || theta == ft_deg2rad(0))
		return (ft_new_vec(1, 0));
	else
		return (ft_new_vec(0, 0));
}

void		ft_box_set(t_box *box)
{
	box->key.w_flag = 0;
	box->key.a_flag = 0;
	box->key.s_flag = 0;
	box->key.d_flag = 0;
	box->key.m_flag = 0;
	box->key.left_flag = 0;
	box->key.right_flag = 0;
	box->win.width_len = box->win.width / box->win.col;
	box->win.height_len = box->win.height / box->win.row;
	box->win.move_speed = 0.06;
	box->win.fov = ft_deg2rad(90);
	box->win.dis = box->win.width / tan(box->win.fov / 2);
	box->win.rotate_angle = ft_deg2rad(3);
	box->mlx.ft_win = mlx_new_window(box->mlx.ft_mlx,\
		box->win.width, box->win.height, "cub3D");
	box->img.img = mlx_new_image(box->mlx.ft_mlx,\
		box->win.width, box->win.height);
	box->img.addr = (int *)mlx_get_data_addr(box->img.img,\
		&box->img.bits_per_pixel, &box->img.size_line, &box->img.endian);
	box->pos.x_height = (double *)malloc(sizeof(double) * box->win.width);
}
