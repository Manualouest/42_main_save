/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:15:43 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/01 16:56:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

static char	**heredoc_lst_to_tab(t_list *lst);

char	**ms_heredoc(char *limiter)
{
	t_list	*tab;
	char	**ret;
	char	*input;

	input = readline(HEREDOC_PROMPT);
	tab = NULL;
	while (input && (ft_strlen(limiter) != ft_strlen(input)
			|| (ft_strncmp(input, limiter, ft_strlen(input)) != 0)))
	{
		ft_lstadd_back(&tab, ft_lstnew(input));
		input = readline(HEREDOC_PROMPT);
	}
	if (input)
		free(input);
	input = NULL;
	ft_lstadd_back(&tab, ft_lstnew(input));
	ret = heredoc_lst_to_tab(tab);
	return (ret);
}

static char	**heredoc_lst_to_tab(t_list *lst)
{
	t_list	*tmp;
	char	**tab;
	int		i;

	i = ft_lstsize(lst);
	tab = ft_calloc(i, sizeof(char *));
	i = 0;
	while (lst)
	{
		tab[i] = lst->content;
		i++;
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (tab);
}

void	ms_free_end_heredoc(t_command *cmd, t_params *prev, t_params *tp_param)
{
	if (prev)
	{
		free(prev->next);
		prev->next = NULL;
	}
	else if (!cmd->params->text)
	{
		free(cmd->params);
		cmd->params = NULL;
	}
	else if (cmd->params->next && cmd->params->next->text)
	{
		while (tp_param && tp_param->next && tp_param->next->text)
			tp_param = tp_param->next;
		free(tp_param->next);
		tp_param->next = NULL;
	}
	else
	{
		free(cmd->params->next);
		cmd->params->next = NULL;
	}
}

void	ms_fill_params_heredoc(t_command *cmd, t_params *params, char **doc,
			int line_i)
{
	char		*item;
	t_params	*prev;
	int			doc_i;

	prev = NULL;
	doc_i = -1;
	while (doc[++doc_i] && (!cmd->params->text
			|| (cmd->params->text && doc_i > 0)))
	{
		line_i = 0;
		params->quote_level = 4;
		item = ms_get_next_param(doc[doc_i], &line_i, 4, line_i);
		while (item && ft_strlen(item) > 0)
		{
			prev = ms_setup_params_text_and_symbol(params, item);
			params->quote_level = 4;
			params = params->next;
			free(item);
			item = ms_get_next_param(doc[doc_i], &line_i, 4, line_i);
		}
		free(item);
	}
	ms_free_end_heredoc(cmd, prev, cmd->params);
	params = cmd->params;
}

void	ms_launch_heredoc(t_command *cmd, t_params *params,
			char *line, int *main_index)
{
	char		**heredoc;
	char		*limiter;
	int			i;

	limiter = ms_get_next_item(line, main_index);
	heredoc = ms_heredoc(limiter);
	free(limiter);
	i = -1;
	if (cmd->builtins == NO_CMD && (ms_is_line_done(line, *main_index, NULL)
			|| ((line[*main_index] && line[*main_index] == '|')
				|| (line[*main_index] && line[*main_index + 1]
					&& line[*main_index + 1] == '|'))))
		ms_fill_params_heredoc(cmd, params, heredoc, 0);
	i = -1;
	while (heredoc[++i])
		free(heredoc[i]);
	free(heredoc);
	if (line[*main_index] && line[*main_index + 1]
		&& line[*main_index] == ' ')
		*main_index = *main_index + 1;
	if (cmd->builtins != NO_CMD
		|| ((line[*main_index] && line[*main_index] != '|')
			&& (line[*main_index] && line[*main_index + 1]
				&& line[*main_index + 1] != '|')))
		ms_fill_params(cmd, params, line, main_index);
}
