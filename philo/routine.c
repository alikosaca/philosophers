/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:55:12 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/13 20:42:01 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//* rutinleri buradan işleme sokuyoruz

void	think(t_simulation *sim)
{
	print_message("is thinking", sim);
}

void	dream(t_simulation *sim)
{
	print_message("is sleeping", sim);
	ft_usleep(sim->time_to_sleep);
}

void	eat(t_simulation *sim)
{
	//!
}
