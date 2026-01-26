/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:03:51 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/26 14:51:18 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	static t_initvals initvals;

	if (argc >= 5 && argc <= 6)
	{
		if (argc == 6)
			parser(argv, &initvals, 1);
		else
			parser(argv, &initvals, 0);
	}
	else
	{
		write(2, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
	printf("nbr:%ld\n forks:%ld\n time_die:%ld\n time_eat:%ld\n time_sleep:%ld\n repeats:%ld\n", initvals.nbr, initvals.nbr, initvals.time_die, initvals.time_eat, initvals.time_sleep, initvals.repeats);
}
