/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokeniser_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:48:35 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/08 05:26:11 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

void	*ms_free_cmd(t_cmd *cmd)
{
	int		i;
	t_cmd	*tp_cmd;

	while (cmd != NULL)
	{
		i = -1;
		if (cmd->args)
		{
			while (cmd->args[++i] != 0)
				free(cmd->args[i]);
			free(cmd->args[i]);
			free(cmd->args);
		}
		tp_cmd = cmd->next;
		free(cmd);
		cmd = tp_cmd;
	}
	cmd = NULL;
	return (NULL);
}

int	ms_check_for_bad_pipe(t_cmd *cmd)
{
	while (cmd)
	{
		if (tablen(cmd->args) == 0)
		{
			if (cmd->next)
				ms_handle_errors(cmd, 1, MS_SYNTAX_ERROR, "|");
			else
				ms_handle_errors(cmd, 1, MS_SYNTAX_ERROR, NULL);
			return (1);
		}
		cmd = cmd->next;
	}
	return (0);
}

char	*ms_find_env_name(char *content, char **envp)
{
	int		i;
	int		content_len;
	char	*tp_char;

	i = 0;
	tp_char = ft_substr(content, 2, ft_strlen(content) - 3);
	while (envp[i])
	{
		content_len = -1;
		while (envp[i] && envp[i][++content_len] && envp[i][content_len] != '=')
			;
		if (ft_strncmp(&envp[i][content_len + 1], tp_char, ft_strlen(tp_char)) == 0
			&& ft_strlen(tp_char) == ft_strlen(envp[i]) - content_len - 1)
		{
			free(tp_char);
			return ft_substr(envp[i], 0, content_len);
		}
		i++;
	}
	free(tp_char);
	return (NULL);
}

void	ms_clean_delimiters(t_cmd *cmd, char **envp)
{
	char	*tp_char;
	int		arg_i;

	while (cmd)
	{
		arg_i = -1;
		while (cmd->args[++arg_i])
		{
			if (cmd->args[arg_i][0] == -3 && cmd->args[arg_i]
				[ft_strlen(cmd->args[arg_i]) - 1] == -3)
			{
				tp_char = ms_find_env_name(cmd->args[arg_i], envp);
				free(cmd->args[arg_i]);
				cmd->args[arg_i] = ft_strjoin("$", tp_char);
				free(tp_char);
			}
		}
		cmd = cmd->next;
	}
}

t_cmd	*ms_tokeniser_main(char *line, char **envp)
{
	t_cmd	*cmd;
	t_cmd	*cpy_cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	ms_base_setup(cmd, line);
	if (ms_check_for_bad_pipe(cmd))
		return (cmd);
	if (cmd && envp)
		ms_hide_quotes(cmd);
	if (cmd && envp)
		ms_setup_round_two(cmd, envp);
	else
		cmd = ms_free_cmd(cmd);
	if (!cmd || g_signal == 2)
		return (NULL);
	// ms_clean_delimiters(cmd, envp);
	cpy_cmd = cmd;
	while (cpy_cmd && cpy_cmd->error_id == NO_ERROR)
		cpy_cmd = cpy_cmd->next;
	if (cpy_cmd && cpy_cmd->error_id != NO_ERROR)
		cmd->error_id = cpy_cmd->error_id;
	return (cmd);
}
