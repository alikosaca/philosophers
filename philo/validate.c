/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:24:33 by akosaca           #+#    #+#             */
/*   Updated: 2025/08/20 16:10:16 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argc > j)
	{
		while (argv[j][i])
		{
			if (!ft_strchr("+-", argv[j][i]) || !ft_isdigit(argv[j][i]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
int	validate_argument(int argc, char **argv)
{

	if (argc < 5 || argc > 6)
		return (return_err("Invalid argument digit"));
	if (ft_atoi(argv[1]) <= 0)
		return (return_err("The number of philosophers must be positive"));
	if (ft_atoi(argv[2]) <= 0)
		return (return_err("The number of die must be positive"));
	if (ft_atoi(argv[3]) <= 0)
		return (return_err("The number of eat must be positive"));
	if (ft_atoi(argv[4]) <= 0)
		return (return_err("The number of sleep must be positive"));
	if (ft_atoi(argv[1]) > 200)
		printf("Too many philosophers can consume system resources");
	if (argc == 6)
		if (ft_atoi(argv[5]) <= 0)
			return (return_err("Limited number must be positive"));
	if (check_arg(argc, argv))
		return (return_err("Invalid argument"));
	return (0);
}
