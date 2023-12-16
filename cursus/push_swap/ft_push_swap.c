/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:56:39 by mbirou            #+#    #+#             */
/*   Updated: 2023/12/16 20:06:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

#include <stdio.h>
// void	debug_printer(t_stack *stk);
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
		// write(1, "\na: ", 4);
		// debug_printer(a);
		// write(1, "\nb: \n", 5);
		// debug_printer(b);
		// write(1, "before\n", 7);
		algo(&a, &b);
		// write(1, "\na: ", 4);
		// debug_printer(a);
		// write(1, "\nb: \n", 5);
		// debug_printer(b);
		// write(1, "after\n", 7);
		ft_mega_clearer(a, b, argv);
	}
	exit (0);
}

// write(1, "\na: ", 4);
// debug_printer(a);
// write(1, "\nb: \n", 5);
// debug_printer(b);
// write(1, "before\n", 7);

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

char	**stack_maker_utils(char **args, int *nb_args)
{
	char	**new_args;
	char	*tp_args;
	int		i;

	i = 2;
	if (ft_has_letter(args[i]))
		return(NULL);
	tp_args = ft_strlcat(NULL, args[1], 0);
	while (i < *nb_args)
	{
		if (ft_has_letter(args[i]))
		{
			free(tp_args);
			return(NULL);
		}
		tp_args = ft_strlcat(tp_args, args[i], 1);
		i ++;
	}
	if (args[0] != 0)
	{
		new_args = ft_split(tp_args, " "[0], nb_args);
		if (new_args == NULL)
			return (NULL);
		return (new_args);
	}
	return (NULL);
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

void	debug_printer(t_stack *stk)
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

void	algo(t_stack **a, t_stack **b)
{
	int	i;

	while (!is_sorted(*a))
	{
		i = find_index_min(*a);
		while ((i > 0 && i < ft_lstsize(*a)) && (!is_sorted(*a)))
		{
			if (is_s_useful(*a) || (*a)->content > (*a)->next->content)
			{
				sa(a);
				i --;
			}
			else if (ft_lstsize(*a) - i < (ft_lstsize(*a) + 1) / 2)
			{
				rra(a);
				i ++;
			}
			else if (find_index_min(*a) != 0)
			{
				ra(a);
				i --;
			}
		}
		if (find_index_min(*a) == 0 && !is_sorted(*a))
			pb(b, a);
		while (is_sorted(*a) && ft_lstsize(*b) > 0)
			pa(a, b);
	}
}

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
