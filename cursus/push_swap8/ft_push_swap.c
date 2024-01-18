/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:56:39 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/08 17:30:11 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

#include <stdio.h>
// void	debug_printer(t_stack *stk);

static int	frr(t_stack **stk, t_stack **stk2,  int *place, int *placeb);
static int	fr(t_stack **stk, t_stack **stk2,  int *place, int *placeb);


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		argv = stack_maker_utils(argv, &argc);
		if (!argv || !ft_has_no_double(argv, argc)
			|| stack_maker(argv, &a, argc) == 0)
		{
			ft_mega_clearer(a, NULL, argv);
			write(2, "Error\n", 6);
			exit (0);
		}
		// debug_printer(a, b);
		// write(1, "\nbefore\n\n", 9);
		
		// debug_printer(a, b);
		// ra(&a, NULL);
		// debug_printer(a, b);
		// rra(&a, NULL);
		// debug_printer(a, b);

		if (!is_sorted(a))
			algo(&a, &b);

		// debug_printer(a, b);
		// write(1, "\nafter\n", 8);
		ft_mega_clearer(a, b, argv);
	}
	exit (0);
}

// write(1, "\na: ", 4);
// debug_printer(a);
// write(1, "\nb: \n", 5);
// debug_printer(b);
// write(1, "before\n", 7);

// write(1, "\na: ", 4);
// debug_printer(a);
// write(1, "\nb: ", 4);
// debug_printer(b);
// write(1, "\n", 1);

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

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;
	char			num;

	if (n < 0)
	{
		write(fd, "-", 1);
		temp = n * -1;
	}
	else
		temp = n;
	if (temp > 9)
	{
		ft_putnbr_fd(temp / 10, fd);
	}
	num = temp % 10 + '0';
	write(fd, &num, 1);
}

void	debug_printer(t_stack *stk, t_stack *stk2)
{
	write(1, "\na: ", 4);
	if (stk)
	{
		while (stk && stk->next)
		{
			ft_putnbr_fd(stk->content, 1);
			write(1, " ", 1);
			stk = stk->next;
		}
		if (stk)
			ft_putnbr_fd(stk->content, 1);
	}
	else
		write(1, "empty", 5);
	write(1, "\nb: ", 4);
	if (stk2)
	{
		while (stk2 && stk2->next)
		{
			ft_putnbr_fd(stk2->content, 1);
			write(1, " ", 1);
			stk2 = stk2->next;
		}
		if (stk2)
			ft_putnbr_fd(stk2->content, 1);
	}
	else
		write(1, "empty", 5);
	write(1, "\n", 1);
}


//######################################################################################




int		ft_get_place(t_stack *stk, int num);
int		ft_get_index_a(t_stack **sta, t_stack **stb, int *indexb);
int		ft_get_index_b(t_stack **sta, t_stack **stb);
int		ft_get_min(t_stack *stk);
int		ft_get_max(t_stack *stk);
void	ft_empty_b(t_stack **a, t_stack **b);
void	ft_sort_three(t_stack **a);
void	ft_do_move(t_stack **a, t_stack **b, int indexa, int indexb);

void	algo(t_stack **a, t_stack **b)
{
	// t_stack *a2;
	// t_stack *b2;
	int	indexb;
	int	indexa;

	indexb = 0;
	if (ft_lstsize(*a) > 3)
	{
		pb(b, a);
		if (ft_lstsize(*a) > 3)
			pb(b, a);
	}
	// ft_putnbr_fd(ft_get_index_a(&a2, &b2), 1);
	while (ft_lstsize(*a) > 3 && !is_sorted(*a))
	{
		// debug_printer(*a, *b);
		// a2 = duplicator(*a);
		// b2 = duplicator(*b);
		indexa = ft_get_index_a(a, b, &indexb);
		ft_do_move(a, b, indexa, indexb);
	}
	ft_sort_three(a);
	ft_empty_b(a, b);
	while (find_index_min(*a) != 0 && find_index_min(*a) != ft_lstsize(*a))
	{
		if (ft_lstsize(*a) - find_index_min(*a) < (ft_lstsize(*a)) / 2)
			rra(a, NULL);
		else
			ra(a, NULL);
	}
}

int	ft_get_index_b_special(t_stack **a, t_stack **b, int indexa)
{
	int	tpint;
	int	indexb;

	tpint = ft_lstsize(*a) - indexa;
	while (indexa > 0 && indexa < ft_lstsize(*a))
	{
		if (ft_lstsize(*a) - indexa < ((ft_lstsize(*a)) / 2) + 1)
			frr(a, NULL, &indexa, NULL);
		else
			fr(a, NULL, &indexa, NULL);
	}

	indexb = ft_get_index_b(a, b);

	while (tpint > 0 && tpint < ft_lstsize(*a))
	{
		if (ft_lstsize(*a) - tpint < ((ft_lstsize(*a)) / 2) + 1)
			frr(a, NULL, &tpint, NULL);
		else
			fr(a, NULL, &tpint, NULL);
	}
	return (indexb);
}

