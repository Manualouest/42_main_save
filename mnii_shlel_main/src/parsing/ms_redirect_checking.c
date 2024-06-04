/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redirect_checking.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:41:06 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/27 15:25:50 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

static char	*ms_get_whole_input(int fd)
{
	char	*input;
	char	*tp_char;
	char	*full_input;

	input = get_next_line(fd);
	full_input = malloc(sizeof(char) * 1);
	full_input[0] = 0;
	while (input)
	{
		tp_char = ft_strjoin(full_input, input);
		free(full_input);
		free(input);
		full_input = ft_strjoin("", tp_char);
		free(tp_char);
		input = get_next_line(fd);
	}
	return (full_input);
}

static void	ms_move_args_front(char **args)
{
	int	i;
	char *tp_char;

	i = -1;
	tp_char = NULL;
	while (args[++i])
	{
		tp_char = args[i + 1];
		free(args[i]);
		args[i] = tp_char;
	}
}

static void	ms_input_handler(t_cmd *cmd)
{
	int		i;
	char	*input;

	i = -1;
	while (cmd->args[++i] && cmd->error_id == NO_ERROR)
	{
		if (ft_strncmp(cmd->args[i], "<", 1) == 0 && cmd->args[i + 1])
		{
			cmd->fd_in = open(cmd->args[i + 1], O_RDONLY);
			if (cmd->fd_in == -1)
				cmd->error_id = BAD_INPUT;
			input = ms_get_whole_input(cmd->fd_in);
			free(cmd->args[i]);
			cmd->args[i] = input;
			ms_move_args_front(&cmd->args[i + 1]);
			if (cmd->fd_in != -1)
				close(cmd->fd_in);
		}
	}
}

void	ms_redirect_handler(t_cmd *cmd)
{
	int	i;

	i = -1;
	ms_input_handler(cmd);
	while (cmd->args[++i])
	{
		if (ft_strncmp(cmd->args[i], ">", 1) == 0 && cmd->args[i + 1])
		{
			if (ft_strncmp(cmd->args[i], ">>", 2) == 0)
			{
				if (cmd->fd_out != -1)
					close(cmd->fd_out);
				cmd->fd_out = open(cmd->args[i + 1], O_APPEND | O_CREAT);
			}
			else
			{
				if (cmd->fd_out != -1)
					close(cmd->fd_out);
				cmd->fd_out = open(cmd->args[i + 1], O_WRONLY | O_CREAT);
			}
		}
	}
	if (cmd->fd_out == -1)
		cmd->fd_out = 1;
}
