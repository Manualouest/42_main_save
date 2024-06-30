/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_string_cleaning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:00:31 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/27 23:37:11 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

static void	ms_do_separation(t_cmd *cmd, int *len, int *i)
{
	char	*tp_char;

	if ((*len > 0 && (cmd->args[*i][*len - 1] == '<'
			|| cmd->args[*i][*len - 1] == '>'))
			|| (cmd->args[*i][*len] == '<' || cmd->args[*i][*len] == '>'))
	{
		cmd->args = tab_append(cmd->args,
				ft_substr(cmd->args[*i], 0, *len), *i);
		*i = *i + 1;
		tp_char = ft_substr(cmd->args[*i], *len, ft_strlen(cmd->args[*i]));
		free(cmd->args[*i]);
		cmd->args[*i] = tp_char;
		*len = 0;
	}
}

void	ms_separate_symbols_base(t_cmd *cmd)
{
	int		i;
	int		l;
	int		quote;
	int		old_quote;

	quote = 0;
	while (cmd)
	{
		i = -1;
		while (cmd->args[i + (i == -1)] && cmd->args[++i])
		{
			l = -1;
			while (cmd->args[i] && cmd->args[i][++l])
			{
				old_quote = quote;
				quote = ms_change_quote_level(cmd->args[i], l, quote);
				// if ((quote == 0 || old_quote == 0) && cmd->args[i][l + 1]
				// 	&& !(((l == 1 && (cmd->args[i][l - 1] == '<'
				// 				|| cmd->args[i][l - 1] == '>')) || l == 0)
				// 	&& (cmd->args[i][l] == '<' || cmd->args[i][l] == '>')))
				if ((quote == 0 || old_quote == 0) && cmd->args[i][l + 1]
					&& !((l == 0 || (l == 1 && (cmd->args[i][l - 1] == '<'
								|| cmd->args[i][l - 1] == '>') && cmd->args[i][l - 1] == cmd->args[i][l]))
					&& (cmd->args[i][l] == '<' || cmd->args[i][l] == '>')))
					ms_do_separation(cmd, &l, &i);
				// if ((quote == 0 || old_quote == 0) && l > 0
				// 	&& (cmd->args[i][l - 1] == '<' || cmd->args[i][l - 1] == '>'))
				// 	ms_do_separation(cmd, &l, &i);
			}
		}
		cmd = cmd->next;
	}
}

void	ms_quote_hider(t_cmd *cmd, char **arg)
{
	int		has_pair;
	int		index;
	char	target_quote;

	index = -1;
	has_pair = 0;
	target_quote = -4;
	while (arg[0][++index])
	{
		if ((target_quote == -4 && (arg[0][index] == '\''
				|| arg[0][index] == '"')) || arg[0][index] == target_quote)
		{
			if (has_pair)
				target_quote = -4;
			else
				target_quote = arg[0][index];
			if (has_pair)
				has_pair --;
			else
				has_pair ++;
			arg[0][index] = (char)(-1 - (arg[0][index] == '\''));
		}
	}
	if (has_pair)
		ms_handle_errors(cmd, BAD_QUOTE, MS_SYNTAX_ERROR, NULL);
}

void	ms_hide_quotes(t_cmd *cmd)
{
	int	arg_i;

	while(cmd)
	{
		arg_i = -1;
		while (cmd->args[++arg_i])
			ms_quote_hider(cmd, &cmd->args[arg_i]);
		cmd = cmd->next;
	}
}

void	ms_remove_hiders(t_cmd *cd, int a_i)
{
	char	*tp_arg;
	int		i;

	while (cd)
	{
		a_i = -1;
		cd->args = ms_remove_empty_chars(cd->args);
		while (cd->args[++a_i])
		{
			i = -1;
			while (cd->args[a_i] && cd->args[a_i][++i])
			{
				if (cd->args[a_i][i] < 7 && cd->args[a_i - (a_i >= 1)][0] != '<'
					&& cd->args[a_i - (a_i >= 1)][0] != '>')
				{
					tp_arg = ms_tripple_join(ft_substr(cd->args[a_i], 0, i),
						&cd->args[a_i][i + 1], "", 100);
					free(cd->args[a_i]);
					cd->args[a_i] = tp_arg;
					i --;
				}
			}
		}
		cd = cd->next;
	}
}
