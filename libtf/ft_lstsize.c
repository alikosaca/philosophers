/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:05:17 by akosaca           #+#    #+#             */
/*   Updated: 2024/11/05 19:12:39 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		result;
	t_list	*node;

	if (lst)
	{
		result = 1;
		node = lst;
		while (node->next != NULL)
		{
			node = node->next;
			result++;
		}
		return (result);
	}
	return (0);
}
