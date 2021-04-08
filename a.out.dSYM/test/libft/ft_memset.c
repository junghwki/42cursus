/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:42:35 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/16 21:45:25 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*temp;

	index = 0;
	temp = (unsigned char *)b;
	while (index < len)
	{
		temp[index] = c;
		index++;
	}
	return (b);
}
