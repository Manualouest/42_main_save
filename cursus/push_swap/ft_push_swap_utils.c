/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:04:25 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/18 19:14:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_stack_maker(char **args, t_stack **a, int nb_args)
{
	int	i;

	i = 1;
	if (!args || !*args)
		return (0);
	*a = ft_lstnew(ft_atoi(args[i - 1]));
	if (*a == NULL || (args[i - 1] && ft_atoi(args[i - 1]) == 0
			&& args[i - 1][0] != '0'))
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
		if (str[i] != ' ' && !(str[i] >= '0' && str[i] <= '9')
			&& !((str[i] == '+' || str[i] == '-') && (str[i + 1]
					&& str[i + 1] >= '0' && str[i + 1] <= '9')))
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

char	**ft_stk_mk_util2(char **new_args)
{
	int	i;

	i = 0;
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

char	**ft_stk_mk_util(char **args, int *nb_args)
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
		return (ft_stk_mk_util2(new_args));
	}
	return (NULL);
}
