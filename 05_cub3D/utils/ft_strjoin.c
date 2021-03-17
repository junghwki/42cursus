/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:57:37 by junghwki          #+#    #+#             */
/*   Updated: 2021/03/15 18:11:34 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		result_index;
	char	*result;

	index = 0;
	result_index = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[index])
		result[result_index++] = s1[index++];
	index = 0;
	while (s2[index])
		result[result_index++] = s2[index++];
	result[result_index] = '\0';
	return (result);
}
