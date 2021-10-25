/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:20:42 by junghwki          #+#    #+#             */
/*   Updated: 2021/07/30 00:07:32 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK_MSG	"has taken a fork"
# define EAT_MSG	"is eating"
# define SLEEP_MSG	"is sleeping"
# define THINK_MSG	"is thinking"

typedef struct s_arguments
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	struct timeval	start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}					t_arg;

typedef struct s_philosopher
{
	t_arg			*args;
	pthread_t		t_id;
	int				philo_idx;
	int				left_fork;
	int				right_fork;
	int				eat_cnt;
	struct timeval	last_meal;
}					t_philo;

int					philosopher(void *philo);
int					ft_atoi(const char *str);
int					ft_usleep(useconds_t microseconds);
int					runtime(struct timeval old_time);
void				print_msg(t_philo *philo, char *msg);

#endif
