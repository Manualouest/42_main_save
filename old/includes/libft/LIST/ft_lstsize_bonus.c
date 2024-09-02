/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:18:45 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/12/14 01:34:10 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIBFT/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*actual_node;

	actual_node = lst;
	if (!actual_node)
		return (0);
	i = 1;
	while (actual_node->next)
	{
		i++;
		actual_node = actual_node->next;
	}
	return (i);
}
