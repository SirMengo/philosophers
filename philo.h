/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:04:19 by msimoes           #+#    #+#             */
/*   Updated: 2025/09/05 13:26:41 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo{
	long nbr;
	long forks;
	long time_die;
	long time_eat;
	long time_sleep;
	long repeats;
}			t_philo;

void	parser(char **args, t_philo *philo, int flag);

#include "./srcs/srcs.h"
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

#endif