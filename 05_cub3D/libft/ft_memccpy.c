/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:17:28 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/16 21:05:27 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;
	unsigned char	value;

	index = 0;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	value = (unsigned char)c;
	while (index < n)
	{
		dst_temp[index] = src_temp[index];
		if (src_temp[index] == value)
			return ((void *)&dst[index + 1]);
		index++;
	}
	return (0);
}
