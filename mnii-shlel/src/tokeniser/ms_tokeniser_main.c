/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokeniser_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:48:35 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/24 09:20:12 by mbirou           ###   ########.fr       */
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
	t_cmd	*cpy_cmd;

	cpy_cmd = cmd;
	while (cpy_cmd)
	{
		if (tablen(cpy_cmd->args) == 0)
		{
			if (cpy_cmd->next)
				ms_handle_errors(cmd, 1, MS_SYNTAX_ERROR, "|");
			else
				ms_handle_errors(cmd, 1, MS_SYNTAX_ERROR, NULL);
			return (1);
		}
		cpy_cmd = cpy_cmd->next;
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
	t_cmd	*cpy_cmd;
	char	*tp_char;
	int		arg_i;

	cpy_cmd = cmd;
	while (cpy_cmd)
	{
		arg_i = -1;
		while (cpy_cmd->args[++arg_i])
		{
			if (cpy_cmd->args[arg_i][0] == -3 && cpy_cmd->args[arg_i]
				[ft_strlen(cpy_cmd->args[arg_i]) - 1] == -3)
			{
				tp_char = ms_find_env_name(cpy_cmd->args[arg_i], envp);
				free(cpy_cmd->args[arg_i]);
				cpy_cmd->args[arg_i] = ft_strjoin("$", tp_char);
				free(tp_char);
			}
		}
		cpy_cmd = cpy_cmd->next;
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
		ms_setup_round_two(cmd, envp);
	else
		cmd = ms_free_cmd(cmd);
	if (!cmd)
		return (NULL);
	ms_clean_delimiters(cmd, envp);
	cpy_cmd = cmd;
	while (cpy_cmd && cpy_cmd->error_id == NO_ERROR)
		cpy_cmd = cpy_cmd->next;
	if (cpy_cmd && cpy_cmd->error_id != NO_ERROR)
		cmd = ms_free_cmd(cmd);
	return (cmd);
}
