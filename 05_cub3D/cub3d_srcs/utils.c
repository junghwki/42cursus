/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:20:38 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/12 18:56:43 by junghwki         ###   ########.fr       */
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
	free(box->pos.x_height);
	free(box->sprt);
	free(box->visible);
	ft_array_free(box->win.map);
	free(box);
	exit(0);
	return (0);
}

void		ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

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
