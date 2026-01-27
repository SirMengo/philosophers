/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:48:59 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/27 15:01:45 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCTS_H
# define STRUCTS_H

# include "philo.h"

typedef struct s_data	t_data;

typedef struct	s_initvals
{
	long			nbr;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			repeats;
}					t_initvals;

typedef struct	s_philo
{
	t_data			*data;
	long			id;
	long			times_eaten;
	long			last_eaten;
	int				eat_limit;
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
}					t_philo;

typedef struct	s_mutex
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	write_flag;
	pthread_mutex_t	dead_flag;
	pthread_mutex_t	eat_flag;
}					t_mutex;

typedef struct	s_data
{
	t_initvals		initvals;
	t_philo			*philo;
	t_mutex			mutex;
	int				check;
	int				dead;
	int				id_dead;
	long			start_time;
}					t_data;

#endif
