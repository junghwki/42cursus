#include "../includes/philo.h"

int		philo_sleep(t_philo *philo)
{
	ft_print_msg(philo, SLEEP_MSG);
	ft_usleep(philo->args->time_to_sleep * 1000);
	return (0);
}

int		philo_eat(t_philo *philo)
{
	ft_print_msg(philo, EAT_MSG);
	ft_usleep(philo->args->time_to_eat * 1000);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
	//ft_print_msg(philo, "left fork out");
	pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
	//ft_print_msg(philo, "right fork out");
	philo_sleep(philo);
	return (0);
}

int		philo_think(t_philo *philo)
{
	ft_print_msg(philo, THINK_MSG);
	return (0);
}

int		philo_take_fork(t_philo *philo)
{
	
}

int		even_philo_think(t_philo *philo)
{
	ft_print_msg(philo, THINK_MSG);
	pthread_mutex_lock(&philo->args->fork[philo->left_fork]);
	//ft_print_msg(philo, "has taken a left fork");
	pthread_mutex_lock(&philo->args->fork[philo->right_fork]);
	ft_print_msg(philo, "has taken a right fork");
	//if (current_time_calc(philo->last_meal) < philo->args->time_to_die)
	//{
		philo_eat(philo);
	//}
	//else
	//{
	//	pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
	//	pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
	//	pthread_mutex_lock(&(philo->args->print));
	//	printf("%d ms %d is died\n", current_time_calc(philo->args->start_time), philo->philo_idx + 1);
	//	return (-1);
	//}
	return (0);
}

int		odd_philo_think(t_philo *philo)
{
	ft_print_msg(philo, THINK_MSG);
	pthread_mutex_lock(&philo->args->fork[philo->right_fork]);
	//ft_print_msg(philo, "has taken a right fork");
	pthread_mutex_lock(&philo->args->fork[philo->left_fork]);
	ft_print_msg(philo, "has taken a left fork");
	//if (current_time_calc(philo->last_meal) < philo->args->time_to_die)
	//{
		philo_eat(philo);
	//}
	//else
	//{
	//	pthread_mutex_unlock(&philo->args->fork[philo->right_fork]);
	//	pthread_mutex_unlock(&philo->args->fork[philo->left_fork]);
	//	pthread_mutex_lock(&(philo->args->print));
	//	printf("%d ms %d is died\n", current_time_calc(philo->args->start_time), philo->philo_idx + 1);
	//	return (-1);
	//}
	return (0);
}

int		philosophers(void *philo)
{
	t_philo	*temp;

	temp = (t_philo *)philo;
	temp->left_fork = (temp->philo_idx + 1) % (temp->args->philo_num);
	temp->right_fork = temp->philo_idx;
	if (temp->philo_idx % 2 != 0)
		ft_usleep(temp->args->time_to_eat * 1000 - 1000);
	while (1)
	{
		//if (temp->philo_idx % 2 == 0)
		//{
			even_philo_think(temp);
			//if (even_philo_think(temp) < 0)
				//break ;
		//}
		//else
		//{
		//	odd_philo_think(temp);
		//	//if (odd_philo_think(temp) < 0)
		//		//break ;
		//}
		usleep(50);
	}
	return (-1);
}
