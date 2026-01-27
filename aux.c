/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:36:44 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/27 15:53:13 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_print(char *str, t_philo *philo)
{
	long	time;

	//Func de morte
	pthread_mutex_lock(&philo->data->mutex.write_flag);
	time = ft_get_time() - philo->data->start_time;
	printf("%ld %ld %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->mutex.write_flag);
}

void	ft_sleep(t_data *data, int time)
{
	long	start_sleep;
	long	elapsed;
	(void)data;

	start_sleep = ft_get_time();
	while (1)
	{
		//func de morte
		elapsed = ft_get_time() - start_sleep;
		if (elapsed >= time)
			break;
		usleep(1000);
	}
}
