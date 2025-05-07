/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:07:37 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/06 19:04:41 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	parse_argument(int argc, char **argv, t_simulation *simulation)
{
	if (argc < 5 || argc > 6)
	{
		ft_printf("Argüman sayısı Hatalı!");
	}
	simulation->number_of_meals = ft_atoi(argv[1]); //Filozof sayısı
	simulation->time_to_die = ft_atoi(argv[2]);		//Bir filozofun son yediği yemekten itibaren bu süre içinde yemek yememesi durumunda öleceği süre
	simulation->time_to_eat = ft_atoi(argv[3]);		//Bir filozofun yemek yediği süre 
	simulation->time_to_sleep = ft_atoi(argv[4]);	//Bir filozofun uyuduğu süre

	if (argc == 6)
		simulation->number_of_meals = ft_atoi(argv[5]); //Her filozofun en az bu kadar kez yemek yemesi gerekir "isteğe bağlı".
	else
		simulation->number_of_meals = -1;

	simulation->simulation_end = false;
	simulation->start_time = 0;
	simulation->philosophers = NULL;
	simulation->forks = NULL;

	return (validate_argument(simulation));
}

int	validate_argument(t_simulation *simulation)
{
	if (simulation->number_of_philosophers <= 0)
		return(error_message("Philosophers"));
	if (simulation->time_to_die <= 0)
		return (err_message("Die"));
	if (simulation->time_to_eat <= 0)
		return (err_message("Eat"));
	if (simulation->time_to_sleep <= 0)
		return (err_message("Sleep"));
	if (simulation->number_of_meals <= 0)
		return (err_message("Meal"));
	if (simulation->number_of_philosophers > 200)
		printf("Too many philosophers can consume system resources");
	return (0);
}

int main(int argc, char const *argv[])
{
	t_simulation simulation;

	if (!parse_argument(argc, **argv, &simulation))
		return (1);

	printf("%d", printf("merhaba"));
	
	return 0;
}
