/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:07:56 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/08 19:02:32 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_bitmap_file_header(t_box *box, int fd)
{
	box->bfh.bf_size = 54 + box->win.width * box->win.height * 4;
	box->bfh.bf_reserved1 = 0;
	box->bfh.bf_reserved2 = 0;
	box->bfh.bf_off_bits = 54;
	write(fd, "B", 1);
	write(fd, "M", 1);
	write(fd, &box->bfh.bf_size, 4);
	write(fd, &box->bfh.bf_reserved1, 2);
	write(fd, &box->bfh.bf_reserved2, 2);
	write(fd, &box->bfh.bf_off_bits, 4);
}

void		ft_bitmap_info_header(t_box *box, int fd)
{
	box->bih.bi_size = 40;
	box->bih.bi_width = box->win.width;
	box->bih.bi_height = -box->win.height;
	box->bih.bi_planes = 1;
	box->bih.bi_bit_count = 32;
	box->bih.bi_compression = 0;
	box->bih.bi_size_image = 4 * box->win.width * box->win.height;
	box->bih.bi_x_pels_per_meter = 0;
	box->bih.bi_y_pels_per_meter = 0;
	box->bih.bi_clr_used = 0;
	box->bih.bi_clr_important = 0;
	write(fd, &box->bih.bi_size, 4);
	write(fd, &box->bih.bi_width, 4);
	write(fd, &box->bih.bi_height, 4);
	write(fd, &box->bih.bi_planes, 2);
	write(fd, &box->bih.bi_bit_count, 2);
	write(fd, &box->bih.bi_compression, 4);
	write(fd, &box->bih.bi_size_image, 4);
	write(fd, &box->bih.bi_x_pels_per_meter, 4);
	write(fd, &box->bih.bi_y_pels_per_meter, 4);
	write(fd, &box->bih.bi_clr_used, 4);
	write(fd, &box->bih.bi_clr_important, 4);
}

void		ft_write_bmp(t_box *box)
{
	int		fd;

	fd = open("save.bmp", O_WRONLY | O_TRUNC | O_APPEND | O_CREAT);
	ft_bitmap_file_header(box, fd);
	ft_bitmap_info_header(box, fd);
	write(fd, box->img.addr, box->bih.bi_size_image);
	close(fd);
	exit(0);
}

void		ft_save_bmp(t_box *box)
{
	ft_background_init(box);
	ft_draw_fov(box);
	ft_sprt_calc(box);
	ft_sprt_check(box);
	ft_write_bmp(box);
	exit(0);
}
