/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:55:12 by akosaca           #+#    #+#             */
/*   Updated: 2025/08/07 21:26:07 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	think(t_philosopher *philo)
{
	print_message("is thinking", philo);
	return ;
}

void	dream(t_philosopher *philo)
{
	if (check_simulation_end(philo->simulation))
		return ;
	print_message("is sleeping", philo);
	ft_usleep(philo->simulation->time_to_sleep, philo->simulation);
}

void	eat(t_philosopher *philo) 
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (check_simulation_end(philo->simulation))
		return ;
	//printf("id: %d\n", philo->id);
	if (philo->id % 2 == 0)
	{
		first_fork = &philo->right_fork->mutex;
		second_fork = &philo->left_fork->mutex;
	}
	else
	{
		first_fork = &philo->left_fork->mutex;
		second_fork = &philo->right_fork->mutex;
	}
	pthread_mutex_lock(first_fork);
	print_message("has taken a fork left", philo);
	pthread_mutex_lock(second_fork);
	print_message("has taken a fork right", philo);
	print_message("is eating", philo);
	pthread_mutex_lock(philo->simulation->dead_lock);
	philo->last_meal_time = get_current_time();
	philo->eat_count++;
	pthread_mutex_unlock(philo->simulation->dead_lock);
	ft_usleep(philo->simulation->time_to_eat, philo->simulation);
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);
}


// void	eat(t_philosopher *philo) 
// {
// 	if (check_simulation_end(philo))
// 		return (1);
// 	printf("id: %d\n", philo->id);
// 	if (philo->id % 2 == 0)
// 	{
// 		pthread_mutex_lock(&philo->left_fork->mutex);
// 		print_message("has taken a fork left", philo);
// 		pthread_mutex_lock(&philo->right_fork->mutex);
// 		print_message("has taken a fork right", philo);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&philo->right_fork->mutex);
// 		print_message("has taken a fork right", philo);
// 		pthread_mutex_lock(&philo->left_fork->mutex);
// 		print_message("has taken a fork left", philo);
// 	}
// 	print_message("is eating", philo);
// 	//philo->is_eating = true; //?
// 	pthread_mutex_lock(philo->simulation->meal_mutex);
// 	philo->last_meal_time = get_current_time();
// 	philo->eat_count++;
// 	pthread_mutex_unlock(philo->simulation->meal_mutex);
// 	ft_usleep(philo->simulation->time_to_eat, philo->simulation);
// 	//philo->is_eating = false;
// 	pthread_mutex_unlock(&philo->left_fork->mutex);
// 	pthread_mutex_unlock(&philo->right_fork->mutex);
// }
