/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:24:33 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/12 15:43:23 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//? All error message will change
int	validate_argument(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return(return_err("İnvalid Argument digit"));
	if (ft_atoi(argv[1]) <= 0)
		return(return_err("The number of Philosophers must be positive"));
	if (ft_atoi(argv[2]) <= 0)
		return (return_err("The number of Die must be positive"));
	if (ft_atoi(argv[3]) <= 0)
		return (return_err("The number of Eat must be positive"));
	if (ft_atoi(argv[4]) <= 0)
		return (return_err("The number of Sleep must be positive"));
	if (ft_atoi(argv[1]) > 200)
		printf("Too many philosophers can consume system resources");
	if (argc == 6)
		if (ft_atoi(argv[5]) <= 0)
			return (return_err("Limited Number must be positive"));
	return (0);
}