void	ft_do_move(t_stack **a, t_stack **b, int indexa, int indexb)
{
	// int		indexb;
	
	// t_stack *a2;
	// t_stack *b2;
	// write(1, "before move", 11);
	// ft_putnbr_fd(indexb, 1);
	// debug_printer(*a, *b);
	// indexb = ft_get_index_b_special(a, b, indexa); //&a2, &b2
	while (a && b && indexa > 0
			&& indexa < ft_lstsize(*a)
			&& indexb > 0 && indexb < ft_lstsize(*b)
			&& ((ft_lstsize(*a) - indexa < ((ft_lstsize(*a)) / 2) + 1
			&& ft_lstsize(*b) - indexb < ((ft_lstsize(*b)) / 2) + 1)
			|| (ft_lstsize(*a) - indexa > ((ft_lstsize(*a)) / 2)
			&& ft_lstsize(*b) - indexb > ((ft_lstsize(*b)) / 2))))
	{
		if (ft_lstsize(*a) - indexa < ((ft_lstsize(*a)) / 2) + 1
			&& ft_lstsize(*b) - indexb < ((ft_lstsize(*b)) / 2) + 1)
		{
			frr(a, NULL, &indexa, NULL);
			frr(b, NULL, &indexb, NULL);
			write(1, "rrr\n", 4);
		}
		else if (ft_lstsize(*a) - indexa > ((ft_lstsize(*a)) / 2)
			&& ft_lstsize(*b) - indexb > ((ft_lstsize(*b)) / 2))
		{
			fr(a, NULL, &indexa, NULL);
			fr(b, NULL, &indexb, NULL);
			write(1, "rr\n", 3);
		}
	}
	while (indexa > 0 && indexa < ft_lstsize(*a))
	{
		if (ft_lstsize(*a) - indexa < ((ft_lstsize(*a)) / 2) + 1)
			rra(a, &indexa);
		else
			ra(a, &indexa);
	}
	// a2 = duplicator(*a);
	// b2 = duplicator(*b);
	while (indexb > 0 && indexb < ft_lstsize(*b))
	{
		if (ft_lstsize(*b) - indexb < ((ft_lstsize(*b)) / 2) + 1)
			rrb(b, &indexb);
		else
			rb(b, &indexb);
	}
	pb(b, a);
	// ft_putnbr_fd(indexa, 1);
	// write(1, ",", 1);
	// ft_putnbr_fd(indexb, 1);
	// write(1, "after move", 10);
	// debug_printer(*a, *b);
}

void	replace_stk(t_stack **stk, int index)
{
	int	tpint;

	if (index > 0)
		while (index > 0)
			fr(stk, NULL, &index, NULL);
	else
	{
		index = index * -1;
		tpint = 0;
		while (tpint < index)
			frr(stk, NULL, &tpint, NULL);
	}
}

int	find_num(t_stack *stk, int num)
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

void	refresh_stacks(t_stack **a, t_stack **b, int num)
{
	// int	tpint;

	// write(1, "refresh", 7);
	// debug_printer(*a, *b);
	// tpint = ft_lstsize(*b);
	// ft_putnbr_fd(num, 1);
	// ft_putnbr_fd(find_num(*b, num), 1);
	while (find_num(*b, num) > 0 && find_num(*b, num) < ft_lstsize(*b))
		if (find_num(*b, num) > ft_lstsize(*b) / 2)
			frr(b, NULL, NULL, NULL);
		else
			fr(b, NULL, NULL, NULL); //frr(b, NULL, &tpint, NULL);
	// debug_printer(*a, *b);
	fp(a, b);
}

