#include "../includes/philo.h"

int		philo_eat(t_philo *philo)
{
	printf("ms %d is eating\n", philo->philo_idx + 1);
	ft_usleep(philo->args->time_to_eat * 1000);
	gettimeofday(&philo->last_eat_time, NULL);
	pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
	return (0);
}

int		philo_sleep(t_philo *philo)
{
	printf("ms %d is sleeping\n", philo->philo_idx);
	ft_usleep(philo->args->time_to_sleep * 1000);
	return (0);
}

int		even_philo_think(t_philo *philo)
{
	struct timeval	current_time;

	printf("ms %d is thinking\n", philo->philo_idx + 1);
	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&philo->args->fork[philo->left_fork]);
	printf("ms %d has taken a fork\n", philo->philo_idx + 1);
	pthread_mutex_lock(&philo->args->fork[philo->right_fork]);
	printf("ms %d has taken a fork\n", philo->philo_idx + 1);
	if (time_calc(philo->last_eat_time, current_time) < philo->args->must_eat_num)
	{
		philo_eat(philo);
	}
	else
	{
		pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
		pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
		printf("phillosopher dead\n");
	}
	return (0);
}

int		odd_philo_think(t_philo *philo)
{
	struct timeval	current_time;

	printf("ms %d is thinking\n", philo->philo_idx + 1);
	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&philo->args->fork[philo->right_fork]);
	printf("ms %d has taken a fork\n", philo->philo_idx + 1);
	pthread_mutex_lock(&philo->args->fork[philo->left_fork]);
	printf("ms %d has taken a fork\n", philo->philo_idx + 1);
	if (time_calc(philo->last_eat_time, current_time) < philo->args->must_eat_num)
	{
		philo_eat(philo);
	}
	else
	{
		pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
		pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
		printf("phillosopher dead\n");
	}
	return (0);
}

void	philosophers(void *philo)
{
	t_philo	*temp;

	temp = (t_philo *)philo;
	temp->left_fork = (temp->philo_idx + 1) % (temp->args->philo_num);
	temp->right_fork = temp->philo_idx;
	printf("idx %d\n", temp->philo_idx);//temp->philo_idx % 2);
	while (1)
	{
		if (temp->philo_idx % 2 == 0)
		{
			even_philo_think(temp);
		}
		else
		{
			odd_philo_think(temp);
		}
	}
}
