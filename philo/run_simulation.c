/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:06:28 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/13 21:06:22 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//t_philosopher	*philo;
//philo = sim->philo;

	//*yemek yemeye gitti ise hemen sonra uykuya gitsin
	//çift id sağ, sol
	//tek id sol, sağ, usleep(100)
	//unlock, tam tersi

#include "philo.h"

void	*monitor_routine(void *arg)
{
	(void) arg;
	return (NULL);
}

void	*philo_routine(void *arg)
{
	(void) arg;
	t_simulation	*sim;

	sim = (t_simulation *)arg;

	if (sim->philo->id % 2 == 0) // Çift numaralı filozoflar için kısa gecikme
		ft_usleep(100);
	// Loop until the philosopher dies or has enough food
	while (1)
	{
		// Ölüm kontrolü
        
        // Sol çatalı al
        
        // Durum mesajı (fork taken)
        
        // Sağ çatalı al
        
        // Durum mesajı (fork taken)
        
        // Yemek ye
        
        // Son yemek zamanını güncelle
        
        // Yemek sayısını artır
        
        // Çatalları bırak
        
        // Uyu
        
        // Düşün
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
		if (pthread_create(&sim->philo[i].thread, NULL, philo_routine, sim))
			return (1);
	}
	if (pthread_create(&monitor, NULL, monitor_routine, sim))
		return (1);
	if (pthread_join(monitor, NULL))
		return (1);
	i = -1;
	while (++i < sim->num_philo)
	{
		if (pthread_join(sim->philo[i].thread, NULL))
			return (1);
	}
	return (0);
}
