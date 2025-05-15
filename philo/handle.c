/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:38:02 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/15 19:12:53 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philosopher *philo, int id)
{
	int	time;

	pthread_mutex_lock(philo->simulation->write_mutex);
	time = get_current_time() - philo->simulation->start_time;
	if (!check_any_dead(philo->simulation->simulation_end))
		printf("%d %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->simulation->write_mutex);
}

void	print_fork_taken(t_simulation *sim)
{
	int	time;

	pthread_mutex_lock(sim->write_mutex);
	time = get_current_time() - sim->start_time;
	if (sim->simulation_end)
		printf("%d %d %s\n", time, sim->philo->id);
	pthread_mutex_unlock(sim->write_mutex);

}