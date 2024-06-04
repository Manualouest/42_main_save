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


void	ft_do_move(t_stack **a, t_stack **b, int index, int indexb);
int	ft_get_best(t_stack *a, t_stack *b);
int	ft_sort_single(t_stack *a, t_stack *b, int place); // , int *curr_count

static int	frr(t_stack **stk, t_stack **stk2,  int *place, int *placeb);
static int	fr(t_stack **stk, t_stack **stk2,  int *place, int *placeb);
int	ft_find_place(t_stack *a, t_stack *b, int place);


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






int	ft_get_place(t_stack *stk, int num);
int	ft_get_min(t_stack *stk);
int	ft_get_max(t_stack *stk);
void	ft_empty_b(t_stack **a, t_stack **b);
void ft_sort_three(t_stack **a);

void	algo(t_stack **a, t_stack **b)
{
	int	i;
	int indexb;

	if (ft_lstsize(*a) > 3)
	{
		pb(b, a);
		pb(b, a);
		// if (is_sorted(*b))
		// 	sb(b);
	}
	while (!is_sorted(*a) && ft_lstsize(*a) >= 4) // 
	{
		i = ft_get_best(*a, *b);
		indexb = ft_find_place(*a, *b, i);
		// write(1, "\n;\n", 3);
		// ft_putnbr_fd(indexb, 1); #############################################
		// debug_printer(*a, *b);
		// write(1, ",\n", 2);
		ft_do_move(a, b, i, indexb);
	}
	// if (is_s_useful(*a) && *a && *b && (*a)->content < (*b)->content)
	// 	sa(a);
	// i = find_index_min(*a);
	// while ((i > 0 && i < ft_lstsize(*a)))
	// 	if (ft_lstsize(*a) - i < (ft_lstsize(*a) + 1) / 2)
	// 		rra(a, &i);
	// 	else
	// 		ra(a, &i);
	// while ((*a)->content < (*b)->content)
	// 	ra(a, NULL);
	ft_sort_three(a);
	if (b && *b)
	{
		while (find_index_max(*b) != 0 && find_index_max(*b) != ft_lstsize(*b))
		{
			if (ft_lstsize(*b) - find_index_max(*b) < (ft_lstsize(*b)) / 2)
				rrb(b, NULL);
			else
				rb(b, NULL);
		}
	}

	ft_empty_b(a, b);
	i = find_index_min(*a);
	while ((i > 0 && i < ft_lstsize(*a)))
	{
		// debug_printer(*a, *b);
		if (ft_lstsize(*a) - i < (ft_lstsize(*a) + 1) / 2)
			rra(a, &i);
		else
			ra(a, &i);
	}
	i = 0;
	if (!is_sorted(*a))
	{
		while ((i >= 0 && i < ft_lstsize(*a)) && !is_sorted(*a))
		{
			// debug_printer(*a, *b);
			if ((*a)->next && (*a)->content > (*a)->next->content)
				sa(a);
			if (!is_sorted(*a))
				rra(a, &i);
		}
	}
	// }
}

