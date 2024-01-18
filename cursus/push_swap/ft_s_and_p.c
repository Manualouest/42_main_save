/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_and_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:14:59 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/18 19:11:55 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	sa(t_stack **stk)
{
	t_stack	*temp;

	if (*stk && (*stk)->next != NULL)
	{
		temp = *stk;
		*stk = (*stk)->next;
		temp->next = (*stk)->next;
		(*stk)->next = temp;
		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}

int	sb(t_stack **stk)
{
	t_stack	*temp;

	if (*stk && (*stk)->next != NULL)
	{
		temp = *stk;
		*stk = (*stk)->next;
		temp->next = (*stk)->next;
		(*stk)->next = temp;
		write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}

int	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!b || !*b)
		return (0);
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		temp = (*b)->next;
		ft_lstadd_front(a, *b);
		*b = temp;
	}
	if (*a == NULL)
	{
		free(a);
		return (0);
	}
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!b || !*b)
		return (0);
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		temp = (*b)->next;
		ft_lstadd_front(a, *b);
		*b = temp;
	}
	if (*a == NULL)
	{
		free(a);
		return (0);
	}
	write(1, "pb\n", 3);
	return (1);
}

int	fp(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!b || !*b)
		return (0);
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		temp = (*b)->next;
		ft_lstadd_front(a, *b);
		*b = temp;
	}
	if (*a == NULL)
	{
		free(a);
		return (0);
	}
	return (1);
}
