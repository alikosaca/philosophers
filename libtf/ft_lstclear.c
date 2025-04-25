/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:47:56 by akosaca           #+#    #+#             */
/*   Updated: 2024/11/05 19:12:09 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	if (*lst || del)
	{
		node = *lst;
		while (node)
		{
			tmp = node->next;
			del(node->content);
			free(node);
			node = tmp;
		}
		*lst = NULL;
	}
}
