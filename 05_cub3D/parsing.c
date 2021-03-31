#include "cub3d.h"

void 	ft_nbr_check(char *nbr)
{
	while (*nbr)
	{
		if (!(ft_isdigit(*nbr)))
			ft_error();
		nbr++;
	}
}

void 	ft_map_print(t_box *box)
{
	int i;

	i = 0;
	while (i < box->win.row)
	{
		printf("%s\n", box->win.map[i]);
		i++;
	}
}

void 	ft_make_base(t_box *box)
{
	int i;
	int j;

	i = 0;
	box->win.map = (char **)malloc(sizeof(char *) * (box->win.row + 1));
	while (i < box->win.row)
	{
		box->win.map[i] = (char *)malloc(box->win.col + 1);
		i++;
	}
	j = 0;
	while (j < box->win.row)
	{
		i = 0;
		while (i < box->win.col)
		{
			box->win.map[j][i] = ' ';
			i++;
		}
		box->win.map[j][i] = '\0';
		j++;
	}
}

void 	ft_get_map(t_box *box, int fd)
{
	char **temp;
	int	eof;

	ft_pars_init(box);
	while (get_next_line(fd, &box->pars.line) > 0)
	{
		// eof = get_next_line(fd, &box->pars.line);
		box->pars.word = ft_split(box->pars.line, ' ');
		if (!(*box->pars.word)) //개행 처리
			continue;
		if (ft_isdigit(box->pars.word[0][0])) //플래그 다들어왔나 확인
		// if (ft_check_flag(box) ) //플래그 다들어왔나 확인
		{
			if (!(box->pars.map))
				box->pars.map = ft_strdup(box->pars.line);
			else
			{
				if (box->win.col < ft_strlen(box->pars.line))
					box->win.col = ft_strlen(box->pars.line);
				box->pars.map = ft_strjoin(box->pars.map, "#");
				box->pars.map = ft_strjoin(box->pars.map, box->pars.line);
			}
			box->win.row++;
		}
		else if (!(ft_strcmp(box->pars.word[0], "R")) && ft_rowlen(box->pars.word) == 3)
		{
			if (box->pars.r_flag)
				ft_error();
			ft_nbr_check(box->pars.word[1]);
			ft_nbr_check(box->pars.word[2]);
			box->win.width = ft_atoi(box->pars.word[1]);
			box->win.height = ft_atoi(box->pars.word[2]);
			box->pars.r_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "EA")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.ea_flag)
				ft_error();
			if (open(box->pars.word[1], O_RDONLY) < 0)
				ft_error();
			box->ea.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, box->pars.word[1], &box->ea.width, &box->ea.height);
			box->ea.addr = (int *)mlx_get_data_addr(box->ea.ptr, &box->ea.bits_per_pixel, &box->ea.size_line, &box->ea.endian);
			box->pars.ea_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "WE")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.we_flag)
				ft_error();
			if (open(box->pars.word[1], O_RDONLY) < 0)
				ft_error();
			box->we.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, box->pars.word[1], &box->we.width, &box->we.height);
			box->we.addr = (int *)mlx_get_data_addr(box->we.ptr, &box->img.bits_per_pixel, &box->we.size_line, &box->we.endian);
			box->pars.we_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "SO")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.so_flag)
				ft_error();
			if (open(box->pars.word[1], O_RDONLY) < 0)
				ft_error();
			box->so.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, box->pars.word[1], &box->so.width, &box->so.height);
			box->so.addr = (int *)mlx_get_data_addr(box->so.ptr, &box->img.bits_per_pixel, &box->so.size_line, &box->so.endian);
			box->pars.so_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "NO")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.no_flag)
				ft_error();
			if (open(box->pars.word[1], O_RDONLY) < 0)
				ft_error();
			box->no.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, box->pars.word[1], &box->no.width, &box->no.height);
			box->no.addr = (int *)mlx_get_data_addr(box->no.ptr, &box->img.bits_per_pixel, &box->no.size_line, &box->no.endian);
			box->pars.no_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "S")) && ft_rowlen(box->pars.word) == 2)
		{
			if (box->pars.s_flag)
				ft_error();
			if (open(box->pars.word[1], O_RDONLY) < 0)
				ft_error();
			box->s.ptr = mlx_xpm_file_to_image(box->mlx.ft_mlx, box->pars.word[1], &box->s.width, &box->s.height);
			box->s.addr = (int *)mlx_get_data_addr(box->s.ptr, &box->img.bits_per_pixel, &box->s.size_line, &box->s.endian);
			box->pars.s_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "C")) && ft_rowlen(box->pars.word) == 2)
		{
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
			// ft_array_free(temp);
			box->pars.c_flag = 1;
		}
		else if (!(ft_strcmp(box->pars.word[0], "F")) && ft_rowlen(box->pars.word) == 2)
		{
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
		else
			ft_error();
		ft_array_free(box->pars.word);
	}
	temp = ft_split(box->pars.map, '#');
	ft_make_base(box);
	ft_map_dup(box, temp);
	ft_array_free(temp);
	ft_map_print(box);
	ft_map_check(box);
	box->sprt = (t_sprt *)malloc(sizeof(t_sprt) * box->pars.s_cnt);
	box->visible = (t_sprt *)malloc(sizeof(t_sprt) * box->pars.s_cnt);
	// printf("%d\n",box->pars.s_cnt);
	ft_sprt_pos(box);
}
