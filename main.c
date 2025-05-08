/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:07:37 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/08 16:56:33 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int argc, char **argv)
{
	t_simulation	simulation;

	if (validate_argument(argc, argv, &simulation))
		return (1);
	if (init_sim(argc, argv, &simulation))
		return (1);

	
	return 0;
}
