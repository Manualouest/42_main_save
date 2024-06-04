/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokeniser_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:13:02 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/17 16:31:08 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_get_right_symbol(char *item)
{
	int	symbol;

	if (ft_strncmp(item, "'", 1) == 0)
		symbol = QUOTE;
	else if (item[0] == '"')
		symbol = DOUBLE_QUOTE;
	else if (ft_strncmp(item, "<<", 2) == 0)
		symbol = HEREDOC;
	else if (ft_strncmp(item, "<", 1) == 0)
		symbol = INPUT;
	else if (ft_strncmp(item, ">>", 2) == 0)
		symbol = APPEND;
	else if (ft_strncmp(item, ">", 1) == 0)
		symbol = REDIRECT;
	else if (ft_strncmp(item, "$", 1) == 0)
		symbol = DOLLAR;
	else
		symbol = NO_SYMBOL;
	return (symbol);
}

void	ms_setup_params_quote_level(t_params *params, char *item)
{
	if (params->symbol == QUOTE || (params->quote_level == 1
			&& item[0] == "'"[0]))
	{
		if (params->quote_level == 1)
			params->quote_level = 0;
		else if (params->quote_level == 0)
			params->quote_level = 1;
	}
	else if (params->symbol == DOUBLE_QUOTE || (params->quote_level == 2
			&& item[0] == '"'))
	{
		if (params->quote_level == 2)
			params->quote_level = 0;
		else if (params->quote_level == 0)
			params->quote_level = 2;
	}
}

void	ms_setupd_params_text_and_symbol(t_params *params, char *item)
{
	if (params->quote_level % 2 == 0 && ((ft_strlen(item) == 1
				&& ms_is_symbol(item[0])) || (ft_strlen(item) == 2
				&& (ft_strncmp(item, "<<", 2) == 0
					|| ft_strncmp(item, ">>", 2) == 0))))
		params->type = 0;
	else if (params->quote_level % 2 == 0)
		params->type = 1;
	else
	{
		if (ft_strncmp(item, "'", 1) == 0)
			params->type = 0;
		else
			params->type = 1;
	}
	params->text = NULL;
	params->symbol = NO_SYMBOL;
	if (params->type == 0)
		params->symbol = ms_get_right_symbol(item);
	else
	{
		params->text = malloc(sizeof(char) * (ft_strlen(item)) + 1);
		ft_strlcpy(params->text, item, ft_strlen(item) + 1);
	}
	ms_setup_params_quote_level(params, item);
}

char	*ms_get_next_param(char *line, int *main_index, int quote, int start)
{
	int		i;

	i = *main_index;
	while (line && i <= (int)ft_strlen(line) && line[i])
	{
		if ((quote == 0 && ((ms_is_symbol(line[i]) && line[i] != '<'
						&& line[i] != '>') || (i > start
						&& (!ms_is_symbol(line[i - 1])
							!= !ms_is_symbol(line[i])
							|| ms_is_symbol(line[i - 1])))))
			|| (quote == 1 && line[i] == "'"[0])
			|| (quote == 2 && ((line[i] == '"' || line[i] == '$')
					|| (i == start + 1 && line[i - 1] == '$')))
			|| (quote == 0 && ((i > start && line[i] == '|')
					|| (i == start + 1 && line[i - 1] == '|'))))
			break ;
		i ++;
	}
	if (i <= (int)ft_strlen(line) && (((line[i] == "'"[0] || line[i] == '"'
					|| line[i] == '$') && i == start) || (i == start + 1
				&& line[i - 1] == line[i])))
		i ++;
	*main_index = i;
	return (ft_substr(line, start, (i - start)));
}

void	ms_fill_params(t_command *cmd, t_params *params, char *line, int *i)
{
	char		*item;
	t_params	*previous;

	item = ms_get_next_param(line, i, params->quote_level, *i);
	if (ft_strncmp(item, "|", 1) == 0 || ms_is_line_done(line, *i, item) == 1)
	{
		free(item);
		free(params);
		cmd->params = NULL;
		return ;
	}
	while (!(ft_strncmp(item, "|", 1) == 0 && ft_strlen(item) == 1)
		&& ms_is_line_done(line, *i, item) == 0)
	{
		ms_setupd_params_text_and_symbol(params, item);
		params->next = malloc(sizeof(*params->next));
		previous = params;
		params->next->quote_level = params->quote_level;
		params = params->next;
		free(item);
		item = ms_get_next_param(line, i, params->quote_level, *i);
	}
	free(previous->next);
	previous->next = NULL;
	free(item);
}
