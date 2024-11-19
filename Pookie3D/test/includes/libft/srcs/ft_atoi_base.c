/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:22:28 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	is_invalid(char *base)
{
	int	i;
	int	g;

	i = 0;
	while (base[i])
	{
		g = i + 1;
		while (base [g])
		{
			if (base[g] == base[i])
				return (0);
			g++;
		}
		g = 0;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	ft_atoi_base(char *base, char *to_convert)
{
	int	i;
	int	j;
	int	base_num;
	int	count;

	count = 0;
	if (!is_invalid(base))
		return (0);
	base_num = ft_strlen(base);
	j = 0;
	while (to_convert[j])
	{
		i = 0;
		while (base[i] != to_convert[j])
			i++;
		count = count * base_num + i;
		j++;
	}
	return (count);
}
