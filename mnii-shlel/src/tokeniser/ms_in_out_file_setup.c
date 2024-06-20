/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_in_out_file_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:38:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/20 15:40:47 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

char	*ms_clean_filename(char	*old_name)
{
	int		i;
	char	*name;
	char	*tp_str;
	char	*tp_arg;

	// if (old_name[0] == -1 || old_name[0] == -2)
	// 	i = 0;
	// else
	i = -1;
	name = ft_calloc(sizeof(char), ft_strlen(&old_name[(i == 0)]) + 2);
	name[0] = (char)(- 1 - (i == 0));
	ft_strlcat(&name[1], &old_name[(i == 0)], ft_strlen(&old_name[(i == 0)]) + 2);
	while (name[++i])
	{
		if (name[i] == -1 || name[i] == -2)
		{
			tp_str = ft_substr(name, 0, i);
			tp_arg = ft_strjoin(tp_str, &name[i + 1]);
			free(tp_str);
			free(name);
			name = tp_arg;
			i -= 1;
		}
	}
	return (name);
}

static void	ms_appends_setup(t_cmd *cmd, char ***args, int *i)
{
	// int		i;
	char	*file;

	// i = -1;
	if (!ft_strncmp(args[0][*i], ">>", 2) && cmd->error_id != BAD_FILE
		&& ft_strlen(args[0][*i]) == 2 && args[0][*i + 1])
	{
		if (cmd->fd_out > 1)
			close(cmd->fd_out);
		file = ms_clean_filename(args[0][*i + 1]);
		cmd->fd_out = ms_opens(cmd, file, ms_is_file_real(file), 1);
		args[0] = ms_remove_filename(args[0], *i);
		*i = *i - 1;
		free(file);
	}
	else if (!ft_strncmp(args[0][*i], ">>", 2)
		&& ft_strlen(args[0][*i]) == 2 && !args[0][*i + 1])
		cmd->error_id = BAD_FILE;
	if (cmd->fd_out == -1)
		cmd->error_id = BAD_FILE;
	if (cmd->error_id == BAD_FILE && cmd->fd_out > 1)
		close(cmd->fd_out);
}

static void	ms_redirects_setup(t_cmd *cmd, char ***args, int *i)
{
	// int		i;
	char	*file;

	// i = -1;
	if (args[0][*i][0] == '>' && ft_strlen(args[0][*i]) == 1
		&& args[0][*i + 1] && cmd->error_id != BAD_FILE)
	{
		if (cmd->fd_out > 1)
			close(cmd->fd_out);
		file = ms_clean_filename(args[0][*i + 1]);
		cmd->fd_out = ms_opens(cmd, file, ms_is_file_real(file), 0);
		args[0] = ms_remove_filename(args[0], *i);
		*i = *i - 1;
		free(file);
	}
	else if (args[0][*i][0] == '>' && !args[0][*i + 1]
		&& ft_strlen(args[0][*i]) == 1)
		cmd->error_id = BAD_FILE;
	if (cmd->fd_out == -1)
		cmd->error_id = BAD_FILE;
	if (cmd->error_id == BAD_FILE && cmd->fd_out > 1)
		close(cmd->fd_out);
}

static void	ms_inputs_setup(t_cmd *cmd, char ***args, int *i)
{
	// int		i;
	char	*file;

	// i = -1;
	if (args[0][*i][0] == '<' && ft_strlen(args[0][*i]) == 1
		&& args[0][*i + 1] && cmd->error_id != BAD_FILE)
	{
		if (cmd->fd_in > 0)
			close(cmd->fd_in);
		file = ms_clean_filename(args[0][*i + 1]);
		cmd->fd_in = ms_opens(cmd, file, ms_is_file_real(file), -1);
		args[0] = ms_remove_filename(args[0], *i);
		*i = *i - 1;
		free(file);
	}
	else if (args[0][*i][0] == '<' && !args[0][*i + 1]
		&& ft_strlen(args[0][*i]) == 1)
		cmd->error_id = BAD_FILE;
	if (cmd->fd_in == -1)
		cmd->error_id = BAD_FILE;
	if (cmd->error_id == BAD_FILE && cmd->fd_in > 0)
		close(cmd->fd_in);
}

int	ms_head_to_next_symbol(char **args, int prev_index)
{
	int	index;

	index = prev_index;
	// if ((((args[index + 1][0] == '<' || args[index + 1][0] == '>')
	// 	&& ft_strlen(args[index + 1]) == 1)
	// 	|| ((!ft_strncmp(args[index + 1], ">>", 2)
	// 		|| !ft_strncmp(args[index + 1], "<<", 2))
	// 		&& ft_strlen(args[index + 1]) == 1)) && prev_index != 0)
	// 	return (-1);
	while (args && (index  == -1 || (index >= 0 && args[index])) && args[++index])
	{
		printf ("elem: |%s|, index: %d\n", args[index], index);
		if ((((args[index][0] == '<' || args[index][0] == '>')
			&& ft_strlen(args[index]) == 1)
			|| ((!ft_strncmp(args[index], ">>", 2)
				|| !ft_strncmp(args[index], "<<", 2))
				&& ft_strlen(args[index]) == 2))
			&& (index == 0 || (index > 1 && args[index - 1] >= 0)))
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
	
	int i = -1;
	while (cmd->args[++i])
	{
		write(1, " |", 2);
		write(1, cmd->args[i], ft_strlen(cmd->args[i]));
		write(1, "|", 1);
	}
	write(1, "\n", 1);

	index = -1;
	while (cpy_cmd)
	{
		args = cpy_cmd->args;
		index = ms_head_to_next_symbol(args, index);
		printf("index before: %d, |%s|\n", index, args[index + (index == -1)]);
		if (index == -1)
			cpy_cmd = cpy_cmd->next;
		else if (args[index][0] == '>' && ft_strlen(args[index]) == 1)
			ms_redirects_setup(cpy_cmd, &args, &index);
		else if (args[index][0] == '<' && ft_strlen(args[index]) == 1)
			ms_inputs_setup(cpy_cmd, &args, &index);
		else if (!ft_strncmp(args[index], ">>", 2))
			ms_appends_setup(cpy_cmd, &args, &index);
		else if (!ft_strncmp(args[index], "<<", 2) && (args[index + 1]
			&& (args[index + 1][0] == '>' || args[index + 1][0] == '<')))
			cpy_cmd->error_id = BAD_HEREDOC;
		printf("index after: %d\n", index);
		if (cpy_cmd)
		{
			cpy_cmd->args = args;
			
			i = -1;
			write(1, "current line: ", 14);
			while (cpy_cmd->args[++i])
			{
				write(1, " |", 2);
				write(1, cpy_cmd->args[i], ft_strlen(cpy_cmd->args[i]));
				write(1, "|", 1);
			}
			write(1, "\n", 1);
		}


	}
	ms_remove_hiders(cmd, -1);
}
