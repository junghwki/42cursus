/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:04:16 by junghwki          #+#    #+#             */
/*   Updated: 2021/04/08 14:46:33 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcmp(const char *s1, const char *s2)
{
	int		index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] != s2[index] || s1[index] == '\0' || s2[index] == '\0')
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}
