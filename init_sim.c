/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:26:02 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/07 18:59:34 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_simulation	*simulation)
{
	return (0);
}

int	init_philo(t_simulation	*simulation)
{
	return (0);
}


int	init_sim(int argc, char **argv, t_simulation *simulation)
{
	if (argc < 5 || argc > 6)
		printf("Argüman sayısı Hatalı!");
	init_fork(&simulation);
	init_philo(&simulation);
	
	return (0);
}
/*

	simulation->number_of_philosophers = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	printf("a %s\n", argv[1]);
	printf("b %c\n", argv[1][0]);
	printf("c %d\n", ft_atoi(argv[1]));
	simulation->number_of_meals = -1;
	if (argc == 6)
	{
		simulation->number_of_meals = ft_atoi(argv[5]);
		if (simulation->number_of_meals == 0)
			printf("akosaca'ya selam yolumuza devam\n");
	}

	simulation->simulation_end = false;
	simulation->start_time = 0;
	simulation->philosophers = NULL;
	simulation->forks = NULL;


*/