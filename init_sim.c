/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:26:02 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/09 18:50:08 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork(t_simulation	*simulation)
{
	int	i;

	i = 0;
	simulation->forks = malloc(simulation->num_philo * sizeof(t_fork));
	if (!simulation->forks)
		return (return_err("Ups! init error occurred"));
	while (i < simulation->num_philo)
	{
		
		simulation->forks[i].id = i;
		simulation->forks[i].status = true;
		pthread_mutex_init(&simulation->forks[i].mutex, NULL);
		i++;
	}
	return (0);
}
//! thread başlatma işlemini gerçekelştirmedik
//! simulation->philosophers[i].thread = 0; olarak ayarladık  
static int	init_philo(t_simulation	*simulation)
{
	int	i;

	i = 0;
	simulation->philosophers = malloc(simulation->num_philo * sizeof(t_fork));
	if (!simulation)
		return (return_err("Ups! init error occurred"));
	while (i < simulation->num_philo)
	{
		simulation->philosophers[i].id = i;
		simulation->philosophers[i].eat_count = 0;
		simulation->philosophers[i].right_fork = NULL;
		simulation->philosophers[i].left_fork = NULL;
		simulation->philosophers[i].last_meal_time = NULL;
		simulation->philosophers[i].thread = 0;
		simulation->philosophers[i].is_eating = false;
		i++;
	}
	return (0);
}

static int	init_input(int argc, char **argv, t_simulation *simulation)
{
	
	simulation->num_philo = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	simulation->number_of_meals = -1;
	simulation->simulation_end = false;
	simulation->start_time = 0;
	simulation->philosophers = NULL;
	simulation->forks = NULL;	
	if (argc == 6)
		simulation->number_of_meals = ft_atoi(argv[5]);
	return (0);
}

int	init_sim(int argc, char **argv, t_simulation *simulation)
{
	if (init_input(argc, argv, &simulation))
		return (1);
	if (init_fork(&simulation))
		return (1);
	if (init_philo(&simulation))
		return (1);
	return (0);
}
/*


*/