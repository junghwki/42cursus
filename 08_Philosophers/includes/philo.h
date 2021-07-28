/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwki <junghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:20:42 by junghwki          #+#    #+#             */
/*   Updated: 2021/07/09 16:41:02 by junghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK_MSG	"has taken a fork"
# define EAT_MSG	"is eating"
# define SLEEP_MSG	"is sleeping"
# define THINK_MSG	"is thinking"
# define DIE_MSG	"is died"

typedef struct		s_arguments
{
	int				philo_num;
	int 			time_to_die;
	int 			time_to_eat;
	int 			time_to_sleep;
	int				must_eat_num;
	struct timeval	start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}					t_arg;

typedef struct		s_philosophers
{
	pthread_t		t_id;
	int				philo_idx;
	int				left_fork;
	int				right_fork;
	t_arg			*args;
	struct timeval	current_time;
	struct timeval	last_meal;
}					t_philo;
/* philo.c */
int		philosophers(void *philo);
/* utils.c */
int		ft_atoi(const char *str);
int		ft_usleep(useconds_t microseconds);
int		time_calc(struct timeval old_time, struct timeval new_time);
int		current_time_calc(struct timeval old_time);
void	ft_print_msg(t_philo *philo, char *msg);

#endif
