/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:47:32 by mbirou            #+#    #+#             */
/*   Updated: 2023/12/02 13:45:39 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	*testint1;
	int	*testint2;
	int	len;
	int	i;
	int	len_1;
	int	len_2;

	if (argc > 1)
	{
		len_1 = ft_atoi(argv[1]);
		len_2 = ft_atoi(argv[2]);
		testint1 = malloc(len_1 * sizeof(int));
		testint2 = malloc(len_2 * sizeof(int));
		i = 3;
		while (argv[i] && i < len_1 + 3)
		{
			testint1[i - 3] = ft_atoi(argv[i]);
			i ++;
		}
		while (argv[i] && i < len_2 + len_1 + 3)
		{
			testint2[i - 3 - len_1] = ft_atoi(argv[i]);
			i ++;
		}
		len = i - 1;
		i = 0;
		
		while (i < len_1)
		{
			ft_putnbr(testint1[i]);
			write(1, " ", 1);
			i ++;
		}
		write(1, ",", 1);
		i = 0;
		while (i < len_2)
		{
			ft_putnbr(testint2[i]);
			write(1, " ", 1);
			i ++;
		}
		
		if (s_check(testint1))
			s(&testint1);
		write(1, "\nsa\n", 4);
		
		i = 0;
		while (i < len_1)
		{
			ft_putnbr(testint1[i]);
			write(1, " ", 1);
			i ++;
		}
		write(1, ",", 1);
		i = 0;
		while (i < len_2)
		{
			ft_putnbr(testint2[i]);
			write(1, " ", 1);
			i ++;
		}

		if (p_check(testint1, len_1, testint2, len_2))
		{
			p(&testint1, &len_1, &testint2, &len_2);
		}
		write(1, "\npb\n", 4);

		i = 0;
		while (i < len_1)
		{
			ft_putnbr(testint1[i]);
			write(1, " ", 1);
			i ++;
		}
		write(1, ",", 1);
		i = 0;
		while (i < len_2)
		{
			ft_putnbr(testint2[i]);
			write(1, " ", 1);
			i ++;
		}
		
		if (r_check(testint2, len_2))
		{
			r(&testint2, len_2);
		}
		write(1, "\nrb\n", 4);

		i = 0;
		while (i < len_1)
		{
			ft_putnbr(testint1[i]);
			write(1, " ", 1);
			i ++;
		}
		write(1, ",", 1);
		i = 0;
		while (i < len_2)
		{
			ft_putnbr(testint2[i]);
			write(1, " ", 1);
			i ++;
		}

		if (rr_check(testint2, len_2))
		{
			rr(&testint2, len_2);
		}
		write(1, "\nrrb\n", 5);

		i = 0;
		while (i < len_1)
		{
			ft_putnbr(testint1[i]);
			write(1, " ", 1);
			i ++;
		}
		write(1, ",", 1);
		i = 0;
		while (i < len_2)
		{
			ft_putnbr(testint2[i]);
			write(1, " ", 1);
			i ++;
		}

		if (p_check(testint2, len_2, testint1, len_1))
		{
			p(&testint2, &len_2, &testint1, &len_1);
		}
		write(1, "\npa\n", 4);

		i = 0;
		while (i < len_1)
		{
			ft_putnbr(testint1[i]);
			write(1, " ", 1);
			i ++;
		}
		write(1, ",", 1);
		i = 0;
		while (i < len_2)
		{
			ft_putnbr(testint2[i]);
			write(1, " ", 1);
			i ++;
		}

		if (s_check(testint1))
			s(&testint1);
		write(1, "\nsa\n", 4);	

		i = 0;
		while (i < len_1)
		{
			ft_putnbr(testint1[i]);
			write(1, " ", 1);
			i ++;
		}
		write(1, ",", 1);
		i = 0;
		while (i < len_2)
		{
			ft_putnbr(testint2[i]);
			write(1, " ", 1);
			i ++;
		}

		write(1, "\n", 1);
		free(testint1);
		free(testint2);
	}
	return (0);
}



int	*get_tier(int **stack, int len_stack)
{
	int	max_num_id;
	int	*tier;
	int	i;

	tier = (int *)malloc(len_stack * sizeof(int));
	tier[0] = stack[0][0];
	max_num_id = 0;
	i = -1;
	while (++i < len_stack)
	{
		if (tier[0] < stack[0][i])
			tier[0] = i;
	}
	i --;
	while (i >= 0)
	{
		if (stack[0][i] > stack[0][tier[max_num_id]] && (max_num_id == 0 || (max_num_id > 0 && stack[0][i] < stack[0][tier[max_num_id - 1]])))
		{
			tier[max_num_id] = i;
			i = len_stack - 1;
		}
		i --;
	}
	return (tier);
}

















































































int	s(int **stack)
{
	int	temp;

	if (*stack && stack[0][0] && stack[0][1])
	{
		temp = stack[0][0];
		stack[0][0] = stack[0][1];
		stack[0][1] = temp;
		return (1);
	}
	return (0);
}

int	s_check(int *stack)
{
	if (stack && stack[0] && stack[1])
		return (1);
	return (0);
}
static int	*p_utils(int dest, int len_dest, int **src, int len_src);
int	p(int **a, int *len_a, int **b, int *len_b)
{
	int	i;
	int	tp_len;
	int	*tpa;
	int	*tp_stack;

	i = 0;
	if (*a && *a[0] && *b)
	{
		tp_stack = p_utils(a[0][0], 1, b, *len_b);
		free(*b);
		*b = tp_stack;
		tpa = &a[0][1];
		tp_stack = p_utils(0, 0, &tpa, *len_a - 1);
		free(*a);
		*a = tp_stack;
		tp_len = *len_a - 1;
		*len_a = tp_len;
		tp_len = *len_b + 1;
		*len_b = tp_len;
		return (1);
	}
	return (0);
}
static int	*p_utils(int dest, int len_dest, int **src, int len_src)
{
	int		i;
	int		len;
	int		*tp;

	i = 0;
	tp = malloc(len_dest + len_src);
	if (!tp)
		return (NULL);
	len = 0;
	if (dest && len_dest == 1)
	{
		tp[i] = dest;
		i ++;
	}
	while (*src && len < len_src)
	{
		tp[i] = src[0][len];
		i++;
		len ++;
	}
	return (tp);
}
int	p_check(int *a, int len_a, int *b, int len_b)
{
	if (a && a[0] && b && len_a != 0 && len_b != 0)
		return (1);
	return (0);
}

int r(int **stack, int len_stack)
{
	int	temp_val;
	int	i;

	if (*stack && stack[0][0] && stack[0][1] && len_stack > 1)
	{
		i = 0;
		temp_val = stack[0][len_stack];
		stack[0][len_stack] = stack[0][0];
		while (i < len_stack)
		{
			stack[0][i] = stack[0][i + 1];
			i ++;
		}
		stack[0][i] = temp_val;
		return (1);
	}
	return (0);
}

int	r_check(int * stack, int len_stack)
{
	if (stack && stack[0] && stack[0] && len_stack > 1)
		return (1);
	return (0);
}

int rr(int **stack, int len_stack)
{
	int	temp_val;
	int	i;

	if (*stack && stack[0][0] && stack[0][1] && len_stack > 1)
	{
		i = len_stack;
		temp_val = stack[0][0];
		stack[0][0] = stack[0][len_stack - 1];
		while (i > 1)
		{
			stack[0][i] = stack[0][i - 1];
			i --;
		}
		stack[0][1] = temp_val;
		return (1);
	}
	return (0);
}

int	rr_check(int * stack, int len_stack)
{
	if (stack && stack[0] && stack[0] && len_stack > 1)
		return (1);
	return (0);
}