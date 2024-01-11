/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg_rush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:50:40 by glaurich          #+#    #+#             */
/*   Updated: 2023/09/03 16:50:46 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str);

char	*pars_numbers_final(char *ret, char *str, int dep)
{
	int	i;
	int	j;

	i = dep;
	j = 0;
	while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
char	*parsing_arg_nbr(char *ret, char *str)
{
	int	tab[3];

	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 0;
	if (str[tab[0]] == '-')
		return (NULL);
	while (str[tab[2]] != 0 && str[tab[2]] == '0')
		tab[2]++;
	tab[0] = tab[2];
	while (str[tab[0]] != 0 && str[tab[0]] >= '0' && str[tab[0]] <= '9')
	{
		tab[1]++;
		tab[0]++;
	}
	if (tab[2] > 0 && tab[1] == 1)
		return ("0");
	if (ft_strlen(str) == tab[0] && tab[1] > 1)
	{
		ret = (char *)malloc(tab[1] * sizeof(char));
		ret = pars_numbers_final(ret, str, (tab[0] + 1 - tab[1]));
		return (ret);
	}
	else
		return (NULL);
}
