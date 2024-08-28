/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_second_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:20:40 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/25 21:25:30 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

void	ms_incr_var_len(char *arg, int *var_len, int i)
{
	int	is_num;

	is_num = ft_isdigit(arg[i + 1]);
	while (arg[++*var_len + i] && (!is_num || *var_len != 2
			|| (is_num && !ft_isdigit(arg[*var_len + i])))
		&& (ft_isalnum(arg[*var_len + i]) || arg[*var_len + i] == '_'))
		;
}

int	ms_get_var_start(char *arg, int *var_len)
{
	int	quote_level;
	int	i;

	quote_level = 0;
	i = -1;
	while (arg[++i])
	{
		quote_level = ms_change_quote_level(arg, i, quote_level);
		if (quote_level % 2 == 0 && arg[i] == '$')
		{
			if (!arg[i + 1] || arg[i + 1] == ' ' || (arg[i + 1] < 0
					&& !ms_change_quote_level(arg, i + 1, quote_level))
				|| arg[i + 1] == '"' || arg[i + 1] == '\'' || arg[i + 1] == '=')
				continue ;
			if (ms_change_quote_level(arg, i + 1, 0) != 0)
				return (i);
			if (arg[i + 1] == '?')
				*var_len = 2;
			if (arg[i + 1] == '?')
				return (i);
			ms_incr_var_len(arg, var_len, i);
			return (i);
		}
	}
	return (-1);
}

char	*ms_get_var_parse(char *arg, int var_pos, int var_len)
{
	char	*var_name;

	if (var_pos == -1)
		return (NULL);
	if (var_len >= 0)
		var_name = ft_substr(arg, var_pos + 1, var_len);
	else
		var_name = ft_calloc(sizeof(char), 1);
	if (!var_name)
		return (NULL);
	return (var_name);
}

char	*ms_get_var(char *arg, int var_pos, int var_len, char **envp)
{
	char	*var_name;
	char	*raw_content;
	char	*var_content;

	var_name = ms_get_var_parse(arg, var_pos, var_len);
	if (!var_name)
		return (NULL);
	if (var_name[0] == '?')
	{
		var_content = ft_itoa(g_signal);
		free(var_name);
		return (var_content);
	}
	else
		raw_content = envp_find(envp, var_name);
	free(var_name);
	if (!raw_content)
	{
		raw_content = ft_calloc(sizeof(char), 1);
		return (raw_content);
	}
	var_content = ft_strdup(&(ft_strchr(raw_content, '=')[1]));
	return (var_content);
}

int	ms_setup_round_two(t_cmd *cmd, char **envp)
{
	t_cmd		*cpy_cmd;

	cpy_cmd = cmd;
	ms_separate_symbols_base(cmd, 0);
	while (cpy_cmd)
	{
		cpy_cmd->args = ms_remove_empty_chars(cpy_cmd->args);
		if (!ms_expand_loop(&cpy_cmd->args, envp))
		{
			ms_handle_errors(NULL, 0, MS_FAIL_STRUCT, NULL);
			return (0);
		}
		cpy_cmd = cpy_cmd->next;
	}
	ms_in_out_files_setup(cmd, envp);
	ms_remove_hiders(cmd, -1);
	return (1);
}
