/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_algo_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:34:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/18 19:14:39 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_do_move(t_stack **a, t_stack **b, int indexa, int indexb)
{
	ft_do_rrr(a, b, &indexa, &indexb);
	while (indexa > 0 && indexa < ft_lstsize(*a))
	{
		if (ft_lstsize(*a) - indexa < ((ft_lstsize(*a)) / 2) + 1)
			rra(a, &indexa);
		else
			ra(a, &indexa);
	}
	while (indexb > 0 && indexb < ft_lstsize(*b))
	{
		if (ft_lstsize(*b) - indexb < ((ft_lstsize(*b)) / 2) + 1)
			rrb(b, &indexb);
		else
			rb(b, &indexb);
	}
	pb(b, a);
}

int	ft_find_num(t_stack *stk, int num)
{
	int	index;

	index = 0;
	while (stk && stk->content != num && index < ft_lstsize(stk))
	{
		stk = stk->next;
		index ++;
	}
	return (index);
}

void	ft_sort_three(t_stack **a)
{
	int	min;
	int	max;

	min = ft_find_index_min(*a);
	max = ft_find_index_max(*a);
	if ((min == 0 && max == 1) || (min == 2 && max == 0))
		sa(a);
	else if ((min == 1 && max == 2) || (min == 1 && max == 2))
		sa(a);
}

int	ft_get_place(t_stack *stk, int num)
{
	int		i;

	i = 0;
	while (stk && !(stk->content > num
			&& ft_lstlast(stk)->content < num) && i < ft_lstsize(stk))
	{
		fr(&stk, NULL);
		i ++;
	}
	ft_replace_stk(&stk, -1 * i);
	return (i);
}

void	ft_empty_b(t_stack **a, t_stack **b)
{
	int	move_count;

	while (ft_lstsize(*b) != 0)
	{
		if ((*b)->content > ft_get_max(*a))
			move_count = ft_find_index_max(*a) + 1;
		else if ((*b)->content < ft_get_min(*a))
			move_count = ft_find_index_min(*a);
		else
			move_count = ft_get_place(*a, (*b)->content);
		while (a && *a && (move_count > 0 && move_count < ft_lstsize(*a)))
		{
			if (ft_lstsize(*a) - move_count < (ft_lstsize(*a) + 1) / 2)
				rra(a, &move_count);
			else
				ra(a, &move_count);
		}
		pa(a, b);
	}
}
