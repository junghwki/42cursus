/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:33:28 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/20 13:31:06 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst_temp;
	unsigned char *src_temp;

	if (!dst && !src)
		return (NULL);
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	if (dst_temp < src_temp)
		while (len)
		{
			len--;
			*dst_temp++ = *src_temp++;
		}
	else
	{
		dst_temp = dst_temp + len - 1;
		src_temp = src_temp + len - 1;
		while (len)
		{
			len--;
			*dst_temp-- = *src_temp--;
		}
	}
	return (dst);
}
