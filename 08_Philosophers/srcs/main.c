/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:20:39 by junghwki          #+#    #+#             */
/*   Updated: 2021/07/30 00:39:53 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_arg	*argument_init(int argc, char **argv)
{
	t_arg	*args;
	int		idx;

	idx = 0;
	args = (t_arg *)malloc(sizeof(t_arg));
	args->philo_num = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->must_eat_num = ft_atoi(argv[5]);
	else
		args->must_eat_num = 0;
	args->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* args->philo_num);
	pthread_mutex_init(&args->print, NULL);
	while (idx < args->philo_num)
	{
		pthread_mutex_init(&(args->fork[idx]), NULL);
		idx++;
	}
	return (args);
}

t_philo	*philo_thread_create(t_arg *args)
{
	t_philo	*philo;
	int		idx;

	idx = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * args->philo_num);
	while (idx < args->philo_num)
	{
		philo[idx].philo_idx = idx;
		philo[idx].args = args;
		philo[idx].eat_cnt = 0;
		pthread_create(&(philo[idx].t_id), NULL,
			(void *)philosopher, &philo[idx]);
		pthread_detach(philo[idx].t_id);
		idx++;
	}
	return (philo);
}

void	monitoring(t_arg *args, t_philo *philo)
{
	int	idx;
	int	flag;
	int	eat_cnt;

	flag = 0;
	eat_cnt = 0;
	while (!flag)
	{
		idx = 0;
		while (idx < args->philo_num)
		{
			if (runtime(philo[idx].last_meal) > args->time_to_die)
			{
				pthread_mutex_lock(&(args->print));
				printf("%d ms %d is died\n", runtime(args->start_time), idx + 1);
				flag = 1;
				break ;
			}
			if (args->must_eat_num && philo[idx].eat_cnt <= args->must_eat_num)
				eat_cnt = philo[idx].eat_cnt;
			idx++;
		}
		if (args->must_eat_num && (eat_cnt >= args->must_eat_num))
			break ;
	}
}

int	main(int argc, char **argv)
{
	t_arg		*args;
	t_philo		*philo;

	if (argc == 5 || argc == 6)
	{
		args = argument_init(argc, argv);
		if (args->philo_num < 0 || args->time_to_die < 0
			|| args->time_to_eat < 0 || args->time_to_sleep < 0
			|| args->must_eat_num < 0)
		{
			write(2, "arguments error\n", 16);
			free(args->fork);
			free(args);
			return (0);
		}
		philo = philo_thread_create(args);
		monitoring(args, philo);
		free(args->fork);
		free(args);
	}
	else
		write(2, "arguments error\n", 16);
	return (0);
}
