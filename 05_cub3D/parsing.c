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

void	ft_map_nbr(char *nbr)
{
	while (*nbr)
	{
		if ((*nbr >= '0' && *nbr <= '2') || *nbr == 'E' || *nbr == 'W' || *nbr == 'S' || *nbr == 'N')
			nbr++;
		else
			ft_error();
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
	box->win.map[box->win.row] = NULL;
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
	ft_pars_init(box);
	while (get_next_line(fd, &box->pars.line) > 0)
	{
		// if (ft_check_flag(box) == 0)
			box->pars.word = ft_split(box->pars.line, ' ');
		if (!*box->pars.line && box->win.row)
			ft_error();
		if (!*box->pars.line) //개행 처리
			continue;
		if (!(ft_strcmp(box->pars.word[0], "R")) && ft_rowlen(box->pars.word) == 3)
			ft_resolution(box);
		else if (!(ft_strcmp(box->pars.word[0], "EA")) && ft_rowlen(box->pars.word) == 2)
			ft_ea_route(box);
		else if (!(ft_strcmp(box->pars.word[0], "WE")) && ft_rowlen(box->pars.word) == 2)
			ft_we_route(box);
		else if (!(ft_strcmp(box->pars.word[0], "SO")) && ft_rowlen(box->pars.word) == 2)
			ft_so_route(box);
		else if (!(ft_strcmp(box->pars.word[0], "NO")) && ft_rowlen(box->pars.word) == 2)
			ft_no_route(box);
		else if (!(ft_strcmp(box->pars.word[0], "S")) && ft_rowlen(box->pars.word) == 2)
			ft_s_route(box);
		else if (!(ft_strcmp(box->pars.word[0], "C")) && ft_rowlen(box->pars.word) == 2)
			ft_c_color(box);
		else if (!(ft_strcmp(box->pars.word[0], "F")) && ft_rowlen(box->pars.word) == 2)
			ft_f_color(box);
		else if (ft_check_flag(box)) //플래그 다들어왔나 확인
		{
			ft_map_nbr(box->pars.line);
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
		else
			ft_error();
		if (box->pars.word)
			ft_array_free(box->pars.word);
		free(box->pars.line);
	}
	if (box->pars.line)
	{
		if (box->win.col < ft_strlen(box->pars.line))
			box->win.col = ft_strlen(box->pars.line);
		box->pars.map = ft_strjoin(box->pars.map, "#");
		box->pars.map = ft_strjoin(box->pars.map, box->pars.line);
	}
	ft_make_base(box);
	ft_map_dup(box, ft_split(box->pars.map, '#'));
	// ft_map_print(box);
	ft_map_check(box);
	box->sprt = (t_sprt *)malloc(sizeof(t_sprt) * box->pars.s_cnt);
	box->visible = (t_sprt *)malloc(sizeof(t_sprt) * box->pars.s_cnt);
	ft_sprt_pos(box);
}
