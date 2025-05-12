/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:26:19 by akosaca           #+#    #+#             */
/*   Updated: 2025/05/12 15:20:42 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	return_err(char *message)
{
	printf("%s\n", message);
	return (1);
}
// int	free_and_error(char *str, t_simulation *simulation)
// {
// 	//! Yazılacak...
// 	return (1);
// }