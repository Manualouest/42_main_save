/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:56:39 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/25 17:21:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		argv = ft_stk_mk_util(argv, &argc);
		if (!argv || !ft_has_no_double(argv, argc)
			|| ft_stack_maker(argv, &a, argc) == 0)
		{
			ft_mega_clearer(a, NULL, argv);
			write(2, "Error\n", 6);
			exit (0);
		}
		if (!ft_is_sorted(a))
			ft_algo(&a, &b);
		ft_mega_clearer(a, b, argv);
	}
	exit (0);
}

void	ft_algo(t_stack **a, t_stack **b)
{
	int	indexb;
	int	indexa;

	indexb = 0;
	if (ft_lstsize(*a) > 3)
	{
		pb(b, a);
		if (ft_lstsize(*a) > 3)
			pb(b, a);
	}
	while (ft_lstsize(*a) > 3 && !ft_is_sorted(*a))
	{
		indexa = ft_get_index_a(a, b, &indexb);
		ft_do_move(a, b, indexa, indexb);
	}
	ft_sort_three(a);
	ft_empty_b(a, b);
	while (ft_find_index_min(*a) != 0
		&& ft_find_index_min(*a) != ft_lstsize(*a))
	{
		if (ft_lstsize(*a) - ft_find_index_min(*a) < (ft_lstsize(*a)) / 2)
			rra(a, NULL);
		else
			ra(a, NULL);
	}
}
