/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:06:28 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/15 20:18:15 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//t_philosopher	*philo;
//philo = sim->philo;

	//*yemek yemeye gitti ise hemen sonra uykuya gitsin
	//çift id sağ, sol
	//tek id sol, sağ, usleep(100)
	//unlock, tam tersi

#include "philo.h"

void	*monitor_routine(void *arg)
{
	(void) arg;
	t_simulation	*sim;

	sim = (t_simulation *)arg;
	pthread_mutex_lock(sim->dead_lock);
	if (sim->is_dead == DEAD)
	{
		pthread_mutex_unlock(sim->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(sim->dead_lock);
	return (0);
}

void	*philo_routine(void *arg)
{
	(void) arg;
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;

	if (philo->id % 2 == 0) //* Short delay for even numbered philosophers
		ft_usleep(100);
	while (!monitor_routine(philo->simulation))
	{
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

	i = -1;
	sim->start_time = get_current_time();

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
