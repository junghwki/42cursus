#include "../cub3d.h"

void	ft_array_free(char **array)
{
	int	idx;

	idx = 0;
	while (array[idx])
	{
		free(array[idx]);
		idx++;
	}
	free(array);
}

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
	box->pars.map = NULL;
	box->pars.s_cnt = 0;
	box->win.col = 0;
	box->win.row = 0;
	box->win.c_color = 0;
	box->win.f_color = 0;
}

int ft_rowlen(char **array)
{
	int idx;

	idx = 0;
	while (array[idx])
		idx++;
	return (idx);
}

int ft_check_flag(t_box *box)
{
	if (box->pars.ea_flag && box->pars.we_flag && 
		box->pars.so_flag && box->pars.no_flag && 
		box->pars.r_flag && box->pars.s_flag && 
		box->pars.f_flag && box->pars.c_flag)
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

int		ft_set_player_pos(t_box *box, int x, int y)
{
	if (box->win.map[y][x] == 'E')
		box->pos.theta = ft_deg2rad(0);
	else if (box->win.map[y][x] == 'S')
		box->pos.theta = ft_deg2rad(90);
	else if (box->win.map[y][x] == 'W')
		box->pos.theta = ft_deg2rad(-180);
	else if (box->win.map[y][x] == 'N')
		box->pos.theta = ft_deg2rad(-90);
	else
		ft_error();
	box->win.map[y][x] = '0';
	box->pos.x = x + 0.5;
	box->pos.y = y + 0.5;
	return (1);
}

void	ft_dir_check(t_box *box)
{
	int flag;
	int x;
	int y;
	
	flag = 0;
	y = 0;
	while (y < box->win.row)
	{
		x = 0;
		while (x < box->win.col)
		{
			if (box->win.map[y][x] == 'E' || box->win.map[y][x] == 'W' ||
			box->win.map[y][x] == 'S' || box->win.map[y][x] == 'N')
			{
				if (flag == 0)
					flag = ft_set_player_pos(box, x, y);
			}
			x++;
		}
		y++;
	}
	if (!flag)
		ft_error();
}

void ft_map_check(t_box *box)
{
	int x;
	int y;

	ft_dir_check(box);
	y = 0;
	while (y < box->win.row)
	{
		x = 0;
		while (x < box->win.col)
		{
			if (box->win.map[y][x] == '0' || box->win.map[y][x] == '2')
			{
				if (y == 0 || y == box->win.row || x == 0 || x == box->win.col)
					ft_error();
				else
				{
					if (box->win.map[y + 1][x] != '0' && box->win.map[y + 1][x] != '1' && box->win.map[y + 1][x] != '2')
						ft_error();
					if (box->win.map[y - 1][x] != '0' && box->win.map[y - 1][x] != '1' && box->win.map[y - 1][x] != '2')
						ft_error();
					if (box->win.map[y][x + 1] != '0' && box->win.map[y][x + 1] != '1' && box->win.map[y][x + 1] != '2')
						ft_error();
					if (box->win.map[y][x - 1] != '0' && box->win.map[y][x - 1] != '1' && box->win.map[y][x - 1] != '2')
						ft_error();
				}
				if (box->win.map[y][x] == '2')
					box->pars.s_cnt++;
			}
			x++;
		}
		y++;
	}
}

void ft_resolution(t_box *box)
{
	if (box->pars.r_flag)
		ft_error();
	ft_nbr_check(box->pars.word[1]);
	ft_nbr_check(box->pars.word[2]);
	box->win.width = ft_atoi(box->pars.word[1]);
	box->win.height = ft_atoi(box->pars.word[2]);
	box->pars.r_flag = 1;
}

void ft_c_color(t_box *box)
{
	char **temp;
	
	if (box->pars.c_flag)
		ft_error();
	temp = ft_split(box->pars.word[1], ',');
	if (ft_rowlen(temp) != 3)
		ft_error();
	ft_nbr_check(temp[0]);
	ft_nbr_check(temp[1]);
	ft_nbr_check(temp[2]);
	if (ft_atoi(temp[0]) > 255)
		ft_error();
	box->win.c_color = ft_atoi(temp[0]);
	box->win.c_color *= 256;
	if (ft_atoi(temp[1]) > 255)
		ft_error();
	box->win.c_color += ft_atoi(temp[1]);
	box->win.c_color *= 256;
	if (ft_atoi(temp[2]) > 255)
		ft_error();
	box->win.c_color += ft_atoi(temp[2]);
	ft_array_free(temp);
	box->pars.c_flag = 1;
}

void ft_f_color(t_box *box)
{
	char **temp;

	if (box->pars.f_flag)
		ft_error();
	temp = ft_split(box->pars.word[1], ',');
	if (ft_rowlen(temp) != 3)
		ft_error();
	ft_nbr_check(temp[0]);
	ft_nbr_check(temp[1]);
	ft_nbr_check(temp[2]);
	if (ft_atoi(temp[0]) > 255)
		ft_error();
	box->win.f_color = ft_atoi(temp[0]);
	box->win.f_color *= 256;
	if (ft_atoi(temp[1]) > 255)
		ft_error();
	box->win.f_color += ft_atoi(temp[1]);
	box->win.f_color *= 256;
	if (ft_atoi(temp[2]) > 255)
		ft_error();
	box->win.f_color += ft_atoi(temp[2]);
	ft_array_free(temp);
	box->pars.f_flag = 1;
}