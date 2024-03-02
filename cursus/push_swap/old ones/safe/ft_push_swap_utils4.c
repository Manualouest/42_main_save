/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:30:38 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/18 19:11:59 by mbirou           ###   ########.fr       */
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
