/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:57:19 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/27 14:12:16 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((index < dstsize - 1) && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	index;

	index = 0;
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	src_index;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	src_index = 0;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	if (dstsize > dst_len + 1)
	{
		while ((dst_len + src_index < dstsize - 1) && src[src_index])
		{
			dst[dst_len + src_index] = src[src_index];
			src_index++;
		}
	}
	dst[dst_len + src_index] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	str_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char *)malloc(str_len + 1)))
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, str_len + 1);
	return (result);
}
