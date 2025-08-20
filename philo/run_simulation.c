/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:06:28 by akosaca           #+#    #+#             */
/*   Updated: 2025/08/20 15:40:40 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	//long long	fp;

	i = -1;
	while (++i < sim->num_philo)
	{
		time = get_current_time();
		pthread_mutex_lock(sim->dead_lock);
		last_meal_time = sim->philo[i].last_meal_time;
		pthread_mutex_unlock(sim->dead_lock);
		//printf("time: %lld\n", (time - last_meal_time));
		//printf("end: %lld\n", sim->time_to_die);
		if ((time - last_meal_time) > sim->time_to_die)
		{
			printf("---------------------------\n");
			printf("time: %lld\n", (time - last_meal_time));
			printf("end: %lld\n", sim->time_to_die);
			printf("---------------------------\n");
			pthread_mutex_lock(sim->dead_lock);
			sim->is_dead = true;
			pthread_mutex_unlock(sim->dead_lock);
			dead_time = time - sim->start_time;
			pthread_mutex_lock(sim->write_mutex);
			printf("%lld %d > died\n", dead_time, sim->philo[i].id);
			pthread_mutex_unlock(sim->write_mutex);
			return (1);
		}
	}
	return (0);
}

static bool	is_ate(t_simulation *sim)
{
	int			i;
	bool		all_ate;

	if (sim->number_of_meals <= 0)
		return (false);
	i = -1;
	all_ate = true;
	while (++i < sim->num_philo)
	{
		pthread_mutex_lock(sim->dead_lock);
		if (sim->philo[i].eat_count < sim->number_of_meals)
			all_ate = false;
		pthread_mutex_unlock(sim->dead_lock);
		if (!all_ate)
			break ;
	}	
	if (all_ate)
	{
		pthread_mutex_lock(sim->dead_lock);
		sim->is_dead = true;
		pthread_mutex_unlock(sim->dead_lock);
	}
	return (all_ate);
}

void	*monitor_routine(void *arg)
{
	t_simulation	*sim;

	sim = (t_simulation *)arg;
	while (!is_dead(sim) && !is_ate(sim))
		usleep(200);
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_mutex_lock(philo->simulation->dead_lock);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(philo->simulation->dead_lock);
	is_one_philo(philo);
	if (philo->simulation->num_philo % 2 == 0 && philo->id % 2 == 0)
		ft_usleep(philo->simulation->time_to_eat / 2, philo->simulation);
	else if (philo->simulation->num_philo % 2 == 1 && philo->id % 2 == 0)
		ft_usleep(philo->simulation->time_to_eat, philo->simulation);
	while (!check_simulation_end(philo->simulation))
	{
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
    return (0);
}




// void	*philo_routine(void *arg)
// {
// 	t_philosopher	*philo;

// 	philo = (t_philosopher *)arg;
// 	pthread_mutex_lock(philo->simulation->dead_lock);
// 	philo->last_meal_time = get_current_time();
// 	pthread_mutex_unlock(philo->simulation->dead_lock);
// 	is_one_philo(philo);
// 	if (philo->id % 2 == 0)
// 		ft_usleep(philo->simulation->time_to_eat / 2, philo->simulation);
// 	while (!check_simulation_end(philo->simulation))
// 	{
// 		//if (philo->simulation->number_of_meals > 0) //is_enough(philo)
// 		//	return (NULL);
// 		eat(philo);
// 		dream(philo);
// 		think(philo);
// 	}

// 	return (NULL);
// }