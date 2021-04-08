/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:39:43 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/20 14:34:44 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	ch;

	index = 0;
	ch = (char)c;
	while (s[index])
	{
		if (s[index] == ch)
			return ((char *)&s[index]);
		index++;
	}
	if (c == 0)
		return ((char *)&s[index]);
	return (0);
}
