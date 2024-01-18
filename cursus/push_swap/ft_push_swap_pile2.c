/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_pile2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:01:55 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/18 19:12:07 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (*lst == 0)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*curr;

	if (new == NULL)
		return ;
	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new;
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*curr;

	if (*lst == NULL)
		return ;
	curr = *lst;
	while (curr->next != NULL)
	{
		temp = curr->next;
		if (curr)
			free (curr);
		curr = temp;
	}
	if (curr)
		free (curr);
	*lst = NULL;
}
