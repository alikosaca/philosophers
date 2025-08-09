/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:06:28 by akosaca           #+#    #+#             */
/*   Updated: 2025/08/08 15:41:40 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_enough(t_philosopher *philo)
{
	int	eat_count;

	pthread_mutex_lock(philo->simulation->dead_lock);
	eat_count = philo->eat_count;
	pthread_mutex_unlock(philo->simulation->dead_lock);
	printf("philo[%d] yemek sayısı[%d] \n", philo->id, eat_count);
	if (eat_count >= philo->simulation->number_of_meals)
		return (1);
	return (0);
}

int	check_simulation_end(t_simulation *sim)
{
	if (!sim || !sim->dead_lock)
        return (1);
	pthread_mutex_lock(sim->dead_lock);
	if (sim->is_dead)
	{
		pthread_mutex_unlock(sim->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(sim->dead_lock);
	return (0);
}

static int	is_dead(t_simulation *sim)
{
	int			i;
	long long	time;
	long long	dead_time;
	long long	last_meal_time;

	i = -1;
	while (++i < sim->num_philo)
	{
		time = get_current_time();
		pthread_mutex_lock(sim->dead_lock);
		last_meal_time = sim->philo[i].last_meal_time;
		pthread_mutex_unlock(sim->dead_lock);
		if (time - last_meal_time > sim->time_to_die
			&& (sim->philo[i].eat_count >= sim->number_of_meals))
		{
			pthread_mutex_lock(sim->dead_lock);
			sim->is_dead = true;
			pthread_mutex_unlock(sim->dead_lock);
			dead_time = time - sim->start_time;
			pthread_mutex_lock(sim->write_mutex);
			printf("%lld | %d > died\n", dead_time, sim->philo[i].id);
			pthread_mutex_unlock(sim->write_mutex);
			return (1);
		}
	}
	return (0);
}
static bool	is_ate(t_simulation *sim)
{
	int			i;
	long long	finish_time;
	bool		every_philo_ate;
	int tmp1;
	int tmp2;

	i = -1;
	every_philo_ate = true;
	if (sim->number_of_meals > 0)
	{
		while (++i < sim->num_philo)
		{
			pthread_mutex_lock(sim->dead_lock);
			if (sim->philo[i].eat_count >= sim->number_of_meals)
			{
				tmp1 = sim->philo[i].eat_count;
				tmp2 = sim->number_of_meals;
				every_philo_ate = false;
				
			}
			pthread_mutex_unlock(sim->dead_lock);
		}	
		if (every_philo_ate)
		{
			finish_time = get_current_time() - sim->start_time;
			printf("\n");
			printf("\n");
			printf("every_philo_ate: %d\n", every_philo_ate);
			printf("%lld > timestamp\n", finish_time);
			printf("\n");
			printf("sim->philo[i].eat_count: %d\n", tmp1);
			printf("sim->number_of_meals: %d\n", tmp2);
			printf("\n");
			printf("\n");
			printf("\n");
		}
	}
	else
		return (false);
	return (every_philo_ate);
}

void	*monitor_routine(void *arg)
{
	t_simulation	*sim;

	sim = (t_simulation *)arg;
	while (!is_dead(sim) && !is_ate(sim))
		usleep(1000);
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_mutex_lock(philo->simulation->dead_lock);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(philo->simulation->dead_lock);
	if (philo->id % 2 == 0)
		ft_usleep(philo->simulation->time_to_eat / 2, philo->simulation);
	
	while (!check_simulation_end(philo->simulation))
	{
		if (philo->simulation->number_of_meals > 0 && is_enough(philo))
		{
			printf("philo bitti id[%d] \n", philo->id);
			return (NULL);
		}
		eat(philo);
		dream(philo);
		think(philo);
	}

	return (NULL);
}

int	run_simulation(t_simulation *sim)
{
	pthread_t	monitor;
	int			i;

	printf("--------run simulation----------\n");
	i = -1;
	sim->start_time = get_current_time();
	while (++i < sim->num_philo)
	{
		if (pthread_create(&sim->philo[i].thread, NULL, philo_routine, &sim->philo[i]))
			return (1);
	}
	if (pthread_create(&monitor, NULL, monitor_routine, sim))
		return (1);

	i = -1;
	while (++i < sim->num_philo)
	{
		if (pthread_join(sim->philo[i].thread, NULL))
			return (1);
	}
	if (pthread_join(monitor, NULL))
		return (1);
	fprintf(stderr, "[DBG] run_simulation completed\n");
	return (0);
}


