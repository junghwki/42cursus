#include "cub3d.h"

void		ft_make_wall(t_box *box, int x, int y)
{
	int		first_x;
	int		first_y;

	first_y = y;
	while (first_y < (box->win.height_len + y))
	{
		first_x = x;
		while (first_x < (box->win.width_len + x))
		{
			ft_pixel_put(box, first_x, first_y, 0x444444);
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
			if(map[row][col] == 1)
				ft_make_wall(box, col * box->win.width_len, row * box->win.height_len);
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
	// ft_pixel_put(box, box->pos.x, box->pos.y, 0xFF0000);
	int 	first_x;
	int 	first_y;
	int		player_size;

	player_size = 5;
	first_y = box->pos.y + player_size;
	while (first_y >= box->pos.y - player_size)
	{
		first_x = box->pos.x + player_size;
		while (first_x >= box->pos.x - player_size)
		{
			ft_pixel_put(box, first_x, first_y, 0xFF0000);
			first_x -= 1;
		}
		first_y -= 1;
	}
	printf("player x = %f\n player y = %f=n",box->pos.x, box->pos.y);
}