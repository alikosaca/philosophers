/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:26:02 by akosaca           #+#    #+#             */
/*   Updated: 2025/08/08 15:25:37 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork(t_simulation	*sim)
{
	int	i;

	i = -1;
	sim->forks = malloc(sim->num_philo * sizeof(t_fork)); //? +1 kadar yer açmadık ilerde sorun olabilir mi
	if (!sim->forks)
		return (return_err("Ups! init error occurred"));
	while (++i < sim->num_philo)
	{
		sim->forks[i].id = i;
		sim->forks[i].status = true;
		pthread_mutex_init(&sim->forks[i].mutex, NULL);
	}
	return (0);
}

static int	init_philo(t_simulation	*sim)
{
	int	i;

	i = -1;
	sim->philo = malloc(sim->num_philo * sizeof(t_philosopher));
	if (!sim->philo)
		return (return_err("Ups! init error occurred"));
	while (++i < sim->num_philo)
	{
		sim->philo[i].id = i + 1;
		sim->philo[i].eat_count = 0;
		sim->philo[i].thread = 0; //? niçin var. can be problem?
		sim->philo[i].right_fork = NULL;
		sim->philo[i].left_fork = NULL;
		sim->philo[i].last_meal_time = 0;
		sim->philo[i].simulation = sim; //? gerek var mı
	}
	return (0);
}

static	int	assign_forks_to_philos(t_simulation *sim)
{
	int	i;

	i = -1;

	while (++i < sim->num_philo)
	{
		sim->philo[i].right_fork = &sim->forks[i];
		if (i == 0)
			sim->philo[i].left_fork = &sim->forks[sim->num_philo - 1];
		else
			sim->philo[i].left_fork = &sim->forks[i - 1];
		sim->philo[i].simulation = sim;
	}
	return (0);
}

static int	init_input(int argc, char **argv, t_simulation *sim)
{
	memset(sim, 0, sizeof(t_simulation)); //? memset kullanımına izin veriyorlar mı?
	sim->num_philo = ft_atoi(argv[1]);
	sim->time_to_die = ft_atoi(argv[2]);
	sim->time_to_eat = ft_atoi(argv[3]);
	sim->time_to_sleep = ft_atoi(argv[4]);
	sim->is_dead = false;
	sim->start_time = 0;
	sim->philo = NULL;
	sim->forks = NULL;
	if (argc == 6)
		sim->number_of_meals = ft_atoi(argv[5]);
	else
		sim->number_of_meals = 0;
	return (0);
}

static int	init_mutexes(t_simulation *sim)
{
	sim->write_mutex = malloc(sizeof(pthread_mutex_t));
	sim->dead_lock = malloc(sizeof(pthread_mutex_t));

	if (!sim->write_mutex || !sim->dead_lock)
		return (return_err("Mutex memory allocation failed")); //? memory leak'e karşı önlem al!

	if (pthread_mutex_init(sim->write_mutex, NULL) != 0
		|| pthread_mutex_init(sim->dead_lock, NULL) != 0)
		return (return_err("Mutex initialization failed"));
	return (0);
}

int	init_sim(int argc, char **argv, t_simulation *sim)
{
	if (init_input(argc, argv, sim))
		return (1);
	if (init_mutexes(sim))
		return (1);
	if (init_fork(sim))
		return (1);
	if (init_philo(sim))
		return (1);
	if (assign_forks_to_philos(sim))
		return (1);
	return (0);
}
