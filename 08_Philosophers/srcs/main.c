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

//t_arg		*argument_init(int argc, char **argv)
//{

//}

int	main(int argc, char **argv)
{
	t_arg		*args;
	t_philo		*philo;
	int			idx;
	int			eat_cnt;
	int			flag;
	
	idx = 0;
	flag = 0;
	eat_cnt = 0;
	if (argc == 5 || argc == 6)
	{
		args = (t_arg *)malloc(sizeof(t_arg));
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
		pthread_mutex_init(&args->print, NULL);
		while (idx < args->philo_num)
		{
			pthread_mutex_init(&(args->fork[idx]), NULL);
			idx++;
		}
		idx = 0;
		philo = (t_philo *)malloc(sizeof(t_philo) * args->philo_num);
		gettimeofday(&args->start_time, NULL);
		while (idx < args->philo_num)
		{
			philo[idx].philo_idx = idx;
			philo[idx].args = args;
			philo[idx].eat_cnt = 0;
			pthread_create(&(philo[idx].t_id), NULL, (void *)philosophers, &philo[idx]);
			pthread_detach(philo[idx].t_id);
			idx++;
		}
		while (!flag)
		{
			idx = 0;
			while (idx < args->philo_num)
			{
				if (runtime(philo[idx].last_meal) > args->time_to_die)
				{
					pthread_mutex_lock(&(philo->args->print));
					printf("%d ms %d is died\n", runtime(args->start_time), idx + 1);
					flag = 1;
					break ;
				}
				if ((argc == 6) && (philo[idx].eat_cnt <= args->must_eat_num))
					eat_cnt = philo[idx].eat_cnt;
				idx++;
			}
			if ((argc == 6) && (eat_cnt >= args->must_eat_num))
				break ;
		}
		free(args->fork);
		free(args);
	}
	else
		write(2, "arguments error\n", 16);
	return (0);
}

/*
1,000,000 microsecs = 1s
1,000 ms = 1s
*/
