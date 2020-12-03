/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:43:36 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/16 21:37:53 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	result_len;

	if (!s)
		return (NULL);
	if (!*s || (ft_strlen(s) <= (size_t)start))
		return (result = ft_strdup(""));
	result_len = ft_strlen(s + (size_t)start);
	if (result_len > len)
		result_len = len;
	if (!(result = (char *)malloc(sizeof(char) * (result_len + 1))))
		return (NULL);
	ft_strlcpy(result, s + start, result_len + 1);
	return (result);
}
