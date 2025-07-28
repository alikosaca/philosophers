/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:06:28 by akosaca           #+#    #+#             */
/*   Updated: 2025/07/28 19:57:54 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *arg)
{
	t_simulation	*sim;
	int				res;

	res = 0;
	sim = (t_simulation *)arg;
	pthread_mutex_lock(sim->dead_lock);
	if (sim->is_dead)
	{
		sim->simulation_end = true;
		pthread_mutex_unlock(sim->dead_lock);
		printf("philo öldü!\n");
		return (NULL);
	}
	pthread_mutex_unlock(sim->dead_lock);
	return ((void *)1);
}

static int	is_enough(t_philosopher *philo)
{
	printf("philo[%d] yemek sayısı[%d] \n", philo->id, philo->eat_count);
	pthread_mutex_lock(philo->simulation->end_mutex);
	if (philo->eat_count == philo->simulation->number_of_meals)
	{
		philo->simulation->simulation_end = true;
		pthread_mutex_unlock(philo->simulation->end_mutex);
		return (1);
	}
	else
	{
		philo->eat_count++;
		pthread_mutex_unlock(philo->simulation->end_mutex);
		return (0);
	}
}

void	*philo_routine(void *arg)
{
	//(void) arg;
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0) //* Short delay for even numbered philosophers
		ft_usleep(100);
	
	while (monitor_routine(philo->simulation) == (void *)1)
	{
		if (philo->simulation->number_of_meals != 0 && is_enough(philo))
		{
			printf("philo bitti id[%d] \n", philo->id);
			return (NULL);
		}
		eat(philo);
		dream(philo);
		think(philo);
	}

	return (NULL);
}

int	run_simulation(t_simulation *sim)
{
	pthread_t	monitor;
	int			i;

	printf("--------run simulation----------\n");
	i = -1;
	sim->start_time = get_current_time(); //? nasıl hesaplanıyor
	printf("start time: %lld \n", sim->start_time);
	while (++i < sim->num_philo)
	{
		if (pthread_create(&sim->philo[i].thread, NULL, philo_routine, &sim->philo[i]))
			return (1);
	}
	if (pthread_create(&monitor, NULL, monitor_routine, sim))
		return (1);
	if (pthread_join(monitor, NULL))
		return (1);
	i = -1;
	while (++i < sim->num_philo)
	{
		if (pthread_join(sim->philo[i].thread, NULL))
			return (1);
	}
	return (0);
}
