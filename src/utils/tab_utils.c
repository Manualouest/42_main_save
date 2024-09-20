/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:32:55 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/20 13:58:16 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

int	pr_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i ++;
	return (i);
}

int	*pr_strtoi(char *str)
{
	int		*nums;
	char	**split_str;
	int		i;

	split_str = ft_split(str, ' ');
	nums = ft_calloc(sizeof(*nums), pr_tab_len(split_str) + 1);
	nums[pr_tab_len(split_str)] = -1;
	i = -1;
	while (split_str[++i])
	{
		nums[i] = ft_atoi(split_str[i]);
		free(split_str[i]);
	}
	free(split_str);
	return (nums);
}

float	*pr_strtor(char *str)
{
	float	*nums;
	char	**split_str;
	int		i;

	split_str = ft_split(str, ' ');
	nums = ft_calloc(sizeof(*nums), pr_tab_len(split_str) + 1);
	nums[pr_tab_len(split_str)] = -1.;
	i = -1;
	while (split_str[++i])
	{
		nums[i] = ft_atoi(split_str[i]) * M_PI / 180;
		nums[i] = floor(nums[i] * 1000) / 1000;
		free(split_str[i]);
	}
	free(split_str);
	return (nums);
}