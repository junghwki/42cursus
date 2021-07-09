/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:20:39 by junghwki          #+#    #+#             */
/*   Updated: 2021/07/09 17:28:13 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_arg		*args;
	t_philo		philo;
	int			idx;
	
	idx = 0;
	if (argc == 5 || argc == 6)
	{
		args = (t_arg *)malloc(sizeof(t_arg));
		args->philo_num = ft_atoi(argv[1]);
		args->time_to_die = ft_atoi(argv[2]);
		args->time_to_eat = ft_atoi(argv[3]);
		args->time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			args->must_eat_num = ft_atoi(argv[5]);
		args->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args->philo_num);
		while (idx < args->philo_num)
		{
			pthread_mutex_init(&(args->fork[idx]), NULL);
			idx++;
		}
		idx = 0;
		while (idx < args->philo_num)
		{
			// philo = (t_philo *)malloc(sizeof(t_philo));
			philo.philo_idx = idx;
			philo.args = args;
			// philo->philo_idx = idx;
			// philo->args = args;
			pthread_create(&philo.t_id, NULL, philosophers, &philo);
			idx++;
		}
		free(args);
	}
	else
	{
		write(2, "arguments error\n", 16);
	}
	return (0);
}

/*
1,000,000 microsecs = 1s
1,000 ms = 1s
*/