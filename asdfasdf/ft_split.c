/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:12:23 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/13 19:30:23 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_free(char **array)
{
	size_t	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
	return (NULL);
}

static size_t		ft_s_l(const char *s, char c)
{
	size_t	index;
	size_t	result;

	index = 0;
	result = 1;
	if (!*s)
		return (0);
	while (s[index] == c)
		index++;
	while (s[index])
	{
		if ((s[index] == c) && s[index - 1] != c)
			result++;
		index++;
	}
	return (result);
}

static size_t		ft_wordlen(const char *s, char c)
{
	size_t	index;

	index = 0;
	while (s[index] != c && s[index])
	{
		index++;
	}
	return (index);
}

char				**ft_split(const char *s, char c)
{
	char	**answer;
	size_t	index;
	size_t	w_l;
	size_t	str_len;

	index = 0;
	str_len = 0;
	if (!s || !(answer = (char **)malloc(sizeof(char *) * (ft_s_l(s, c) + 1))))
		return (NULL);
	while (s[index])
	{
		if (s[index] != c)
		{
			w_l = ft_wordlen(s + index, c);
			if (!(answer[str_len] = (char *)malloc(sizeof(char) * w_l + 1)))
				return (ft_free(answer));
			ft_strlcpy(answer[str_len], &s[index], w_l + 1);
			str_len++;
			index = index + w_l;
		}
		while (s[index] && s[index] == c)
			index++;
	}
	answer[str_len] = NULL;
	return (answer);
}
