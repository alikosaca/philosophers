/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:24:33 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/08 19:56:53 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//? All error message will change
int	validate_argument(char argc, char **argv, t_simulation *simulation)
{
	if (argc < 5 || argc > 6)
		return(err_message("İnvalid Argument digit"));
	if (ft_atoi(argv[1]) <= 0)
		return(err_message("The number of Philosophers must be positive"));
	if (ft_atoi(argv[2]) <= 0)
		return (err_message("The number of Die must be positive"));
	if (ft_atoi(argv[3]) <= 0)
		return (err_message("The number of Eat must be positive"));
	if (ft_atoi(argv[4]) <= 0)
		return (err_message("The number of Sleep must be positive"));
	if (ft_atoi(argv[1]) > 200)
		printf("Too many philosophers can consume system resources");
	if (argc == 6)
		if (ft_atoi(argv[5]) <= 0)
			return (err_message("Limited Number must be positive"));
	return (0);
}