/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:53:30 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/12/14 01:34:04 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIBFT/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*clone_node;
	t_list	*prev_node;

	if (!lst || !f || !del)
		return (0);
	first_node = ft_lstnew(f(lst->content));
	if (!first_node)
		return (0);
	prev_node = first_node;
	while (lst->next)
	{
		lst = lst->next;
		clone_node = ft_lstnew(f(lst->content));
		if (!clone_node)
		{
			ft_lstclear(&first_node, del);
			return (0);
		}
		prev_node->next = clone_node;
		prev_node = prev_node->next;
	}
	return (first_node);
}
