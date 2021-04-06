#include "./cub3d.h"


void		ft_make_wall(t_box *box, int x, int y)
{
	int		first_x;
	int		first_y;

	first_y = y * box->win.height_len;
	while(first_y < (box->win.height_len + (y * box->win.height_len)))
	{
		first_x = x * box->win.width_len;
		while(first_x < (box->win.width_len + (x * box->win.width_len)))
		{
			ft_pixel_put(box, first_x, first_y, 0x666666);
			first_x++;
		}
		first_y++;
	}
}

void 		ft_draw_dir(t_box *box)
{
	int i;
	double x;
	double y;
	double dir_theta;

	dir_theta = box->pos.theta - (box->win.fov / 2);
	while (dir_theta < box->pos.theta + (box->win.fov / 2))
	{
		i = 0;
		x = box->pos.x * box->win.width_len;
		y = box->pos.y * box->win.height_len;
		while (i < box->win.width_len * 2)
		{
			if (box->win.map[(int)(y / box->win.height_len)][(int)(x / box->win.width_len)] == '0')
			{
				ft_pixel_put(box, x, y, 0x00FF00);
				x += cos(dir_theta);
				y += sin(dir_theta);
			}
			i++;
		}
		dir_theta += ft_deg2rad(1);
	}
}

void		ft_make_sprt(t_box *box, int x, int y)
{
	int		first_x;
	int		first_y;

	first_y = y * box->win.height_len;
	while(first_y < (box->win.height_len + (y * box->win.height_len)))
	{
		first_x = x * box->win.width_len;
		while(first_x < (box->win.width_len + (x * box->win.width_len)))
		{
			ft_pixel_put(box, first_x, first_y, 0x5555FF);
			first_x++;
		}
		first_y++;
	}
}

void		ft_draw_wall(t_box *box)
{
	int		row;
	int		col;

	row = 0;
	while(row < box->win.row)
	{
		col = 0;
		while(col < box->win.col)
		{
			if(box->win.map[row][col] == '1')
				ft_make_wall(box, col, row);
			if(box->win.map[row][col] == '2')
				ft_make_sprt(box, col, row);
			col++;
		}
		row++;
	}
}

void		ft_draw_grid(t_box *box)
{
	int 	x;
	int 	y;

	y = box->win.height_len;
	while (y < box->win.height)
	{
		x = 0;
		while (x < box->win.width)
		{
			ft_pixel_put(box, x, y, 0xFFFFFF);
			x += 1;
		}
		y += box->win.height_len;
	}
	x = box->win.width_len;
	while (x < box->win.width)
	{
		y = 0;
		while (y < box->win.height)
		{
			ft_pixel_put(box, x, y, 0xFFFFFF);
			y += 1;
		}
		x += box->win.width_len;
	}
}

void		ft_draw_player(t_box *box)
{
	int 	first_x;
	int 	first_y;
	int		player_size;

	player_size = 3;
	first_y = (box->pos.y * box->win.height_len) + player_size;
	while (first_y >= (box->pos.y * box->win.height_len) - player_size)
	{
		first_x = (box->pos.x * box->win.width_len) + player_size;
		while (first_x >= (box->pos.x * box->win.width_len) - player_size)
		{
			ft_pixel_put(box, first_x, first_y, 0xFF0000);
			first_x -= 1;
		}
		first_y -= 1;
	}
}

void		ft_clear_image(t_box *box)
{
	int		idx;

	idx = 0;
	while (idx < (box->win.width) * (box->win.height))
	{
		box->img.addr[idx] = 0;
		idx++;
	}
}
