#include "../includes/philo.h"

int					ft_atoi(const char *str)
{
	long long int	ret;

	ret = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9' || ret > 2147483647)
			return (-1);
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret);
}

int					ft_usleep(useconds_t microseconds)
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
		if ((useconds_t)temp.tv_usec >= microseconds)
			break ;
		usleep(100);
	}
	return (0);
}

int					time_calc(struct timeval old_time, struct timeval new_time)
{
	int				ret;

	ret = (new_time.tv_sec - old_time.tv_sec) * 1000;
	ret += (new_time.tv_usec - old_time.tv_usec) / 1000;
	return (ret);
}

int					current_time_calc(struct timeval old_time)
{
	struct timeval	new_time;
	int				ret;

	gettimeofday(&new_time, NULL);
	ret = (new_time.tv_sec - old_time.tv_sec) * 1000;
	ret += (new_time.tv_usec - old_time.tv_usec) / 1000;
	return (ret);
}

int					ft_strlen(char *str)
{
	int				ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

void				ft_print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->args->print));
	printf("%d ms ", current_time_calc(philo->args->start_time));
	printf("%d %s\n", philo->philo_idx + 1, msg);
	pthread_mutex_unlock(&(philo->args->print));
}

//void				timestamp(char *str)
//{

//}
