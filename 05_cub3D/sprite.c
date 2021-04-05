#include "cub3d.h"

void	ft_draw_sprt(t_box *box, double sprt_len, int sprt_x)
{
	int	x;
	int	y;
	double	x_idx;
	double	y_idx;
	int start_x;
	int start_y;

	x = 0;
	y = 0;
	start_x = sprt_x - sprt_len;
	start_y = (box->win.height / 2) - sprt_len;
	x_idx = (double)(box->s.width / (sprt_len * 2));
	y_idx = (double)(box->s.height / (sprt_len * 2));
	while (y < (2 * sprt_len) - 1)
	{
		x = 0;
		while (x < (2 * sprt_len) - 1)
		{
			if (start_x + x > 0 && start_x + x < box->win.width &&
				start_y + y > 0 && start_y + y < box->win.height &&
				box->s.addr[(int)(x_idx * x) + ((int)(y_idx * y) * box->s.width)] &&
				box->pos.x_height[start_x + x] < sprt_len)
				ft_pixel_put(box, start_x + x, start_y + y, box->s.addr[(int)(x_idx * x) + ((int)(y_idx * y) * box->s.width)]);
			x++;
		}
		y++;
	}
}

void	ft_sprt_check(t_box *box)
{
	double	sprt_angle;
	double	sprt_dis;
	int 	i;
	int		start_x;
	double	sprt_height;

	i = 0;
	while (i < box->pos.visible_num)
	{
		sprt_angle = ft_rot_angle(box->visible[i].angle, -1 * box->pos.theta);
		sprt_height = (box->win.height / box->visible[i].dist) / 2;
		sprt_dis = tan(sprt_angle) * box->win.dis;
		start_x = (int)((box->win.width / 2) + sprt_dis);
		ft_draw_sprt(box, sprt_height, start_x);
		i++;
	}
}