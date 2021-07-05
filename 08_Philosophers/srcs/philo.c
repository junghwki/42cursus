/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:20:39 by junghwki          #+#    #+#             */
/*   Updated: 2021/07/05 21:58:41 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_usleep(1234569);
}
/*
argv[1] number_of_philosophers
argv[2] time_to_die
argv[3] time_to_eat
argv[4] time_to_sleep
argv[5] [number_of_times_each_philosopher_must_eat]

1,₩000,000ms = 1s
*/