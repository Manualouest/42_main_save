/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_string_cleaning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:00:31 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/23 19:11:23 by mbirou           ###   ########.fr       */
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
	int		len;
	int		quote;
	int		old_quote;

	quote = 0;
	while (cmd)
	{
		i = -1;
		while (cmd->args[i + (i == -1)] && cmd->args[++i])
		{
			len = -1;
			while (cmd->args[i] && cmd->args[i][++len])
			{
				old_quote = quote;
				quote = ms_change_quote_level(cmd->args[i], len, quote);
				if ((quote == 0 || old_quote == 0)
					&& !(((len == 1 && (cmd->args[i][len - 1] == '<'
								|| cmd->args[i][len - 1] == '>')) || len == 0)
					&& (cmd->args[i][len] == '<' || cmd->args[i][len] == '>')))
					ms_do_separation(cmd, &len, &i);
				// if ((quote == 0 || old_quote == 0) && len > 0
				// 	&& (cmd->args[i][len - 1] == '<' || cmd->args[i][len - 1] == '>'))
				// 	ms_do_separation(cmd, &len, &i);
			}
		}
		cmd = cmd->next;
	}
}

char	*ms_clean_filename(char	*old_name)
{
	int		i;
	char	*name;
	char	*tp_str;
	char	*tp_arg;

	i = -1;
	name = ft_calloc(sizeof(char), ft_strlen(old_name) + 2);
	name[0] = (char)(-1);
	ft_strlcat(&name[1], &old_name[(i == 0)],
		ft_strlen(&old_name[(i == 0)]) + 2);
	while (name[++i])
	{
		if (name[i] < 0 || name[0] == 4)
		{
			tp_str = ft_substr(name, 0, i);
			tp_arg = ft_strjoin(tp_str, &name[i + 1]);
			free(tp_str);
			free(name);
			name = tp_arg;
			i -= 1;
		}
	}
	printf("pre filename: |%s|%d, %c\n", name, (int)name[0], name[0]);
	return (name);
}

void	ms_hide_quotes(t_cmd *cmd, char **arg)
{
	int		has_pair;
	int		index;
	char	target_quote;

	index = -1;
	has_pair = 0;
	target_quote = -3;
	while (arg[0][++index])
	{
		if ((target_quote == -3 && (arg[0][index] == '\''
				|| arg[0][index] == '"')) || arg[0][index] == target_quote)
		{
			if (has_pair)
				target_quote = -3;
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

void	ms_remove_hiders(t_cmd *cmd, int arg_i)
{
	char	*tp_char;
	char	*tp_arg;
	int		i;

	while (cmd)
	{
		arg_i = -1;
		while (cmd->args[++arg_i])
		{
			i = -1;
			while (cmd->args[arg_i][++i])
			{
				if (cmd->args[arg_i][i] < 0)
				{
					tp_char = ft_substr(cmd->args[arg_i], 0, i);
					tp_arg = ft_strjoin(tp_char, &cmd->args[arg_i][i + 1]);
					free(tp_char);
					free(cmd->args[arg_i]);
					cmd->args[arg_i] = tp_arg;
					i -= 1;
				}
			}
		}
		cmd = cmd->next;
	}
}
