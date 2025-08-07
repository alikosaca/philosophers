/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:43:51 by akosaca           #+#    #+#             */
/*   Updated: 2025/08/07 17:47:25 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}

	return (res * sign);
}

int	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
void	ft_usleep(long long time_in_ms, t_simulation *sim)
{
	long long	start;

	start = get_current_time();
	while ((get_current_time() - start) < time_in_ms && !check_simulation_end(sim))
		usleep(50);
}

// int	
// void take_forks(t_philosopher *p)
// {
// 	//! Yazılacak.
// }
// void	check_any_dead(t_simulation *sim)
// {
// }