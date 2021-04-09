/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:48:00 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/07 15:03:46 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_array_free(char **array)
{
	int		idx;

	idx = 0;
	while (array[idx])
	{
		free(array[idx]);
		idx++;
	}
	free(array);
}

int			ft_rowlen(char **array)
{
	int		idx;

	idx = 0;
	while (array[idx])
		idx++;
	return (idx);
}

void		ft_nbr_check(char *nbr)
{
	while (*nbr)
	{
		if (!(ft_isdigit(*nbr)))
			ft_error();
		nbr++;
	}
}

void		ft_element_check(char *nbr)
{
	while (*nbr)
	{
		if ((*nbr >= '0' && *nbr <= '2') || *nbr == 'E' || *nbr == 'W'\
		|| *nbr == 'S' || *nbr == 'N' || *nbr == ' ')
			nbr++;
		else
			ft_error();
	}
}
