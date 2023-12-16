/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:04:25 by mbirou            #+#    #+#             */
/*   Updated: 2023/12/16 20:05:52 by mbirou           ###   ########.fr       */
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
	if (!nptr)
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
	
	// if (nptr[i++] == '-')
	// 	sign = -1;
	// if (nptr[0] != '-' && nptr[0] != '+' && i == 1)
	// 	i --;

int	stack_maker(char **args, t_stack **a, int nb_args)
{
	int	i;

	i = 1;
	*a = ft_lstnew(ft_atoi(args[i - 1]));
	if (*a == NULL || (ft_atoi(args[i - 1]) == 0 && args[i][0] != '0'))
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
sta
	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !((str[i] == '+' || str[i] == '-') && (str[i] >= '0' && str[i] <= '9'))
			return (1);
		i ++;
	}
	len = 0;
	while (str[len] != 0)
	{
		len ++;
	}
	if (len != i)
		return (1);
	return (0);
}

int	ft_has_no_double(char **args, int nb_args)
{
	int	n;
	int	finds;
	int	i;

	i = 0;
	while (i < nb_args)
	{
		n = 1;
		finds = 0;
		while (n < nb_args)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[n]))
				finds ++;
			if (finds > 1)
				return (0);
			n ++;
		}
		i ++;
	}
	return (1);
}
