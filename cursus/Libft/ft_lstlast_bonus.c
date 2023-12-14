/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:31:41 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/07 12:57:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (lst == NULL)
		return (NULL);
	curr = lst;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	return (curr);
}
