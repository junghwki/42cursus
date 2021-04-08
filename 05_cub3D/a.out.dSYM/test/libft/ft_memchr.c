/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:18:22 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/13 19:07:30 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	value;
	size_t			index;

	temp = (unsigned char *)s;
	value = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (temp[index] == value)
			return ((void *)&temp[index]);
		index++;
	}
	return (0);
}
