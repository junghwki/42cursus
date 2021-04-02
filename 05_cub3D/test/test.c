#include <math.h>
#include <stdio.h>
#include "../cub3d.h"

int	main(void)
{
	int i;
	int fd;
	char	*line;
	char	**line_word;

	fd = open("./test.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		line_word = ft_split(line, ' ');
		while(line_word[i])
		{
			printf("%s\n",line_word[i]);
			i++;
		}
		ft_array_free(line_word);
	}
	return (0);
}