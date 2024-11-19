/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:43:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first_lst;
	void	*content_tmp;

	if (!lst || !del || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content_tmp = f(lst->content);
		first_lst = ft_lstnew(content_tmp);
		if (!first_lst)
		{
			del(content_tmp);
			ft_lstclear(&first_lst, del);
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, first_lst);
		lst = lst->next;
	}
	return (new_lst);
}
