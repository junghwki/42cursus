/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:42:09 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/13 19:07:38 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;
	size_t			index;

	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (s1_temp[index] != s2_temp[index])
			return (s1_temp[index] - s2_temp[index]);
		index++;
	}
	return (0);
}
