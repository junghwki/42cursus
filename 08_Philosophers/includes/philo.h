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
	pthread_mutex_t	*fork;
}					t_arg;

typedef struct		s_philosophers
{
	pthread_t		t_id;
	int				philo_idx;
	t_arg			*args;
}					t_philo;
/* philo.c */
int		philo_take_fork(t_philo *philo);
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);
void	philosophers(void *philo);
/* utils.c */
int		ft_atoi(const char *str);
int		ft_usleep(useconds_t microseconds);

#endif