int	ft_index_found(t_stack **a, t_stack **b, int index, int way)
{
	int tpint;

	// write(1, "before", 6);
	// ft_putnbr_fd(way, 1);
	// ft_putnbr_fd(index, 1);
	// debug_printer(*a, *b);
	tpint = 0;
	if (way == 1)
	{
		tpint = index;
		while (tpint > 0)
			fr(b, NULL, &tpint, NULL);
	}
	else
		while (tpint < index)
			frr(b, NULL, &tpint, NULL);
	// debug_printer(*a, *b);
	if (((*a)->content > ft_get_max(*b) && find_index_max(*b) != 0)
		|| ((*a)->content < ft_get_min(*b) && find_index_max(*b) != 0)
		|| ((*a)->content < ft_get_max(*b) && (*a)->content > ft_get_min(*b) &&
			((*a)->content < (*b)->content || (*a)->content > ft_lstlast(*b)->content)))
	{
		// debug_printer(*a, *b);
		replace_stk(b, index * way * -1);
		return (0);
	}
	fp(b, a);
	tpint = (*b)->content;
	while (find_index_max(*b) != 0)
		if (find_index_max(*b) > ft_lstsize(*b) / 2)
			frr(b, NULL, NULL, NULL);
		else
			fr(b, NULL, NULL, NULL);
	// debug_printer(*a, *b);
	if (is_rsorted(*b))
	{
		refresh_stacks(a, b, tpint);
		replace_stk(b, index * way * -1);
		// write(1, "after replace", 13);
		// debug_printer(*a, *b);
		return (-1);
	}
	refresh_stacks(a, b, tpint);
	replace_stk(b, index * way * -1);
	// write(1, "after replace2", 14);
	// debug_printer(*a, *b);
	return (tpint);
}

int	ft_get_index_b(t_stack **a, t_stack **b)
{
	int	index;
	int	tpint;
	// int	old_b_size;
	
	index = -1;
	tpint = 0;
	// old_b_size = ft_lstsize(*b);
	while (tpint != -1 && ++index < (ft_lstsize(*b) / 2) + 1) //////// was (ft_lstsize(*b) / 2)
	{
		tpint = ft_index_found(a, b, index, 1); //  the original part
		if (tpint != -1)
		{
			tpint = ft_index_found(a, b, index , -1); // index + 1
				if (tpint == -1)
					return (ft_lstsize(*b) - index); // index - 1
		}
		else
			return (index);

		// write(1, "\nB", 2);
		// debug_printer(*a, *b);
	}
	// ft_mega_clearer(*a, *b, NULL);
	return (index);
}

int ft_move_stk(t_stack **a, t_stack **b, int index, int *indexb_help)
{
	int	tpint;
	// t_stack	*a_dup;
	// t_stack	*b_dup;

	if (a && index > 0)
	{
		tpint = index;
		while (tpint > 0)
			fr(a, NULL, &tpint, NULL);
	}
	else if (a)
	{
		index = index * -1;
		tpint = 0;
		while (tpint < index * 2)
			frr(a, NULL, &tpint, NULL);
	}
	// a_dup = duplicator(*a);
	// b_dup = duplicator(*b);
	// write(1, "before b call", 13);
	// debug_printer(*a, *b);
	tpint = ft_get_index_b(a, b); //&a_dup, &b_dup
	*indexb_help = tpint;
	if (tpint > ft_lstsize(*b) / 2)
		tpint = ft_lstsize(*b) - tpint;
	return (tpint);
}

int	ft_get_index_a(t_stack **a, t_stack **b, int *indexb)
{
	int		index;
	int		tpint;
	int		min_move;
	int		best_index;
	int		indexb_help;

	index = -1;
	min_move = -1;
	indexb_help = 0;
	while (++index < (ft_lstsize(*a) / 2) + 1 && index < (ft_lstsize(*b) / 2) + 1) //////// was ++index < (ft_lstsize(*a) / 2) + 1 && index < (ft_lstsize(*b) / 2) + 1
	{ /// old test : ++index < (ft_lstsize(*a) / 3) + 1 && index < (ft_lstsize(*b) / 3) + 1
		// write(1, "\nA1", 3);
		// debug_printer(*a, *b);
		tpint = ft_move_stk(a, b, index, &indexb_help);
		if (min_move == -1 || index + tpint < min_move)
		{
			min_move = index + tpint;
			best_index = index;
			*indexb = indexb_help;
		}
		tpint = ft_move_stk(a, b, (index * -1), &indexb_help);
		if (index + tpint < min_move)
		{
			min_move = index + tpint;
			best_index = ft_lstsize(*a) - index;// - 1
			*indexb = indexb_help;
		}
		replace_stk(a, index);
		// write(1, "\nA2", 3);
		// debug_printer(*a, *b);
	}
	// ft_mega_clearer(*a, *b, NULL);
	// write(1, "after a find: ", 14);
	// ft_putnbr_fd(best_index, 1);
	// debug_printer(*a, *b);
	return (best_index);
}

void ft_sort_three(t_stack **a)
{
	int	min;
	int	max;

	min = find_index_min(*a);
	max = find_index_max(*a);
	if ((min == 0 && max == 1) || (min == 2 && max == 0))
	{
		sa(a);
		// if (min == 2 && max == 0)
		// 	rra(a, NULL);
		// else
		// 	ra(a, NULL);
	}
	else if ((min == 1 && max == 2) || (min == 1 && max == 2))
		sa(a);
	// else if (min == 2 && max == 1)
	// 	rra(a, NULL);
	// else if (min == 1 && max == 0)
	// 	ra(a, NULL);
}
// 1 2 3 ; 1 3 2 sa, ra ; 2 1 3 sa ; 2 3 1 rra ; 3 2 1 sa, ra ; 3 1 2 ra

