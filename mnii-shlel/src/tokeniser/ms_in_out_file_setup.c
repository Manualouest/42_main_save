/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_in_out_file_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:38:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/21 21:51:23 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

static void	ms_appends_setup(t_cmd *cmd, char ***args, int *i)
{
	char	*file;

	if (!ft_strncmp(args[0][*i], ">>", 2) && cmd->error_id != BAD_FILE
		&& ft_strlen(args[0][*i]) == 2 && args[0][*i + 1]
		&& args[0][*i + 1][0] != '>' && args[0][*i + 1][0] != '<')
	{
		if (cmd->fd_out > 1)
			close(cmd->fd_out);
		file = ms_clean_filename(args[0][*i + 1]);
		cmd->fd_out = ms_opens(cmd, file, ms_is_file_real(file), 1);
		args[0] = ms_remove_filename(args[0], *i);
		*i = *i - 1;
		free(file);
	}
	else
		ms_handle_errors(cmd, BAD_FILE, MS_SYNTAX_ERROR, args[0][*i + 1]);
	if (cmd->error_id == BAD_FILE && cmd->fd_out > 1)
		close(cmd->fd_out);
}

static void	ms_redirects_setup(t_cmd *cmd, char ***args, int *i)
{
	char	*file;

	if (args[0][*i][0] == '>' && ft_strlen(args[0][*i]) == 1
		&& args[0][*i + 1] && cmd->error_id != BAD_FILE
		&& args[0][*i + 1][0] != '>' && args[0][*i + 1][0] != '<')
	{
		if (cmd->fd_out > 1)
			close(cmd->fd_out);
		file = ms_clean_filename(args[0][*i + 1]);
		cmd->fd_out = ms_opens(cmd, file, ms_is_file_real(file), 0);
		args[0] = ms_remove_filename(args[0], *i);
		*i = *i - 1;
		free(file);
	}
	else
		ms_handle_errors(cmd, BAD_FILE, MS_SYNTAX_ERROR, args[0][*i + 1]);
	if (cmd->error_id == BAD_FILE && cmd->fd_out > 1)
		close(cmd->fd_out);
}

static void	ms_inputs_setup(t_cmd *cmd, char ***args, int *i)
{
	char	*file;

	if (args[0][*i][0] == '<' && ft_strlen(args[0][*i]) == 1
		&& args[0][*i + 1] && cmd->error_id != BAD_FILE
		&& args[0][*i + 1][0] != '>' && args[0][*i + 1][0] != '<')
	{
		if (cmd->fd_in > 0)
			close(cmd->fd_in);
		file = ms_clean_filename(args[0][*i + 1]);
		cmd->fd_in = ms_opens(cmd, file, ms_is_file_real(file), -1);
		args[0] = ms_remove_filename(args[0], *i);
		*i = *i - 1;
		free(file);
	}
	else
		ms_handle_errors(cmd, BAD_FILE, MS_SYNTAX_ERROR, args[0][*i + 1]);
	if (cmd->error_id == BAD_FILE && cmd->fd_in > 0)
		close(cmd->fd_in);
}

int	ms_head_to_next_symbol(char **args, int prev_index, int error_id)
{
	int	index;

	index = prev_index;
	if (index < -1)
		index = -1;
	if (error_id != NO_ERROR)
		return (-1);
	while (args && (index == -1 || (index >= 0 && args[index]))
		&& index < tablen(args) && args[++index])
	{
		if ((((args[index][0] == '<' || args[index][0] == '>')
			&& ft_strlen(args[index]) == 1)
			|| ((!ft_strncmp(args[index], ">>", 2)
				|| !ft_strncmp(args[index], "<<", 2))
				&& ft_strlen(args[index]) == 2)))
			return (index);
	}
	return (-1);
}

void	ms_in_out_files_setup(t_cmd *cmd)
{
	t_cmd	*cpy_cmd;
	char	**args;
	int		index;

	ms_separate_symbols_base(cmd);
	cpy_cmd = cmd;
	index = -1;
	while (cpy_cmd)
	{
		args = cpy_cmd->args;
		index = ms_head_to_next_symbol(args, index, cpy_cmd->error_id);
		if (index == -1 && --index == -2)
			cpy_cmd = cpy_cmd->next;
		else if (args[index][0] == '>' && ft_strlen(args[index]) == 1)
			ms_redirects_setup(cpy_cmd, &args, &index);
		else if (args[index][0] == '<' && ft_strlen(args[index]) == 1)
			ms_inputs_setup(cpy_cmd, &args, &index);
		else if (!ft_strncmp(args[index], ">>", 2))
			ms_appends_setup(cpy_cmd, &args, &index);
		else if (!ft_strncmp(args[index], "<<", 2) && (args[index + 1]
				&& (args[index + 1][0] == '>' || args[index + 1][0] == '<')))
			ms_handle_errors(cmd, BAD_FILE, MS_SYNTAX_ERROR, args[index + 1]);
		if (cpy_cmd && index != -2)
			cpy_cmd->args = args;
	}
}
