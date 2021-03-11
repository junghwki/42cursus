/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:16:52 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/16 21:45:57 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			index;
	unsigned char	*temp;

	index = 0;
	temp = (unsigned char *)s;
	while (index < n)
	{
		temp[index] = 0;
		index++;
	}
	return (s);
}
