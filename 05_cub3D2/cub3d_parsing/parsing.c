/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:17:58 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/09 19:15:05 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_check_flag(t_box *box)
{
	if (box->pars.ea_flag && box->pars.we_flag &&\
		box->pars.so_flag && box->pars.no_flag &&\
		box->pars.r_flag && box->pars.s_flag &&\
		box->pars.f_flag && box->pars.c_flag)
		return (1);
	return (0);
}

void		ft_pars_init(t_box *box)
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

void		ft_parsing_data(t_box *box)
{
	box->pars.word = ft_split(box->pars.line, ' ');
	if (!(ft_strcmp(box->pars.word[0], "R")))
		ft_resolution(box);
	else if (!(ft_strcmp(box->pars.word[0], "EA")))
		ft_ea_route(box);
	else if (!(ft_strcmp(box->pars.word[0], "WE")))
		ft_we_route(box);
	else if (!(ft_strcmp(box->pars.word[0], "SO")))
		ft_so_route(box);
	else if (!(ft_strcmp(box->pars.word[0], "NO")))
		ft_no_route(box);
	else if (!(ft_strcmp(box->pars.word[0], "S")))
		ft_s_route(box);
	else if (!(ft_strcmp(box->pars.word[0], "C")))
		ft_c_color(box);
	else if (!(ft_strcmp(box->pars.word[0], "F")))
		ft_f_color(box);
	else
		ft_error();
	ft_array_free(box->pars.word);
}

void		ft_parsing_map(t_box *box, int eof)
{
	char	*temp;

	if (!(*box->pars.line) && box->win.row && eof)
		ft_error();
	ft_element_check(box->pars.line);
	if (!(box->pars.map))
		box->pars.map = ft_strdup(box->pars.line);
	else
	{
		if (box->win.col < ft_strlen(box->pars.line))
			box->win.col = ft_strlen(box->pars.line);
		temp = box->pars.map;
		box->pars.map = ft_strjoin(box->pars.map, "#");
		free(temp);
		temp = box->pars.map;
		box->pars.map = ft_strjoin(box->pars.map, box->pars.line);
		free(temp);
	}
	box->win.row++;
}

void		ft_parsing_cub(t_box *box, int fd)
{
	int		eof;

	ft_pars_init(box);
	while ((eof = get_next_line(fd, &box->pars.line)) >= 0)
	{
		if (!(*box->pars.line) && eof && !box->win.row)
		{
			free(box->pars.line);
			continue;
		}
		if (!ft_check_flag(box))
			ft_parsing_data(box);
		else
			ft_parsing_map(box, eof);
		free(box->pars.line);
		if (eof == 0)
			break ;
	}
	ft_make_base(box);
	ft_map_dup(box);
	ft_dir_check(box);
	ft_map_check(box);
	box->sprt = (t_sprt *)malloc(sizeof(t_sprt) * box->pars.s_cnt);
	box->visible = (t_sprt *)malloc(sizeof(t_sprt) * box->pars.s_cnt);
	ft_sprt_pos(box);
}
