/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:32:55 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/22 21:28:20 by mbirou           ###   ########.fr       */
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

int	*pr_strtoi(char *str, t_data *data)
{
	int		*nums;
	char	**split_str;
	int		tab_len;
	int		src_len;
	int		i;

	split_str = ft_split(str, ' ');
	src_len = pr_tab_len(split_str);
	tab_len = src_len;
	if (src_len < data->nb_sphere)
		tab_len = data->nb_sphere + 1;
	nums = ft_calloc(sizeof(*nums), tab_len + 1);
	nums[tab_len] = -1;
	i = -1;
	while (split_str[++i])
	{
		nums[i] = ft_atoi(split_str[i]);
		free(split_str[i]);
	}
	i --;
	while (++i < data->nb_sphere)
		nums[i] = nums[i % src_len];
	free(split_str);
	return (nums);
}

float	*pr_strtor(char *str, t_data *data)
{
	float	*nums;
	char	**split_str;
	int		tab_len;
	int		src_len;
	int		i;

	split_str = ft_split(str, ' ');
	src_len = pr_tab_len(split_str);
	tab_len = src_len;
	if (src_len < data->nb_sphere)
		tab_len = data->nb_sphere + 1;
	nums = ft_calloc(sizeof(*nums), tab_len + 1);
	nums[tab_len] = -1.;
	i = -1;
	while (split_str[++i])
	{
		// nums[i] = ft_atoi(split_str[i]) * M_PI / 180;
		nums[i] = M_PI / 8.;
		nums[i] = floor(nums[i] * 1000) / 1000;
		free(split_str[i]);
	}
	i --;
	while (++i < data->nb_sphere)
		nums[i] = nums[i % src_len];
	free(split_str);
	return (nums);
}

int	*pr_extend_itab(int *tab)
{
	int	*n_tab;
	int	i;

	i = -1;
	while (tab[++i] != -1)
		;
	n_tab = ft_calloc(sizeof(*n_tab), i + 2);
	n_tab[i + 1] = -1;
	i = -1;
	while (tab[++i] != -1)
		n_tab[i] = tab[i];
	n_tab[i] = tab[i - 1];
	free(tab);
	return (n_tab);
}

float	*pr_extend_ftab(float *tab)
{
	float	*n_tab;
	int		i;

	i = -1;
	while (tab[++i] != -1)
		;
	n_tab = ft_calloc(sizeof(*n_tab), i + 2);
	n_tab[i + 1] = -1;
	i = -1;
	while (tab[++i] != -1)
		n_tab[i] = tab[i];
	n_tab[i] = tab[i - 1];
	free(tab);
	return (n_tab);
}
