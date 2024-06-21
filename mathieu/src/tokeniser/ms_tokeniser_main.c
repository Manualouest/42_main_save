/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokeniser_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:48:35 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/21 19:29:08 by mbirou           ###   ########.fr       */
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
	cpy_cmd = cmd;
	while (cpy_cmd)
	{
		if (cpy_cmd->error_id != NO_ERROR && cmd->error_id == NO_ERROR)
			cmd->error_id = cpy_cmd->error_id;
		cpy_cmd = cpy_cmd->next;
	}
	return (cmd);
}
