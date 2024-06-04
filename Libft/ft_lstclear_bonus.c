/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:35:42 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/07 12:58:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*curr;

	if (lst == NULL || !del)
		return ;
	curr = *lst;
	while (curr->next != NULL)
	{
		temp = curr->next;
		ft_lstdelone(curr, del);
		curr = temp;
	}
	ft_lstdelone(curr, del);
	*lst = NULL;
}
