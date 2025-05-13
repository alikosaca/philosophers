/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:06:28 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/13 20:10:23 by akosaca          ###   ########.fr       */
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
	return (NULL);
}

void	*philo_routine(void *arg)
{
	(void) arg;
	t_simulation	*sim;

	sim = (t_simulation *)arg;

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
		pthread_create(&sim->philo[i].thread, NULL, philo_routine, sim);

	}

	pthread_create(&monitor, NULL, monitor_routine, sim);
	i = -1;
	while (++i < sim->num_philo)
		pthread_join(sim->philo[i].thread, NULL);
	pthread_join(monitor, NULL);

	return (0);
}
