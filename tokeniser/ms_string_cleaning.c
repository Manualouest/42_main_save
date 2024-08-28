/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_string_cleaning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:00:31 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/25 20:11:30 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

void	ms_slide_char(char *str, int index)
{
	int	i;

	while (--index >= 0)
	{
		i = -1;
		while (str[++i + 1])
			str[i] = str[i + 1];
		str[i] = str[i + 1];
	}
}

void	ms_shorten_str(char *str, int index)
{
	if (index > (int)ft_strlen(str))
		return ;
	while (str[index])
	{
		str[index] = 0;
		index ++;
	}
}

int	ms_setup_doubles(t_cmd *cmd, int *len, int *i)
{
	if (*len == 0 && cmd->args[*i][*len + 1] == cmd->args[*i][*len]
		&& cmd->args[*i][*len + 2])
		return (1);
	else if (*len != 0 && cmd->args[*i][*len + 1] == cmd->args[*i][*len]
		&& cmd->args[*i][*len + 2])
		return (1);
	return (0);
}

static void	ms_do_separation(t_cmd *cmd, int *len, int *i)
{
	int	double_sep;

	double_sep = ms_setup_doubles(cmd, len, i);
	if ((*len == 0 && cmd->args[*i][*len + 1] != cmd->args[*i][*len])
		|| (*len == 0 && cmd->args[*i][*len + 1] == cmd->args[*i][*len]
		&& cmd->args[*i][*len + 2]))
	{
		cmd->args = tab_append(cmd->args,
				ft_substr(cmd->args[*i], 0, *len + 1 + double_sep), *i);
		ms_slide_char(cmd->args[*i + 1], 1 + double_sep);
		*len = 0;
	}
	else if ((*len != 0 && cmd->args[*i][*len + 1] != cmd->args[*i][*len])
		|| (*len != 0 && cmd->args[*i][*len + 1] == cmd->args[*i][*len]
		&& cmd->args[*i][*len + 2]))
	{
		cmd->args = tab_append(cmd->args,
				ft_strdup(&cmd->args[*i][*len]), *i + 1);
		ms_shorten_str(cmd->args[*i], *len + double_sep);
		*len = 0;
	}
}

void	ms_separate_symbols_base(t_cmd *cmd, int quote)
{
	int		i;
	int		l;

	while (cmd)
	{
		i = -1;
		while (cmd->args[i + (i == -1)] && cmd->args[++i])
		{
			l = -1;
			while (i < tablen(cmd->args) && cmd->args[i][++l])
			{
				quote = ms_change_quote_level(cmd->args[i], l, quote);
				if ((quote == 0) && (((cmd->args[i][l] != cmd->args[i][l + 1]
						&& (l == 0
							|| (cmd->args[i][l] != cmd->args[i][l - 1])))
							&& ft_strlen(cmd->args[i]) != 1)
						|| (cmd->args[i][l] == cmd->args[i][l + 1]
							&& ft_strlen(cmd->args[i]) != 2))
					&& (cmd->args[i][l] == '<' || cmd->args[i][l] == '>'))
					ms_do_separation(cmd, &l, &i);
			}
		}
		cmd = cmd->next;
	}
}
