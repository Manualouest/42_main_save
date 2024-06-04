/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:30:38 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/24 20:08:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_find_index_min(t_stack *stk)
{
	int	index;
	int	curr_min;
	int	i;

	if (stk)
	{
		curr_min = stk->content;
		index = 0;
		i = 0;
		while (stk && stk->next != NULL)
		{
			if (stk->content < curr_min)
			{
				index = i;
				curr_min = stk->content;
			}
			i ++;
			stk = stk->next;
		}
		if (stk->content < curr_min)
			index = i;
		return (index);
	}
	return (-1);
}

int	ft_find_index_max(t_stack *stk)
{
	int	index;
	int	curr_min;
	int	i;

	if (stk)
	{
		curr_min = stk->content;
		index = 0;
		i = 0;
		while (stk && stk->next != NULL)
		{
			if (stk->content > curr_min)
			{
				index = i;
				curr_min = stk->content;
			}
			i ++;
			stk = stk->next;
		}
		if (stk->content > curr_min)
			index = i;
		return (index);
	}
	return (-1);
}

void	ft_mega_clearer(t_stack *a, t_stack *b, char **argv)
{
	int	i;

	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i ++;
		}
		free(argv);
	}
}

void	ft_do_rrr(t_stack **a, t_stack **b, int *indexa, int *indexb)
{
	while (a && b && *indexa > 0
		&& *indexa < ft_lstsize(*a)
		&& *indexb > 0 && *indexb < ft_lstsize(*b)
		&& ((ft_lstsize(*a) - *indexa < ((ft_lstsize(*a)) / 2) + 1
				&& ft_lstsize(*b) - *indexb < ((ft_lstsize(*b)) / 2) + 1)
			|| (ft_lstsize(*a) - *indexa > ((ft_lstsize(*a)) / 2)
				&& ft_lstsize(*b) - *indexb > ((ft_lstsize(*b)) / 2))))
	{
		if (ft_lstsize(*a) - *indexa < ((ft_lstsize(*a)) / 2) + 1
			&& ft_lstsize(*b) - *indexb < ((ft_lstsize(*b)) / 2) + 1)
		{
			frr(a, indexa);
			frr(b, indexb);
			write(1, "rrr\n", 4);
		}
		else if (ft_lstsize(*a) - *indexa > ((ft_lstsize(*a)) / 2)
			&& ft_lstsize(*b) - *indexb > ((ft_lstsize(*b)) / 2))
		{
			fr(a, indexa);
			fr(b, indexb);
			write(1, "rr\n", 3);
		}
	}
}
