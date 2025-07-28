/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:07:37 by akosaca           #+#    #+#             */
/*   Updated: 2025/07/28 14:03:52 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int argc, char **argv)
{
	t_simulation	sim;

	if (validate_argument(argc, argv))
		return (1);
	printf("validate -> is running\n");
	if (init_sim(argc, argv, &sim))
		cleanup(&sim);
	
	if (run_simulation(&sim))
		cleanup(&sim);
	printf("run_simulation -> is running\n");
	cleanup(&sim);

	return (0);
}
