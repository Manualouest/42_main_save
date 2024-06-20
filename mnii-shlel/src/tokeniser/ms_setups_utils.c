/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setups_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:01:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/20 18:56:26 by mbirou           ###   ########.fr       */
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

int	ms_is_there_pipe(char *line, int index)
{
	int	quote_level;

	quote_level = 0;
	while (line[++index] && !(line[index] == '|' && quote_level == 0))
	{
		quote_level = ms_change_quote_level(line, index, quote_level);
	}
	if (line[index] == '|' && quote_level == 0)
		return (1);
	return (0);
}

int	ms_change_quote_level(char *line, int index, int old_quote_level)
{
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

char	*ms_tripple_join(char *first, char *second, char *third)
{
	char	*f_s_joined;
	char	*full_join;

	f_s_joined = ft_strjoin(first, second);
	full_join = ft_strjoin(f_s_joined, third);
	if (first)
		free(first);
	if (third)
		free(third);
	if (f_s_joined)
		free(f_s_joined);
	return (full_join);
}

int	ms_has_dollar(char *arg)
{
	int	index;
	int	quote_level;

	quote_level = 0;
	index = -1;
	while (arg[++index])
	{
		quote_level = ms_change_quote_level(arg, index, quote_level);
		if (quote_level != 1 && arg[index] == '$' && arg[index + 1]
			&& arg[index +1] != ' ' && arg[index +1] != -1
			&& arg[index +1] != -2)
			return (1);
	}
	return (0);
}
