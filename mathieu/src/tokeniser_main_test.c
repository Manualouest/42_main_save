/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser_main_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:08:02 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/28 20:25:04 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

// clear; valgrind --show-leak-kinds=all --leak-check=full --suppressions=ms.supp ./minishell
// ls | ls >>./outfiles/outfile >> ./outfiles/outfile2 | cat -e
// echo a$'42$'

void	ms_pipes_test_printer_find_error(int cmd, int cmd_errno)
{
	char	*error_char;

	if (cmd == NO_ERROR && cmd_errno == 0)
		write(1, ": NO_ERROR", 10);
	else if (cmd == BAD_PIPE)
		write(1, ": BAD_PIPE", 10);
	else if (cmd == BAD_QUOTE)
		write(1, ": BAD_QUOTE", 11);
	else if (cmd == BAD_FILE)
		write(1, ": BAD_FILE", 10);
	else
	{
		error_char = strerror(cmd_errno);
		write(1, error_char, ft_strlen(error_char));
	}
}


void	ms_test_printer_find_error(int error, int cmd_errno)
{
	char	*error_char;

	if (error == NO_ERROR && cmd_errno == 0)
		write(1, "NO_ERROR\n", 9);
	else if (error == BAD_PIPE)
		write(1, "BAD_PIPE\n", 9);
	else if (error == BAD_QUOTE)
		write(1, "BAD_QUOTE\n", 10);
	else if (error == BAD_FILE)
		write(1, "BAD_FILE\n", 9);
	else
	{
		error_char = strerror(cmd_errno);
		write(1, error_char, ft_strlen(error_char));
	}
}

void	ms_cmd_test_printer(t_cmd *full_line)
{
	t_cmd	*cmd;
	int		i;
	// char	*heredoc;

	cmd = full_line;
	while (cmd != NULL)
	{

		// heredoc = ms_launch_heredoc(cmd);

		write(1, "____________________________\n\n", 29);
		write(1, "	fd_in: ", 8);
		ft_putnbr_fd(cmd->fd_in, 1);
		write(1, "\n", 1);
		if (cmd->fd_in > 0)
			close(cmd->fd_in);
		write(1, "	fd_out: ", 9);
		ft_putnbr_fd(cmd->fd_out, 1);
		write(1, "\n", 1);
		if (cmd->fd_out > 1)
			close(cmd->fd_out);
		write(1, "	error", 6);
		ms_pipes_test_printer_find_error(cmd->error_id, 0);
		write(1, "\n", 1);
		write(1, "	line: ", 7);
		i = -1;
		while (cmd->args[++i])
		{
			write(1, " |", 2);
			write(1, cmd->args[i], ft_strlen(cmd->args[i]));
			write(1, "|", 1);
		}
		write(1, "\n", 1);
		write(1, "	pid: ", 6);
		cmd->pid = 0;
		ft_putnbr_fd(cmd->pid, 1);
		write(1, "\n", 1);
		if (cmd->next == NULL)
			write(1, "____________________________\n", 29);
		else
			write(1, "\n", 1);

		// ms_remove_heredoc(-1, heredoc);

		cmd = cmd->next;
	}
}
