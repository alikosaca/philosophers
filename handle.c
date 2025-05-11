/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:38:02 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/11 13:07:34 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_simulation *sim)
{
	int	time;

	pthread_mutex_lock(sim->write_mutex);
	time = get_current_time() - sim->start_time;
	if (check_any_dead(sim) != DEAD)
		printf("%d %d %s\n", time, sim->philosophers->id, str);
	pthread_mutex_unlock(sim->write_mutex);
}