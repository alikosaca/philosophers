/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:16:14 by akosaca           #+#    #+#             */
/*   Updated: 2024/11/05 19:00:11 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*new_node;
	void	*tmp;

	list = NULL;
	while (lst)
	{
		tmp = (*f)(lst->content);
		new_node = ft_lstnew(tmp);
		if (!new_node)
		{
			ft_lstclear(&list, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&list, new_node);
		lst = lst->next;
	}
	return (list);
}
