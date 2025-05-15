/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:55:12 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/15 20:27:55 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	think(t_simulation *sim)
{
	print_message("is thinking", sim);
	ft_usleep(100);
}

int	dream(t_simulation *sim)
{
	print_message("is sleeping", sim);
	ft_usleep(sim->time_to_sleep);
}

int	eat(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_message("has taken a fork", philo, philo->id);

		pthread_mutex_lock(&philo->right_fork->mutex);
		print_message("has taken a fork", philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_message("has taken a fork", philo, philo->id);
		
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_message("has taken a fork", philo, philo->id);
	}
	philo->is_eating = true;
	print_message("is eating", philo, philo->id);
	ft_usleep(philo->simulation->time_to_eat);
	philo->eat_count++;
	philo->is_eating = false;

	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);

	
	return (0);
}
