/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_in_out_file_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:38:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/19 20:24:55 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

static void	ms_appends_setup(t_cmd *cmd)
{
	int	index;

	index = -1;
	while (cmd->args[++index])
	{
		if (!ft_strncmp(cmd->args[index], ">>", 2) && cmd->error_id != BAD_FILE
			&& ft_strlen(cmd->args[index]) == 2 && cmd->args[index + 1])
		{
			if (cmd->fd_out != 1)
				close(cmd->fd_out);
			cmd->fd_out = ms_opens(cmd, cmd->args[index + 1],
					ms_is_file_real(cmd->args[index + 1]), 1);
			cmd->args = ms_remove_filename(cmd->args, index);
			index --;
		}
		else if (!ft_strncmp(cmd->args[index], ">>", 2)
			&& ft_strlen(cmd->args[index]) == 2 && !cmd->args[index + 1])
			cmd->error_id = BAD_FILE;
	}
	if (cmd->fd_out == -1)
		cmd->error_id = BAD_FILE;
	if (cmd->error_id == BAD_FILE && cmd->fd_out > 1)
		close(cmd->fd_out);
}

static void	ms_redirects_setup(t_cmd *cmd)
{
	int	index;

	index = -1;
	while (cmd->args[++index])
	{
		if (cmd->args[index][0] == '>' && ft_strlen(cmd->args[index]) == 1
			&& cmd->args[index + 1] && cmd->error_id != BAD_FILE)
		{
			if (cmd->fd_out != 1)
				close(cmd->fd_out);
			cmd->fd_out = ms_opens(cmd, cmd->args[index + 1],
					ms_is_file_real(cmd->args[index + 1]), 0);
			cmd->args = ms_remove_filename(cmd->args, index);
			index --;
		}
		else if (cmd->args[index][0] == '>' && !cmd->args[index + 1]
			&& ft_strlen(cmd->args[index]) == 1)
			cmd->error_id = BAD_FILE;
	}
	if (cmd->fd_out == -1)
		cmd->error_id = BAD_FILE;
	if (cmd->error_id == BAD_FILE && cmd->fd_out > 1)
		close(cmd->fd_out);
}

static void	ms_inputs_setup(t_cmd *cmd)
{
	int	index;

	index = -1;
	while (cmd->args[++index])
	{
		if (cmd->args[index][0] == '<' && ft_strlen(cmd->args[index]) == 1
			&& cmd->args[index + 1] && cmd->error_id != BAD_FILE)
		{
			if (cmd->fd_in != 0)
				close(cmd->fd_in);
			cmd->fd_in = ms_opens(cmd, cmd->args[index + 1],
					ms_is_file_real(cmd->args[index + 1]), -1);
			cmd->args = ms_remove_filename(cmd->args, index);
			index --;
		}
		else if (cmd->args[index][0] == '<' && !cmd->args[index + 1]
			&& ft_strlen(cmd->args[index]) == 1)
			cmd->error_id = BAD_FILE;
	}
	if (cmd->fd_in == -1)
		cmd->error_id = BAD_FILE;
	if (cmd->error_id == BAD_FILE && cmd->fd_in > 0)
		close(cmd->fd_in);
}

void	ms_in_out_files_setup(t_cmd *cmd)
{
	t_cmd	*cpy_cmd;

	ms_separate_symbols_base(cmd);
	cpy_cmd = cmd;
	ms_remove_hiders(cpy_cmd, -1);
	cpy_cmd = cmd;
	while (cpy_cmd)
	{
		ms_redirects_setup(cpy_cmd);
		ms_appends_setup(cpy_cmd);
		ms_inputs_setup(cpy_cmd);
		cpy_cmd->first = cmd;
		cpy_cmd = cpy_cmd->next;
	}
}
