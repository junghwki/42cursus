/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:39:56 by junghwki          #+#    #+#             */
/*   Updated: 2021/03/11 14:11:05 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		index;

	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	index = 0;
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
