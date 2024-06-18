/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_second_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:00:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/18 20:25:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_has_dollar(char *arg)
{
	int	index;

	index = -1;
	while (arg[++index])
		if (arg[index] == '$')
			return (1);
	return (0);
}

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

void	ms_do_env(char **arg, char **envp)
{
	int		index;
	int		env_len;
	char	*env_name;
	char	*env_content;

	index = -1;
	env_len = 0;
	while (arg[0][++index] && arg[0][index] != '$')
		;
	while (arg[0][++env_len + index] && ft_isalpha(arg[0][env_len + index]))
		;
	env_name = ft_substr(arg[0], index + 1, env_len - 1);
	if (ft_strlen(env_name))
		env_content = envp_find(envp, env_name);
	else
	{
		free(env_name);
		arg[0] = ms_setup_env("=", arg, index, env_len);
		return ;
	}
	arg[0] = ms_setup_env(env_content, arg, index, env_len);
	free(env_name);
}

void	ms_remove_quotes(t_cmd *cmd, char **arg)
{
	int		len_arg;
	char	*tp_char;
	char	*tp_arg;
	int		has_pair;
	int		index;

	index = -1;
	has_pair = 0;
	len_arg = ft_strlen(arg[0]);
	if ((arg[0][0] == '\'' || arg[0][0] == '"')
		&& arg[0][0] == arg[0][len_arg - 1])
	{
		has_pair ++;
		while (arg[0][++index])
		{
			if (arg[0][index] == arg[0][0] && index > 0)
			{
				if (has_pair)
					has_pair --;
				else
					has_pair ++;
				tp_char = ft_substr(arg[0], 0 + (index == len_arg - 1), index - 1);
				tp_arg = ft_strjoin(tp_char, &arg[0][index + 1]);
				free(tp_char);
				free(arg[0]);
				arg[0] = tp_arg;
				index --;
			}
		}
		// tp_arg = ft_substr(arg[0], 1, len_arg - 2);
		// free(arg[0]);
		// arg[0] = tp_arg;
		// has_pair --;
	}
	if (has_pair)
		cmd->error_id = BAD_QUOTE;
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
			while (cpy_cmd->args && cpy_cmd->args[args_index][0] != '\''
				&& ms_has_dollar(cpy_cmd->args[args_index]))
				ms_do_env(&cpy_cmd->args[args_index], envp);
			if (!cpy_cmd->args)
			{
				ms_free_cmd(cmd);
				return ;
			}
			if (cpy_cmd->args[args_index][0] == '\''
				|| cpy_cmd->args[args_index][0] == '"')
				ms_remove_quotes(cmd, &cpy_cmd->args[args_index]);
		}
		cpy_cmd = cpy_cmd->next;
	}
	ms_redirect_append_setup(cmd);
	// ms_input_setup(cmd);
}
