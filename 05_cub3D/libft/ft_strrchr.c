/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:46:55 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/20 14:35:34 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	ch;

	index = ft_strlen(s);
	ch = (char)c;
	while (index >= 0)
	{
		if (s[index] == ch)
			return ((char *)&s[index]);
		index--;
	}
	return (0);
}
