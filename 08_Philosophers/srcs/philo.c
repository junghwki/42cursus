#include "../includes/philo.h"

int		philo_take_fork(t_philo *philo)
{
	int left;
	int	right = philo->philo_idx % (philo->args->philo_num - 1);

	if (philo->philo_idx == 0)
	{
		left = philo->args->philo_num;
	}
}

int		philo_eat(t_philo *philo)
{

}

int		philo_sleep(t_philo *philo)
{

}

int		philo_think(t_philo *philo)
{

}

void	philosophers(void *philo)
{
	t_philo	*temp;

	temp = (t_philo *)philo;
	while (1)
	{
		philo_take_fork(temp);
		philo_eat(temp);
		philo_sleep(temp);
		philo_think(temp);
	}
}
