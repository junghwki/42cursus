/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:17:02 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/08 19:50:11 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

	if (argc < 2 || argc > 3)
		ft_error();
	box = (t_box *)malloc(sizeof(t_box));
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
