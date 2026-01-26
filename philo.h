/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:04:19 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/26 15:25:00 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct	s_initvals{
	long nbr;
	long forks;
	long time_die;
	long time_eat;
	long time_sleep;
	long repeats;
}				t_initvals;

typedef struct	s_philo
{
	long id;
	long times_eaten;
	long last_eaten;
	pthread_t thread;
	pthread_mutex_t *fork_left;
	pthread_mutex_t *fork_right;
}				t_philo;

typedef struct	s_mutex
{
	pthread_mutex_t *fork;
}				t_mutex;

int	parser(char **args, t_initvals *initvals, int flag);

#include "./srcs/srcs.h"
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#endif