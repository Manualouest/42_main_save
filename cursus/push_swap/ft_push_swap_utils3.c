/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:14:55 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/25 18:48:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_min(t_stack *stk)
{
	int	min;

	min = 0;
	if (stk)
		min = stk->content;
	while (stk && stk->next)
	{
		if (stk->content < min)
			min = stk->content;
		stk = stk->next;
	}
	if (stk && stk->content < min)
		min = stk->content;
	return (min);
}

int	ft_get_max(t_stack *stk)
{
	int	max;

	max = 0;
	if (stk)
		max = stk->content;
	while (stk && stk->next)
	{
		if (stk->content > max)
			max = stk->content;
		stk = stk->next;
	}
	if (stk && stk->content > max)
		max = stk->content;
	return (max);
}

int	fr(t_stack **stk, int *place)
{
	t_stack	*temp;

	if (stk && *stk && (*stk)->next)
	{
		temp = *stk;
		while (temp->next)
			temp = temp->next;
		temp->next = *stk;
		*stk = (*stk)->next;
		temp->next->next = NULL;
		if (place && *place && *place != -1)
			*place = *place - 1;
		return (1);
	}
	return (0);
}

int	frr(t_stack **stk, int *place)
{
	t_stack	*temp;

	if (stk && *stk && (*stk)->next)
	{
		temp = *stk;
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *stk;
		*stk = temp->next;
		temp->next = NULL;
		if (place && *place != -1)
			*place = *place + 1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (!nptr || !*nptr)
		return (0);
	if ((nptr[0] == '-' || nptr[0] == '+') && ++i != -1)
		if (nptr[0] == '-')
			sign = -1;
	if (i > 0 && (nptr[0] != '-' && nptr[0] != '+'))
		i = 0;
	while (nptr[i] != 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (num >= 2147483647)
			return (0);
		num = num * 10 + (nptr[i] - '0');
		i ++;
	}
	if (((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
		|| (nptr[i] != 0 && !(nptr[i] >= '0' && nptr[i] <= '9')))
		return (0);
	return ((int)num * sign);
}
