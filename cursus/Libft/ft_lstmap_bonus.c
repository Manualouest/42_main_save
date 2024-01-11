/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:56:45 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/07 17:41:01 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*prev;
	t_list	*dup;

	if (!lst || !f || !del)
		return (NULL);
	dup = ft_lstnew(f(lst->content));
	if (!dup)
		return (NULL);
	prev = dup;
	first = dup;
	while (lst->next)
	{
		lst = lst->next;
		dup = ft_lstnew(f(lst->content));
		if (!dup)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		prev->next = dup;
		prev = dup;
	}
	dup->next = NULL;
	return (first);
}