int	ft_get_place(t_stack *stk, int num)
{
	int		i;
	t_stack	*nstk;
	
	i = 0;
	nstk = duplicator(stk);
	while (nstk && !(nstk->content > num && ft_lstlast(nstk)->content < num) && i < ft_lstsize(nstk))
	{
		// rb(&nstk, NULL);
		// debug_printer(nstk, stk);
		fr(&nstk, NULL, NULL, NULL);
		i ++;
	}
	ft_mega_clearer(nstk, NULL, NULL);
	return (i);
}


void	ft_empty_b(t_stack **a, t_stack **b)
{
	int	move_count;

	while (ft_lstsize(*b) != 0)
	{
		// debug_printer(*a, *b);
		if ((*b)->content > ft_get_max(*a))
			move_count = find_index_max(*a) + 1;
		else if ((*b)->content < ft_get_min(*a))
			move_count = find_index_min(*a);
		else
			move_count = ft_get_place(*a, (*b)->content);
		// ft_putnbr_fd(move_count, 1);
		// write(1, "\n", 1);
		while (a && *a && (move_count > 0 && move_count < ft_lstsize(*a)))
			if (ft_lstsize(*a) - move_count < (ft_lstsize(*a) + 1) / 2)
				rra(a, &move_count);
			else
				ra(a, &move_count);
		pa(a, b);
	}
}

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

static int	fr(t_stack **stk, t_stack **stk2, int *place, int *placeb)
{
	t_stack	*temp;

	if (stk2 && *stk2 && (*stk2)->next && place && *place == -1 && find_index_max(*stk2) != 0)
			if (ft_lstsize(*stk2) - *placeb < (ft_lstsize(*stk2) + 1) / 2)
				fr(stk2, NULL, ((int *)-1), placeb);
	if (stk && *stk && (*stk)->next)
	{
		temp = *stk;
		while (temp->next)
			temp = temp->next;
		temp->next = *stk;
		*stk = (*stk)->next;
		temp->next->next = NULL;
	}
	if (place && *place && *place != -1)
		*place = *place - 1;
	else
		if (placeb && *placeb)
			*placeb= *placeb - 1;
	return (0);
}

static int	frr(t_stack **stk, t_stack **stk2, int *place, int *placeb)
{
	t_stack	*temp;

	if (stk2 && *stk2 && (*stk2)->next && place && *place == -1 && find_index_max(*stk2) != 0)
			if (ft_lstsize(*stk2) - *placeb < (ft_lstsize(*stk2) + 1) / 2)
				fr(stk2, NULL, ((int *)-1), placeb);
	if (stk && *stk && (*stk)->next)
	{
		temp = *stk;
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *stk;
		*stk = temp->next;
		temp->next = NULL;
	}
	if (place && *place != -1)
		*place = *place + 1;
	else
		if (placeb && *placeb)
			*placeb = *placeb + 1;
	return (0);
}




//######################################################################################

























int	is_s_useful(t_stack *stk)
{
	t_stack	*temp;
	int		bool;

	if (stk && stk->next != NULL)
	{
		bool = 0;
		temp = stk;
		stk = stk->next;
		temp->next = stk->next;
		stk->next = temp;
		if (is_sorted(stk))
			bool = 1;
		temp = stk;
		stk = stk->next;
		temp->next = stk->next;
		stk->next = temp;
		if (bool == 1)
			return (1);
	}
	return (0);
}

















// void	algo(t_stack **a, t_stack **b)
// {
// 	int	i;

// 	while (!is_sorted(*a))
// 	{
// 		i = find_index_min(*a);
// 		while ((i > 0 && i < ft_lstsize(*a)) && (!is_sorted(*a)))
// 		{
// 			// if (is_s_useful(*a) || (*a)->content > (*a)->next->content)
// 			// {
// 			// 	sa(a);
// 			// 	i --;
// 			// }
// 			if (ft_lstsize(*a) - i < (ft_lstsize(*a) + 1) / 2)
// 			{
// 				rra(a, NULL);
// 				i ++;
// 			}
// 			else if (find_index_min(*a) != 0)
// 			{
// 				ra(a, NULL);
// 				i --;
// 			}
// 		}
// 		if (find_index_min(*a) == 0 && !is_sorted(*a))
// 			pb(b, a);
// 		while (is_sorted(*a) && ft_lstsize(*b) > 0)
// 			pa(a, b);
// 	}
// }