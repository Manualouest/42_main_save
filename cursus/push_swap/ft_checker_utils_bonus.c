/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:00:31 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/25 19:01:09 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	pos;

	pos = -1;
	if (n < 1)
		return (0);
	while (++pos < n && (unsigned char)s1[pos] != 0
		&& (unsigned char)s2[pos] != 0)
		if ((unsigned char)s1[pos] != (unsigned char)s2[pos])
			return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}

int	f_rr(t_stack **a, t_stack **b)
{
	int	tp;

	tp = fr(a, NULL);
	tp += fr(b, NULL);
	if (tp == 2)
		return (1);
	return (0);
}

int	f_rrr(t_stack **a, t_stack **b)
{
	int	tp;

	tp = frr(a, NULL);
	tp += frr(b, NULL);
	if (tp == 2)
		return (1);
	return (0);
}

int	f_ss(t_stack **a, t_stack **b)
{
	int	tp;

	tp = sa(a, 0);
	tp += sb(b, 0);
	if (tp == 2)
		return (1);
	return (0);
}
