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
		gettimeofday(&args->start_time, NULL);
		args->philo_num = ft_atoi(argv[1]);
		args->time_to_die = ft_atoi(argv[2]);
		args->time_to_eat = ft_atoi(argv[3]);
		args->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			args->must_eat_num = ft_atoi(argv[5]);
		if (args->philo_num < 0 || args->time_to_die < 0 || args->time_to_eat < 0 ||
			args->time_to_sleep < 0 || args->must_eat_num < 0)
			{
				write(2, "arguments error\n", 16);
				return (0);
			}
		args->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args->philo_num);
		while (idx < args->philo_num)
		{
			pthread_mutex_init(&(args->fork[idx]), NULL);
			idx++;
		}
		idx = 0;
		while (idx < args->philo_num)
		{
			printf("before idx : %d\n", idx);
			philo.philo_idx = idx;
			philo.args = args;
			gettimeofday(&philo.last_eat_time, NULL);
			pthread_create(&philo.t_id, NULL, (void *)philosophers, &philo);
			idx++;
		}
		pthread_join(philo.t_id, NULL);
		free(args->fork);
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
