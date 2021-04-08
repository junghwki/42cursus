/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:11:04 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/16 21:30:06 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_index;
	size_t	n_index;

	h_index = 0;
	n_index = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[h_index] && h_index < len)
	{
		n_index = 0;
		while (needle[n_index] && h_index + n_index < len)
		{
			if (haystack[h_index + n_index] == needle[n_index])
				n_index++;
			else
				break ;
		}
		if (needle[n_index] == '\0')
			return ((char *)&haystack[h_index]);
		h_index++;
	}
	return (0);
}
