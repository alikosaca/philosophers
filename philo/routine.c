/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:55:12 by akosaca           #+#    #+#             */
/*   Updated: 2025/07/28 19:57:38 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	think(t_philosopher *philo)
{
	print_message("is thinking", philo);
	return (0);
}

int	dream(t_philosopher *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->simulation->time_to_sleep);
	return (0);
}

	int	eat(t_philosopher *philo) 
	{
		printf("id: %d\n", philo->id);
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->left_fork->mutex);
			print_message("has taken a fork left", philo);
			pthread_mutex_lock(&philo->right_fork->mutex);
			print_message("has taken a fork right", philo);

		}
		else
		{
			pthread_mutex_lock(&philo->right_fork->mutex);
			print_message("has taken a fork right", philo);
			pthread_mutex_lock(&philo->left_fork->mutex);
			print_message("has taken a fork left", philo);
		}
		print_message("is eating", philo);
		//philo->is_eating = true; //?
		pthread_mutex_lock(philo->simulation->meal_mutex);
		philo->last_meal_time = get_current_time();
		philo->eat_count++;
		pthread_mutex_unlock(philo->simulation->meal_mutex);
		ft_usleep(philo->simulation->time_to_eat);
		//philo->is_eating = false;
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return (0);
	}

