/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:48:57 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/11 13:05:00 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_any_dead(t_simulation *sim)
{
	pthread_mutex_lock(sim->dead_lock);
	if (*sim->is_dead == DEAD)
	{
		pthread_mutex_unlock(sim->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(sim->dead_lock);
	return (0);
}
