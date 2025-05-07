/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:24:33 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/07 18:29:05 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_argument(t_simulation *simulation)
{
	printf("%d\n", simulation->number_of_philosophers);
	printf("%d: \n \n", simulation->time_to_die);
	if (simulation->number_of_philosophers <= 0)
		return(err_message("Philosophers"));
	if (simulation->time_to_die <= 0)
		return (err_message("Die"));
	if (simulation->time_to_eat <= 0)
		return (err_message("Eat"));
	if (simulation->time_to_sleep <= 0)
		return (err_message("Sleep"));
	if (simulation->number_of_philosophers > 200)
		printf("Too many philosophers can consume system resources");
	return (0);
}