/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:42:01 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/21 19:34:57 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	res_start;
	size_t	res_end;
	size_t	index;

	index = 0;
	if (!s1)
		return (NULL);
	while (s1[index] && ft_strchr(set, s1[index]))
		index++;
	res_start = index;
	index = ft_strlen(s1) - 1;
	while (s1[index] && ft_strchr(set, s1[index]) && index)
		index--;
	res_end = index;
	if (res_end <= res_start)
		return (ft_strdup(""));
	if (!(result = (char *)malloc(sizeof(char) * (res_end - res_start + 2))))
		return (NULL);
	ft_strlcpy(result, &s1[res_start], (res_end - res_start + 2));
	return (result);
}
