/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:38:02 by akosaca           #+#    #+#             */
/*   Updated: 2025/08/07 18:54:51 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//if (!check_any_dead(philo->simulation->simulation_end))
void	print_message(char *str, t_philosopher *philo)
{
	long long	time;

	if (check_simulation_end(philo->simulation))
		return ;
	pthread_mutex_lock(philo->simulation->write_mutex);
	time = get_current_time() - philo->simulation->start_time;
	printf("%lld | %d > %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->simulation->write_mutex);
}

// void	print_fork_taken(t_simulation *sim)
// {
// 	int	time;

// 	pthread_mutex_lock(sim->write_mutex);
// 	time = get_current_time() - sim->start_time;
// 	if (sim->simulation_end)
// 		printf("%d %d %s\n", time, sim->philo->id);
// 	pthread_mutex_unlock(sim->write_mutex);

// }