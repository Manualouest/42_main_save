/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redirect_checking.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:41:06 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/04 19:20:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

void	ms_move_args_front(char ***args, int i)
{
	while (args[0][i])
	{
		free(args[0][i]);
		args[0][i] = NULL;
		if (args[0][i + 1])
		{
			args[0][i] = malloc(sizeof(char)
					* (ft_strlen(args[0][i + 1]) + 1));
			ft_strlcpy(args[0][i], args[0][i + 1],
				ft_strlen(args[0][i + 1]) + 1);
		}
		else
			args[0][i] = NULL;
		i ++;
	}
}

static void	ms_cleanup(t_cmd *cmd)
{
	int		i;
	int		start;
	int		len;
	char	*tp_char;

	i = -1;
	while (cmd->args[++i])
	{
		if (!ft_strncmp(cmd->args[i], "", 1))
			ms_move_args_front(&cmd->args, i);
		if (cmd->args[i] && cmd->args[i + 1]
			&& (!ft_strncmp(cmd->args[i], "<", 1)
				|| !ft_strncmp(cmd->args[i], "<<", 2)))
		{
			start = -1;
			while (cmd->args[i + 1][++start] && cmd->args[i + 1][start] == ' ')
				;
			len = start - 1;
			while (cmd->args[i + 1][++len] && cmd->args[i + 1][len] != ' ')
				;
			tp_char = ft_substr(cmd->args[i + 1], start, len - 1);
			free(cmd->args[i + 1]);
			cmd->args[i + 1] = tp_char;
		}
	}
}

static void	ms_input_handler(t_cmd *cmd)
{
	int	i;

	i = -1;
	ms_cleanup(cmd);
	while (cmd->args[++i] && cmd->error_id == NO_ERROR)
	{
		if (!ft_strncmp(cmd->args[i], "<", 1)
			&& ft_strncmp(cmd->args[i], "<<", 2) != 0 && cmd->args[i + 1])
		{
			if (cmd->fd_in != -1)
				close(cmd->fd_in);
			cmd->fd_in = open(cmd->args[i + 1], O_RDONLY);
			if (cmd->fd_in == -1)
				cmd->error_id = BAD_INPUT;
			if (cmd->error_id == NO_ERROR)
			{
				ms_move_args_front(&cmd->args, i + 1);
				ms_move_args_front(&cmd->args, i);
			}
			i --;
		}
	}
	if (cmd->fd_in == -1)
		cmd->fd_in = 0;
}

static void	ms_redirect_opener(t_cmd *cmd, int i)
{
	if (ft_strncmp(cmd->args[i], ">>", 2) == 0)
	{
		if (cmd->fd_out != -1)
			close(cmd->fd_out);
		cmd->fd_out = open(cmd->args[i + 1], O_APPEND | O_CREAT | S_IRWXU);
		if (cmd->fd_out == -1)
			cmd->error_id = BAD_APPEND;
	}
	else
	{
		if (cmd->fd_out != -1)
			close(cmd->fd_out);
		cmd->fd_out = open(cmd->args[i + 1], O_WRONLY | O_CREAT | S_IRWXU);
		if (cmd->fd_out == -1)
			cmd->error_id = BAD_REDIRECT;
	}
	if (cmd->error_id == NO_ERROR)
	{
		ms_move_args_front(&cmd->args, i + 1);
		ms_move_args_front(&cmd->args, i);
	}
}

void	ms_redirect_handler(t_cmd *cmd)
{
	int	i;

	i = -1;
	ms_input_handler(cmd);
	while (cmd->args[++i] && cmd->error_id == NO_ERROR)
	{
		if (cmd->args[i][0] &&
			ft_strncmp(cmd->args[i], ">", 1) == 0 && cmd->args[i + 1])
		{
			ms_redirect_opener(cmd, i);
			i --;
		}
	}
	if (cmd->fd_out == -1)
		cmd->fd_out = 1;
}
