/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:21:55 by malbrech          #+#    #+#             */
/*   Updated: 2023/08/24 11:21:57 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	res;
	
	
	i = 0;
	minus = 1;
	res = 0;
	while ((str[i] >= 9 && 13 >= str[i]) || \
		str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && '9' >= str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res *= minus);
}

int	main(int ac,char **av)
{
	if ( ac == 2 )
	{
		printf("%d", ft_atoi(av[1]));
	}
}
