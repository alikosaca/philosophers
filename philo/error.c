/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:26:19 by akosaca           #+#    #+#             */
/*   Updated: 2025/08/08 15:26:00 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	return_err(const char *message)
{
	printf("%s\n", message);
	return (1);
}

//? Is there a need for more freeing
void	destroy_mutex(t_simulation *sim)
{
	int	i;

	i = -1;
	if (sim->forks)
		while (++i < sim->num_philo)
			pthread_mutex_destroy(&sim->forks[i].mutex);
	if (sim->write_mutex)
		pthread_mutex_destroy(sim->write_mutex);
	if (sim->dead_lock)
		pthread_mutex_destroy(sim->dead_lock);
}

int	cleanup(t_simulation *sim)
{
	int	i;

	i = -1;
	if (sim->forks)
		while (++i < sim->num_philo)
			pthread_mutex_destroy(&sim->forks[i].mutex);
	if (sim->write_mutex)
		pthread_mutex_destroy(sim->write_mutex);
	if (sim->dead_lock)
		pthread_mutex_destroy(sim->dead_lock);
	if (sim->forks)
		free(sim->forks);
	if (sim->philo)
		free(sim->philo);
	return (1);
}
