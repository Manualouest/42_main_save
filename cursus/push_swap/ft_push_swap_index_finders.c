/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_index_finders.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:09:58 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/24 18:55:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_replace_stk(t_stack **stk, int index)
{
	int	tpint;

	if (index > 0)
		while (index > 0)
			fr(stk, &index);
	else
	{
		index = index * -1;
		tpint = 0;
		while (tpint < index)
			frr(stk, &tpint);
	}
}

int	ft_get_index_b(t_stack **a, t_stack **b)
{
	int	index;
	int	rr_bool;

	index = -1;
	rr_bool = -1;
	while (a && b && ++index < ft_lstsize(*b)
		&& !((*a)->content > ft_get_max(*b) && ft_find_index_max(*b) == 0)
		&& !((*a)->content < ft_get_min(*b) && ft_find_index_max(*b) == 0)
		&& ((*a)->content < (*b)->content
			|| (*a)->content > ft_lstlast(*b)->content))
	{
		if (rr_bool == 1 || ((*a)->content > (*b)->content
				&& ft_find_index_min(*b) > ft_lstsize(*b) / 2))
		{
			frr(b, NULL);
			rr_bool = 1;
		}
		else
			fr(b, NULL);
	}
	ft_replace_stk(b, index * rr_bool);
	if (rr_bool == 1)
		index = ft_lstsize(*b) - index;
	return (index);
}

int	ft_move_stk(t_stack **a, t_stack **b, int index, int *indexb_help)
{
	int	tpint;

	if (a && index > 0)
	{
		tpint = index;
		while (tpint > 0)
			fr(a, &tpint);
	}
	else if (a)
	{
		index = index * -1;
		tpint = 0;
		while (tpint < index * 2)
			frr(a, &tpint);
	}
	tpint = ft_get_index_b(a, b);
	*indexb_help = tpint;
	if (tpint > ft_lstsize(*b) / 2)
		tpint = ft_lstsize(*b) - tpint;
	return (tpint);
}

void	ft_set_values(t_indexa_vals *vals, int tpint, int *indb, int bst_index)
{
	(*vals).min_move = (*vals).index + tpint;
	(*vals).best_index = bst_index;
	*indb = (*vals).indexb_help;
}

int	ft_get_index_a(t_stack **a, t_stack **b, int *indexb)
{
	t_indexa_vals	vals;
	int				tpint;

	vals.index = -1;
	vals.min_move = -1;
	vals.indexb_help = 0;
	while (++vals.index < (ft_lstsize(*a) / 2) + 1
		&& vals.index < (ft_lstsize(*b) / 2) + 1)
	{
		tpint = ft_move_stk(a, b, vals.index, &vals.indexb_help);
		if (vals.min_move == -1 || vals.index + tpint < vals.min_move)
			ft_set_values(&vals, tpint, indexb, vals.index);
		tpint = ft_move_stk(a, b, (vals.index * -1), &vals.indexb_help);
		if (vals.index + tpint < vals.min_move)
			ft_set_values(&vals, tpint, indexb, ft_lstsize(*a) - vals.index);
		ft_replace_stk(a, vals.index);
	}
	return (vals.best_index);
}
