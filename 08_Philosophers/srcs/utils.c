#include "../includes/philo.h"

int					ft_atoi(const char *str)
{
	long long int	result;

	result = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9' || result > 2147483647)
		{
			write(2, "arguments error\n", 16);
			return (-1);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

int	ft_usleep(useconds_t microseconds)
{
	struct timeval	old_time;
	struct timeval	new_time;
	struct timeval	temp;
	useconds_t		temp_time;

	gettimeofday(&old_time, NULL);
	temp_time = microseconds;
	temp_time = (temp_time / 10) * 9;
	usleep(temp_time);
	while (1)
	{
		gettimeofday(&new_time, NULL);
		temp.tv_sec = new_time.tv_sec - old_time.tv_sec;
		temp.tv_usec = new_time.tv_usec - old_time.tv_usec;
		if (temp.tv_sec)
			temp.tv_usec += temp.tv_sec * 1000000;
		if (temp.tv_usec >= microseconds)
			break ;
		usleep(10);
	}
	printf("lib : %d\n", microseconds);
	printf("own : %d\n", temp.tv_usec);
	return (0);
}

int		ft_strlen(char *str)
{
	int	ret;

	while (str[ret])
		ret++;
	return (ret);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
