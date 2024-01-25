/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:14:06 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/25 19:00:24 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_make_a(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	argv = ft_stk_mk_util(argv, &argc);
	if (!argv || !ft_has_no_double(argv, argc)
		|| ft_stack_maker(argv, &a, argc) == 0)
	{
		ft_mega_clearer(a, NULL, argv);
		write(2, "Error\n", 6);
		return (NULL);
	}
	ft_mega_clearer(NULL, NULL, argv);
	return (a);
}

char	**ft_get_movelist(int argc)
{
	char	*tp;
	char	*tp_moves;
	char	**moves;
	int		i;
	int		ii;

	tp = get_next_line(0);
	tp_moves = NULL;
	i = -1;
	while (tp != NULL)
	{
		tp_moves = ft_strlcat(tp_moves, tp, 1);
		free(tp);
		tp = get_next_line(0);
	}
	free(tp);
	moves = ft_split(tp_moves, (char)*"\n", &argc);
	free(tp_moves);
	while (moves && moves[++i] != 0)
	{
		ii = -1;
		while (moves[i][++ii] != 0)
			moves[i][ii] = moves[i][ii + 1];
	}
	return (moves);
}

int	ft_do_moves(t_stack **a, t_stack **b, char *move)
{
	if (ft_strncmp("rr", move, ft_strlen(move)) == 0)
		return (f_rr(a, b));
	if (ft_strncmp("rrr", move, ft_strlen(move)) == 0)
		return (f_rrr(a, b));
	if (ft_strncmp("ss", move, ft_strlen(move)) == 0)
		return (f_ss(a, b));
	if (ft_strncmp("ra", move, ft_strlen(move)) == 0)
		return (fr(a, NULL));
	if (ft_strncmp("rb", move, ft_strlen(move)) == 0)
		return (fr(b, NULL));
	if (ft_strncmp("rra", move, ft_strlen(move)) == 0)
		return (frr(a, NULL));
	if (ft_strncmp("rrb", move, ft_strlen(move)) == 0)
		return (frr(b, NULL));
	if (ft_strncmp("pa", move, ft_strlen(move)) == 0)
		return (fp(a, b));
	if (ft_strncmp("pb", move, ft_strlen(move)) == 0)
		return (fp(b, a));
	if (ft_strncmp("sa", move, ft_strlen(move)) == 0)
		return (sa(a, 0));
	if (ft_strncmp("sb", move, ft_strlen(move)) == 0)
		return (sb(b, 0));
	return (0);
}

int	ft_error(t_stack *a, t_stack *b, char **moves)
{
	ft_mega_clearer(a, b, moves);
	write(2, "ERROR\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**moves;
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = -1;
	b = NULL;
	if (argc == 1)
		return (ft_error(NULL, NULL, NULL));
	a = ft_make_a(argc, argv);
	if (a == NULL)
		return (ft_error(a, NULL, NULL));
	moves = ft_get_movelist(argc);
	if (moves == NULL)
		return (ft_error(a, NULL, moves));
	while (moves[++i] != 0)
		if (ft_do_moves(&a, &b, moves[i]) == 0)
			return (ft_error(a, b, moves));
	if (!ft_is_sorted(a) || ft_lstsize(b) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_mega_clearer(a, b, moves);
	return (0);
}
