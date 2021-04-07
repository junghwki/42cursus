/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:17:02 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/07 14:04:29 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int			ft_main_loop(t_box *box)
{
	mlx_clear_window(box->mlx.ft_mlx, box->mlx.ft_win);
	ft_background_init(box);
	ft_draw_fov(box);
	ft_sprt_calc(box);
	ft_sprt_check(box);
	if (box->key.m_flag)
	{
		ft_draw_wall(box);
		ft_draw_grid(box);
		ft_draw_dir(box);
		ft_draw_player(box);
	}
	ft_key_function(box);
	mlx_put_image_to_window(box->mlx.ft_mlx,\
	box->mlx.ft_win, box->img.img, 0, 0);
	return (0);
}

int			main(void) //int argc, char *argv[])
{
	t_box	*box;
	int		fd;

	fd = open("./test.cub", O_RDONLY);
	// if(argc == 2)
	// {
	box = (t_box *)malloc(sizeof(t_box));
	box->mlx.ft_mlx = mlx_init();
	ft_parsing_cub(box, fd);
	ft_box_set(box);
	mlx_loop_hook(box->mlx.ft_mlx, ft_main_loop, box);
	mlx_hook(box->mlx.ft_win, 2, 0, &ft_key_press, box);
	mlx_hook(box->mlx.ft_win, 3, 0, &ft_key_release, box);
	mlx_hook(box->mlx.ft_win, 17, 0, &ft_exit, box);

	mlx_loop(box->mlx.ft_mlx);
	free(box);
	// }
	return (0);
}
