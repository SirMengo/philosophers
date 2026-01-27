/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:03:51 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/27 15:47:57 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_philo *philo)
{
	int	id;

	id = 0;
	while(id < philo->data->initvals.nbr)
	{
		pthread_create(&philo[id].thread, NULL, &routine, &philo[id]);
		id++;
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
		start_philo(data.philo);
	}
	else
	{
		write(2, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
}
