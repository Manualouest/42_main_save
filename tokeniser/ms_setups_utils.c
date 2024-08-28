/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setups_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:01:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/25 19:29:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_go_to_pipe(char *line, int *main_index)
{
	int	new_index;
	int	quote_level;

	new_index = *main_index;
	quote_level = 0;
	while (line[new_index] && !(line[new_index] == '|' && quote_level == 0))
	{
		quote_level = ms_change_quote_level(line, new_index, quote_level);
		new_index ++;
	}
	*main_index = new_index;
	return (new_index);
}

int	ms_change_quote_level(char *line, int index, int old_quote_level)
{
	if (!line || index < 0 || index >= (int)ft_strlen(line) || !line[index])
		return (old_quote_level);
	if ((line[index] == '"' || line[index] == -1) && old_quote_level == 0)
		return (2);
	else if ((line[index] == '"' || line[index] == -1) && old_quote_level == 2)
		return (0);
	if ((line[index] == '\'' || line[index] == -2) && old_quote_level == 0)
		return (1);
	else if ((line[index] == '\'' || line[index] == -2)
		&& old_quote_level == 1)
		return (0);
	return (old_quote_level);
}

char	*ms_tripple_join(char *first, char *second, char *third, int frees)
{
	char	*f_s_joined;
	char	*full_join;

	f_s_joined = ft_strjoin(first, second);
	full_join = ft_strjoin(f_s_joined, third);
	if (first && frees % 1000 >= 100)
		free(first);
	if (second && frees % 100 >= 10)
		free(second);
	if (third && frees % 10 == 1)
		free(third);
	if (f_s_joined)
		free(f_s_joined);
	return (full_join);
}

char	**ms_remove_empty_chars(char **args)
{
	int		index;
	int		nb_empty;
	char	**n_args;

	index = -1;
	nb_empty = 0;
	while (args[++index])
		if (!ft_strlen(args[index]))
			nb_empty ++;
	n_args = ft_calloc(sizeof(char *), tablen(args) - nb_empty + 1);
	index = -1;
	nb_empty = 0;
	while (args[++index])
	{
		if (ft_strlen(args[index]) != 0)
			n_args[index - nb_empty] = args[index];
		else
		{
			nb_empty ++;
			free(args[index]);
		}
	}
	free(args);
	return (n_args);
}
