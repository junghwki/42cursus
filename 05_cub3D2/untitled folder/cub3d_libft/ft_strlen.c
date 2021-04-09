/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:38:17 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/09 11:33:18 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}
