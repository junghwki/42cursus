/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:51:05 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/09 11:32:50 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	dst_len;
	int	src_len;
	int	src_index;

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
