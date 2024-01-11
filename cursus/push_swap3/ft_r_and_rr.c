/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_and_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:16:24 by mbirou            #+#    #+#             */
/*   Updated: 2023/12/12 20:29:19 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ra(t_stack **stk)
{
	t_stack	*temp;

	if (*stk && (*stk)->next)
	{
		temp = *stk;
		while (temp->next)
			temp = temp->next;
		temp->next = *stk;
		*stk = (*stk)->next;
		temp->next->next = NULL;
		write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}

int	rb(t_stack **stk)
{
	t_stack	*temp;

	if (*stk && (*stk)->next)
	{
		temp = *stk;
		while (temp->next)
			temp = temp->next;
		temp->next = *stk;
		*stk = (*stk)->next;
		temp->next->next = NULL;
		write(1, "rb\n", 3);
		return (1);
	}
	return (0);
}

int	rra(t_stack **stk)
{
	t_stack	*temp;

	if (*stk && (*stk)->next)
	{
		temp = *stk;
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *stk;
		*stk = temp->next;
		temp->next = NULL;
		write(1, "rra\n", 4);
		return (1);
	}
	return (0);
}

int	rrb(t_stack **stk)
{
	t_stack	*temp;

	if (*stk && (*stk)->next)
	{
		temp = *stk;
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *stk;
		*stk = temp->next;
		temp->next = NULL;
		write(1, "rra\n", 4);
		return (1);
	}
	return (0);
}
