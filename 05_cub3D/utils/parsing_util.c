#include "../cub3d.h"

void ft_pars_init(t_box *box)
{
	box->pars.r_flag = 0;
	box->pars.ea_flag = 0;
	box->pars.we_flag = 0;
	box->pars.so_flag = 0;
	box->pars.no_flag = 0;
	box->pars.s_flag = 0;
	box->pars.f_flag = 0;
	box->pars.c_flag = 0;
	box->win.col = 0;
	box->pars.map = NULL;
	box->win.c_color = 0;
	box->win.f_color = 0;
}

int ft_rowlen(char **array)
{
	int index;

	index = 0;
	while (array[index])
		index++;
	return (index);
}

int ft_check_flag(t_box *box)
{
	if (box->pars.r_flag && box->pars.ea_flag &&
		box->pars.we_flag && box->pars.so_flag && box->pars.no_flag &&
		box->pars.s_flag && box->pars.f_flag && box->pars.c_flag)
		return (1);
	return (0);
}

void ft_map_dup(t_box *box, char **src)
{
	int i;
	int j;

	j = 0;
	while (src[j])
	{
		i = 0;
		while (src[j][i])
		{
			box->win.map[j][i] = src[j][i];
			i++;
		}
		j++;
	}
}

int ft_map_check(t_box *box)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (j < box->win.row)
	{
		i = 0;
		while (i < box->win.col)
		{
			if (box->win.map[j][i] == 'N' || box->win.map[j][i] == 'E' || box->win.map[j][i] == 'W' || box->win.map[j][i] == 'S')
			{
				if (box->win.map[j][i] == 'E' && flag == 0)
					box->pos.theta = ft_deg_to_rad(0);
				else if (box->win.map[j][i] == 'S' && flag == 0)
					box->pos.theta = ft_deg_to_rad(90);
				else if (box->win.map[j][i] == 'W' && flag == 0)
					box->pos.theta = ft_deg_to_rad(180);
				else if (box->win.map[j][i] == 'N' && flag == 0)
					box->pos.theta = ft_deg_to_rad(270);
				else
					return (-1);
				box->win.map[j][i] = '0';
				box->pos.x = i + 0.5;
				box->pos.y = j + 0.5;
				flag = 1;
			}
			i++;
		}
		j++;
	}
	j = 0;
	while (j < box->win.row)
	{
		i = 0;
		while (i < box->win.col)
		{
			if (box->win.map[j][i] == '0' || box->win.map[j][i] == '2')
			{
				if (j == 0 || j == box->win.row || i == 0 || i == box->win.col)
					return (-1);
				else
				{
					if (box->win.map[j + 1][i] != '0' && box->win.map[j + 1][i] != '1')
					{
						return (-1);
					}
					if (box->win.map[j - 1][i] != '0' && box->win.map[j - 1][i] != '1')
					{
						return (-1);
					}
					if (box->win.map[j][i + 1] != '0' && box->win.map[j][i + 1] != '1')
					{
						return (-1);
					}
					if (box->win.map[j][i - 1] != '0' && box->win.map[j][i - 1] != '1')
					{
						return (-1);
					}
				}
			}
			i++;
		}
		j++;
	}
	if (flag)
		return (1);
	return (-1);
}
