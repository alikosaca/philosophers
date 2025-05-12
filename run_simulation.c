/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:06:28 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/12 17:59:09 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_routine()
{
	//çift id sağ, sol
	//tek id sol, sağ, usleep(100)
	//unlock, tam tersi
	return (0);
}


int	run_simulation(t_simulation *sim)
{
	int	i;

	i = 0;
	if (sim->num_philo == 1)
		return (return_err("The number of philos is very small")); //!we must free!
	
	while (sim->number_of_meals)
	{
		//? start sim
	}
	
	return (0);
}
