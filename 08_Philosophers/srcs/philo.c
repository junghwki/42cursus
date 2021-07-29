#include "../includes/philo.h"

void		philo_sleep(t_philo *philo)
{
	print_msg(philo, SLEEP_MSG);
	ft_usleep(philo->args->time_to_sleep * 1000);
}

void		philo_eat(t_philo *philo)
{
	print_msg(philo, EAT_MSG);
	ft_usleep(philo->args->time_to_eat * 1000);
	gettimeofday(&philo->last_meal, NULL);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
}

void		philo_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->fork[philo->left_fork]);
	pthread_mutex_lock(&philo->args->fork[philo->right_fork]);
	print_msg(philo, FORK_MSG);
}

int		philosophers(void *philo)
{
	t_philo	*temp;

	temp = (t_philo *)philo;
	temp->left_fork = (temp->philo_idx + 1) % (temp->args->philo_num);
	temp->right_fork = temp->philo_idx;
	gettimeofday(&temp->last_meal, NULL);
	if (temp->philo_idx % 2 != 0)
		ft_usleep(temp->args->time_to_eat * 1000 - 1);
	while (1)
	{
		philo_take_fork(temp);
		philo_eat(temp);
		philo_sleep(temp);
		usleep(100);
		print_msg(philo, THINK_MSG);
	}
	return (-1);
}
