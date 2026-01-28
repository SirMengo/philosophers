/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:04:19 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/28 17:01:41 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <stddef.h>
# include <sys/time.h>

# include "structs.h"
# include "./srcs/srcs.h"

//actions.c
void	*routine(void *arg);
//init.c
int		init_all(t_data *data, char **args);
//aux.c
void	mutex_print(char *str, t_philo *philo);
void	ft_sleep(t_data *data, int time);
int		check_eat_limit(t_philo *philo);
int		time_of_death(t_philo *philo);
int		ft_death(t_data *data);

#endif