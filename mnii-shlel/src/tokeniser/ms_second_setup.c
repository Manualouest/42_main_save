/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_second_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:00:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/19 21:44:48 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

char	*ms_setup_env(char *tp_env, char **arg, int env_start, int env_len)
{
	char	*env_content;
	char	*new_arg;
	int		index;

	index = -1;
	while (tp_env && tp_env[++index] && tp_env[index] != '=')
		;
	env_content = ft_substr(tp_env, index + 1, ft_strlen(tp_env));
	new_arg = ms_tripple_join(ft_substr(arg[0], 0, env_start), env_content,
			ft_strdup(&arg[0][env_start + env_len]));
	free(env_content);
	free(arg[0]);
	return (new_arg);
}

int	ms_env_util(char **arg, int *index, int *len)
{
	int	quote_level;

	quote_level = 0;
	while (arg[0][++*index])
	{
		--*index;
		while (arg[0][++*index] && arg[0][*index] != '$')
			quote_level = ms_change_quote_level(arg[0], *index, quote_level);
		if (quote_level != 1)
			break ;
	}
	if (quote_level == 1)
	{
		*index = -1;
		*len = -1;
		return (0);
	}
	while (arg[0][++*len + *index] && arg[0][*len + *index] != ' '
		&& arg[0][*len + *index] != '$'
		&& arg[0][*len + *index] != -1 && arg[0][*len + *index] != -2)
		if (*len > 1 && arg[0][(*len - 1) + *index] == '?')
			break ;
	return (1);
}

void	ms_do_env(char **arg, char **envp)
{
	int		index;
	int		env_len;
	char	*env_name;
	char	*env_content;

	index = -1;
	env_len = 0;
	if (!ms_env_util(arg, &index, &env_len))
		return ;
	env_name = ft_substr(arg[0], index + 1, env_len - 1);
	if (env_name[0] == '?')
	{
		free(env_name);
		env_name = ft_itoa(g_signal);
		env_content = ft_strjoin("=", env_name);
		arg[0] = ms_setup_env(env_content, arg, index, env_len);
		free(env_name);
		free(env_content);
		return ;
	}
	env_content = envp_find(envp, env_name);
	arg[0] = ms_setup_env(env_content, arg, index, env_len);
	free(env_name);
}

void	ms_hide_quotes(t_cmd *cmd, char **arg)
{
	int		has_pair;
	int		index;
	char	target_quote;

	index = -1;
	has_pair = 0;
	target_quote = '0';
	while (arg[0][++index])
	{
		if ((target_quote == '0' && (arg[0][index] == '\''
				|| arg[0][index] == '"')) || arg[0][index] == target_quote)
		{
			if (has_pair)
				target_quote = '0';
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
		cmd->error_id = BAD_QUOTE;
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
				if (cmd->args[arg_i][i] == -1 || cmd->args[arg_i][i] == -2)
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

void	ms_setup_round_two(t_cmd *cmd, char **envp)
{
	int		args_index;
	t_cmd	*cpy_cmd;

	cpy_cmd = cmd;
	while (cpy_cmd)
	{
		args_index = -1;
		while (cpy_cmd->args[++args_index])
		{
			// if (ms_change_quote_level(cpy_cmd->args[args_index], 0, 0) != 0)
			ms_hide_quotes(cpy_cmd, &cpy_cmd->args[args_index]);
			while (cpy_cmd->args && ms_has_dollar(cpy_cmd->args[args_index]))
				ms_do_env(&cpy_cmd->args[args_index], envp);
			if (!cpy_cmd->args)
			{
				ms_free_cmd(cmd);
				return ;
			}
		}
		cpy_cmd = cpy_cmd->next;
	}
	ms_in_out_files_setup(cmd);
}
