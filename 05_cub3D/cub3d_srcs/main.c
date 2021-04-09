/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:17:02 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/09 13:31:55 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int			ft_main_loop(t_box *box)
{
	mlx_clear_window(box->mlx.ft_mlx, box->mlx.ft_win);
	ft_background_init(box);
	ft_draw_fov(box);
	ft_sprt_calc(box);
	ft_sprt_check(box);
	ft_key_function(box);
	mlx_put_image_to_window(box->mlx.ft_mlx,\
	box->mlx.ft_win, box->img.img, 0, 0);
	return (0);
}

int			main(int argc, char *argv[])
{
	t_box	*box;
	int		fd;

	fd = -1;
	if (argc < 2 || argc > 3)
		ft_error();
	box = (t_box *)malloc(sizeof(t_box));
	if (!(ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub")))
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error();
	box->mlx.ft_mlx = mlx_init();
	ft_parsing_cub(box, fd);
	ft_box_set(box);
	if (argc == 3 && !(ft_strcmp(argv[2], "--save")))
		ft_save_bmp(box);
	else if (argc == 3)
		ft_error();
	mlx_loop_hook(box->mlx.ft_mlx, ft_main_loop, box);
	mlx_hook(box->mlx.ft_win, 2, 0, &ft_key_press, box);
	mlx_hook(box->mlx.ft_win, 3, 0, &ft_key_release, box);
	mlx_hook(box->mlx.ft_win, 17, 0, &ft_exit, box);
	mlx_loop(box->mlx.ft_mlx);
	free(box);
	return (0);
}
