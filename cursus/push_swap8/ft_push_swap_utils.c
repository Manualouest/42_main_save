/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:04:25 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/08 12:00:21 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
		if (((num >= 214748364 && (nptr[i] - '0') >=8) && sign == 1)
		|| (!(num <= 214748364 && (nptr[i] - '0') <=8) && sign == -1))
			return (0);
		num = num * 10 + (nptr[i] - '0');
		i ++;
	}
	if (nptr[i] != 0 && !(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	return ((int)num * sign);
}

int	stack_maker(char **args, t_stack **a, int nb_args)
{
	int	i;

	i = 1;
	if (!args || !*args)
		return (0);
	*a = ft_lstnew(ft_atoi(args[i - 1]));
	if (*a == NULL || (args[i - 1] && ft_atoi(args[i - 1]) == 0 && args[i - 1][0] != '0'))
	{
		ft_lstclear(a);
		return (0);
	}
	while (i < nb_args)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(args[i])));
		if (*a == NULL || (ft_atoi(args[i]) == 0 && args[i][0] != '0'))
		{
			ft_lstclear(a);
			return (0);
		}
		i ++;
	}
	return (1);
}

int	ft_has_letter(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= '0' && str[i] <= '9') && !((str[i] == '+' || str[i] == '-') && (str[i + 1] && str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (1);
		i ++;
	}
	len = 0;
	while (str[len] != 0)
	{
		len ++;
	}
	if (len != i || len + i == 0)
		return (1);
	return (0);
}

int	ft_has_no_double(char **args, int nb_args)
{
	int	n;
	int	i;

	i = 0;
	while (i < nb_args)
	{
		n = i + 1;
		while (n < nb_args)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[n]))
				return (0);
			n ++;
		}
		i ++;
	}
	return (1);
}

char	**stack_maker_utils(char **args, int *nb_args)
{
	char	**new_args;
	char	*tp_args;
	int		i;

	i = 2;
	tp_args = ft_strlcat(NULL, args[1], 0);
	while (i < *nb_args)
	{
		if (ft_has_letter(args[i]))
		{
			free(tp_args);
			return (NULL);
		}
		tp_args = ft_strlcat(tp_args, args[i], 1);
		i ++;
	}
	if (args[0] != 0)
	{
		new_args = ft_split(tp_args, " "[0], nb_args);
		free (tp_args);
		if (new_args == NULL)
			return (NULL);
		i = 0; //############################## can be moved in freeing function
		while (new_args[i])
		{
			if (ft_has_letter(new_args[i]))
			{
				i = 0;
				while (new_args[i])
				{
					free(new_args[i]);
					i ++;
				}
				free(new_args[i]);
				free(new_args);
				return (NULL);
			}
			i ++;
		}
		if (i == 0)
		{
			free(new_args);
			return (NULL);
		}
		return (new_args);
	}
	return (NULL);
}

char    *ft_itoa(int n);
#include <stdio.h>
t_stack	*duplicator(t_stack *stk)
{
	char	*temp;
	char	*num_temp;
	char	**args;
	int		i;
	t_stack	*n_stk;

	args = NULL;
	temp = NULL;
	n_stk = NULL;
	while (stk && stk->next)
	{
		num_temp = ft_itoa(stk->content);
		temp = ft_strlcat(temp, num_temp, 1);
		free (num_temp);
		stk = stk->next;
	}
	if (stk && temp)
	{
		num_temp = ft_itoa(stk->content);
		temp = ft_strlcat(temp, num_temp, 1);
		free (num_temp);
	}
	if (temp)
	{
		args = ft_split(temp, " "[0], &i);
		free (temp);
	}
	if (args)
		i = stack_maker(args, &n_stk, i);
	ft_mega_clearer(NULL, NULL, args);
	// write(1, "\nstk: ", 6);
	// debug_printer(n_stk);
	// printf("n%in", i);
	return (n_stk);
}

static int      get_num_len(int num);
static int      ft_abs(int num);
static char     *fill_num(char *dst, int num, int num_len);

char    *ft_itoa(int n)
{
        char    *num;
        int             len_num;

        len_num = get_num_len(n);
        num = malloc((len_num + 1) * sizeof(char));
        if (!num)
                return (NULL);
        num[len_num] = 0;
        num = fill_num(num, n, len_num - 1);
        return (num);
}

static char     *fill_num(char *dst, int num, int num_len)
{
        int     stop;

        stop = 0;
        if (num < 0)
        {
                dst[0] = '-';
                stop ++;
        }
        while (num_len >= stop)
        {
                dst[num_len] = ft_abs(num % 10) + '0';
                num_len --;
                num = num / 10;
        }
        return (dst);
}

static int      get_num_len(int num)
{
        int     i;

        i = 0;
        if (num <= 0)
                i ++;
        while (num != 0)
        {
                num = ft_abs(num / 10);
                if (num == 10 || num == -10)
                        i ++;
                i ++;
        }
        return (i);
}

static int      ft_abs(int num)
{
        if (num < 0)
                return (-(num));
        return (num);
}