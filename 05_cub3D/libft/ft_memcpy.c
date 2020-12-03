/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:35:52 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/21 21:36:06 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	if (!dst || !src)
		return (NULL);
	index = 0;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (index < n)
	{
		dst_temp[index] = src_temp[index];
		index++;
	}
	return (dst);
}
