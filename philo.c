/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:03:51 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/28 16:00:49 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_manager(t_philo *philo)
{
	int	id;

	id = 0;
	while(id < philo->data->initvals.nbr)
	{
		pthread_create(&philo[id].thread, NULL, &routine, &philo[id]);
		id++;
	}
	while (1)
	{
		if (check_eat_limit(philo))
			break ;
		if (time_of_death(philo))
			break ;
	}
	id = 0;
	while(id < philo->data->initvals.nbr)
	{
		pthread_join(philo[id].thread, NULL);
		id++;
	}
}

int	main(int ac, char **av)
{
	static t_data data;

	if (ac >= 5 && ac <= 6)
	{
		if (init_all(&data, av))
			return (1);
		philo_manager(data.philo);
	}
	else
	{
		write(2, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
}