void ft_sort_three(t_stack **a)
{
	int	min;
	int	max;

	min = find_index_min(*a);
	max = find_index_max(*a);
	// printf("min: %i, max: %i\n", min, max);
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


// int	move_count;

	// while (ft_lstsize(*b) != 0)
	// {
	// 	move_count = ft_lstsize(*a);
	// 	while (move_count > 0
	// 		&& !(((*a)->content > (*b)->content && find_index_max(*a) == 0)
	// 		|| ((*a)->content < (*b)->content && find_index_min(*a) == 0))
	// 			&& !((*a)->content > (*b)->content
	// 			&& ft_lstlast(*a)->content < (*b)->content))
	// 	{
	// 		if ((*a)->content > (*b)->content)
	// 			rra(a, NULL);
	// 		else //if (ft_lstsize(*a) > 2)
	// 			ra(a, NULL);
	// 		move_count --;
	// 	}
	// 	if (move_count == ft_lstsize(*a) //&& move_count > 2
	// 		&& (((*a)->content < (*b)->content && find_index_max(*a) == 0)
	// 		|| ((*a)->content > (*b)->content && find_index_min(*a) == 0)))
	// 	{
	// 		// write(1, "t", 1);
	// 		ra(a, NULL);
	// 	}
	// 	// if ((*a)->content > (*b)->content
	// 	// 	&& ft_lstlast(*a)->content < (*b)->content)
	// 	pa(a, b);
	// }

int		do_move_utils(t_stack *sta, t_stack *stb);
void	ft_do_move(t_stack **a, t_stack **b, int index, int indexb)
{
	while (a && *a && (index > 0 && index < ft_lstsize(*a)))
		if (ft_lstsize(*a) - index < (ft_lstsize(*a) + 1) / 2)
			rra(a, &index);
		else
			ra(a, &index);
						// if (indexb < 0)
						// 	indexb ++;
						// while (b && *b && (indexb != 0))
						// 	if (indexb < 0)
						// 		rrb(b, &indexb);
						// 	else if (indexb != 0)
						// 		rb(b, &indexb);
	// if (b && *b && a && *a && (*a)->content < (*b)->content && find_index_max(*b) != 0)
	// 	while ((*b)->next && (*a)->content < (*b)->content && find_index_max(*b) != 0)
	// 		rb(b, NULL);
	// rb(b, NULL);
	indexb = do_move_utils(*a, *b);
	while (indexb > 0 && indexb < ft_lstsize(*b))
	{
		if (ft_lstsize(*b) - indexb < (ft_lstsize(*b)) / 2)
		{
			rrb(b, NULL);
			indexb ++;
		}
		else
		{
			rb(b, NULL);
			indexb --;
		}
	}



	pb(b, a);
	// write(1, "\n*****", 6);
	// debug_printer(*a, *b);
	// write(1, "\n*****", 6);
	// while (find_index_max(*b) != 0)
	// 	rrb(b, NULL);
	// int i;
	// i = find_index_max(*b);
	// while ((i > 0 && i < ft_lstsize(*b)) && (!is_rsorted(*b)))
	// {
	// 	if (ft_lstsize(*b) - i < (ft_lstsize(*b) + 1) / 2)
	// 	{
	// 		rrb(b, &i);
	// 	}
	// 	else if (find_index_max(*b) != 0)
	// 	{
	// 		rb(b, &i);
	// 	}
	// }
}

int	do_move_utils(t_stack *sta, t_stack *stb)
{
	int	i;
	int	n;
	t_stack	*a;
	t_stack	*b;

	i = -1;
	b = NULL;
	// write(1, "--------------------\n", 21);
	while (!is_rsorted(b) && i < ft_lstsize(stb))
	{
		i ++;
		a = duplicator(sta);
		b = duplicator(stb);
		// write(1, "\n||||\n", 6); 
		// debug_printer(a, b);
		n = i;
		while (n > 0)
		{
			fr(&b, NULL, NULL, NULL);
			n --;
		}
		fp(&b, &a);
		while (find_index_max(b) != 0 && find_index_max(b) != ft_lstsize(b))
		{
			if (ft_lstsize(b) - find_index_max(b) < (ft_lstsize(b)) / 2)
				frr(&b, NULL, NULL, NULL);
			else
				fr(&b, NULL, NULL, NULL);
		}
		// debug_printer(a, b);
		// write(1, "i:", 2);
		// ft_putnbr_fd(i, 1);
		// write(1, "\n", 1);
	}

	return(i);
}

int	ft_get_best(t_stack *a, t_stack *b)
{
	int		i;
	int		place;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	place = 0;
	while (tmp && tmp->next)
	{
		if (i > ft_sort_single(a, b, place))
			i = ft_sort_single(a, b, place);
		tmp = tmp->next;
		place ++;
	}
	return (i);
}

int	ft_sort_single(t_stack *a, t_stack *b, int place)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		placeb;
	int		i;

	i = 1;
	tmpa = duplicator(a);
	tmpb = duplicator(b);
	placeb = ft_find_place(a, b, place);
	while (tmpa && (place > 0 && place < ft_lstsize(tmpa)))
	{
		if (ft_lstsize(tmpa) - place < (ft_lstsize(tmpa) + 1) / 2)
			frr(&tmpa, &tmpb, &place,  &placeb);
		else
			fr(&tmpa, &tmpb, &place, &placeb);
		i ++;
	}
	while (tmpb && (placeb > 0 && placeb < ft_lstsize(tmpb)))
	{
		if (ft_lstsize(tmpa) - placeb < (ft_lstsize(tmpa) + 1) / 2)
			frr(&tmpb, NULL, &placeb, NULL);
		else
			fr(&tmpb, NULL, &placeb, NULL);
		i ++;
	}
	ft_lstclear(&tmpb);
	ft_lstclear(&tmpa);
	return (i);
}

int	ft_find_place_util(t_stack *tmpa, int place)
{
	int	res;

	while (tmpa && (place > 0 && place < ft_lstsize(tmpa)))
		if (ft_lstsize(tmpa) - place < (ft_lstsize(tmpa) + 1) / 2)
			frr(&tmpa, NULL, &place, 0);
		else
			fr(&tmpa, NULL, &place, 0);
	if (tmpa)
	{
		res = tmpa->content;
		ft_lstclear(&tmpa);
		return (res);
	}
	return (-1);
}

int	ft_find_place(t_stack *a, t_stack *b, int place)
{
	int	i;
	int	tmpa;
	t_stack *tmpb;

	i = 0;
	tmpa = ft_find_place_util(duplicator(a), place);
	// write(1, "\n|", 2);
	// ft_putnbr_fd(place, 1); #############################################
	tmpb = duplicator(b);
	
	while (tmpa && tmpa != -1 && tmpb && tmpb->content > tmpa && i != ft_lstsize(b))
	{
		frr(&tmpb, NULL, NULL, 0);
		i ++;
	}
	// ft_putnbr_fd(i, 1); ################################################
	if (i > ft_lstsize(tmpb) / 2)
		i = -1 * (i - (ft_lstsize(b) / 2)); //  - 1
	ft_lstclear(&tmpb);
	return (i);
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
		if (place && *placeb)
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