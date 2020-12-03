/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:24:01 by junghwki          #+#    #+#             */
/*   Updated: 2020/10/27 15:58:47 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int			ft_putline(char **line, char **next_buffer, int str_len)
{
	char			*temp;

	if (str_len >= 0)
	{
		(*next_buffer)[str_len] = '\0';
		*line = ft_strdup(*next_buffer);
		temp = ft_strdup(*next_buffer + str_len + 1);
		free(*next_buffer);
		*next_buffer = temp;
		return (1);
	}
	*line = ft_strdup(*next_buffer);
	free(*next_buffer);
	*next_buffer = NULL;
	return (0);
}

static	int			ft_strclen(char *str)
{
	int				index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

int					get_next_line(int fd, char **line)
{
	static char		*next_buffer[OPEN_MAX];
	char			*temp;
	char			*buffer;
	int				str_len;
	ssize_t			index;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!(next_buffer[fd]))
		next_buffer[fd] = ft_strdup("");
	while (((str_len = ft_strclen(next_buffer[fd])) < 0) &&
			((index = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[index] = '\0';
		temp = ft_strjoin(next_buffer[fd], buffer);
		free(next_buffer[fd]);
		next_buffer[fd] = ft_strdup(temp);
		free(temp);
	}
	free(buffer);
	if (index < 0)
		return (-1);
	return (ft_putline(line, &next_buffer[fd], str_len));
}
