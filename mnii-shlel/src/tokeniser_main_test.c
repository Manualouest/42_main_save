/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser_main_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:08:02 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/27 13:57:19 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

// clear; valgrind --show-leak-kinds=all --leak-check=full --suppressions=ms.supp ./minishell

// echo > test0 >test1 > test2> >test3>test4>test5
// echo > test0 >test1 > test2> >test3>test4>test5 "<he>>hes<<sd>sdf"
// echo > test0 >test1 > test2> ">test3" >test4>test5 "<he>>hes<<sd>sdf"
// echo >test1>test2>test3>>test4 << test5<test6>test7
// echo "$HOME" '$HOME' $HOME "$" " $" "$ " " $ " $""$ $ $?
// echo hi | <'test7' cat
// echo "$PWD" > test1 < test1

void	ms_pipe_test_printer(t_pipes *full_line);
void	ms_cmd_test_printer(t_cmd *full_line, char **envp);

int	g_signal = 0;

void	ms_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
		g_signal = 130;
	}
}

int	main(int argc, char **argv, char **envp)
{
	
	char				*a;
	t_cmd				*full_line;

	// signal(SIGINT, ms_sig_handler);
	// signal(SIGQUIT, SIG_IGN);
	(void)argc;
	(void)argv;
	while (1 == 1)
	{
		a = readline(" what_da_shell $ ");
		if (a && a != NULL)
		{
			full_line = ms_tokeniser_main(a, envp);
			if (full_line)
			{
				if (full_line->error_id == NO_ERROR)
					ms_cmd_test_printer(full_line, envp);
				ms_free_cmd(full_line);
			}
			else
				ms_handle_errors(NULL, -1, MS_FAIL_STRUCT, NULL);
			// ms_pipe_test_printer(full_line);
		}
		else
			break ;
			// exit(0);
		if (a)
			free(a);
		g_signal = 0;
	}
	return (0);
}

void	ms_pipes_test_printer_find_cmd(int cmd)
{
	if (cmd == 0)
		write(1, ": NO_CMD", 8);
	else if (cmd == 1)
		write(1, ": ECHO", 6);
	else if (cmd == 2)
		write(1, ": CD", 4);
	else if (cmd == 3)
		write(1, ": PWD", 5);
	else if (cmd == 4)
		write(1, ": EXPORT", 8);
	else if (cmd == 5)
		write(1, ": UNSET", 7);
	else if (cmd == 6)
		write(1, ": ENV", 5);
	else if (cmd == 7)
		write(1, ": EXIT", 6);
}

void	ms_pipes_test_printer_find_error(int cmd, int cmd_errno)
{
	char	*error_char;

	if (cmd == NO_ERROR && cmd_errno == 0)
		write(1, ": NO_ERROR", 10);
	// else if (cmd == BAD_CMD)
	// 	write(1, ": BAD_CMD", 9);
	else if (cmd == BAD_PIPE)
		write(1, ": BAD_PIPE", 10);
	else if (cmd == BAD_QUOTE)
		write(1, ": BAD_QUOTE", 11);
	else if (cmd == BAD_FILE)
		write(1, ": BAD_FILE", 10);
	// else if (cmd == EMPTY_ARG)
	// 	write(1, ": EMPTY_ARG", 11);
	// else if (cmd == TOO_MANY_ARGUMENT)
	// 	write(1, ": TOO_MANY_ARGUMENT", 19);
	// else if (cmd == BAD_PARAM)
	// 	write(1, ": BAD_PARAM", 11);
	// else if (cmd == BAD_INPUT)
	// 	write(1, ": BAD_INPUT", 11);
	// else if (cmd == BAD_HEREDOC)
	// 	write(1, ": BAD_HEREDOC", 13);
	// else if (cmd == BAD_REDIRECT)
	// 	write(1, ": BAD_REDIRECT", 14);
	// else if (cmd == BAD_APPEND)
	// 	write(1, ": BAD_APPEND", 12);
	else
	{
		error_char = strerror(cmd_errno);
		write(1, error_char, ft_strlen(error_char));
	}
}

void	ms_pipes_test_printer_find_symbol(int symbol)
{
	if (symbol == 0)
		write(1, "NO_SYMBOL", 9);
	else if (symbol == 1)
		write(1, "QUOTE", 5);
	else if (symbol == 2)
		write(1, "DOUBLE_QUOTE", 12);
	else if (symbol == 3)
		write(1, "INPUT", 5);
	else if (symbol == 4)
		write(1, "HEREDOC", 7);
	else if (symbol == 5)
		write(1, "REDIRECT", 8);
	else if (symbol == 6)
		write(1, "APPEND", 6);
	else if (symbol == 7)
		write(1, "DOLLAR", 6);
}

void	ms_test_printer_find_error(int error, int cmd_errno)
{
	char	*error_char;

	if (error == NO_ERROR && cmd_errno == 0)
		write(1, "NO_ERROR\n", 9);
	// else if (error == BAD_CMD)
	// 	write(1, "BAD_CMD\n", 8);
	else if (error == BAD_PIPE)
		write(1, "BAD_PIPE\n", 9);
	else if (error == BAD_QUOTE)
		write(1, "BAD_QUOTE\n", 10);
	else if (error == BAD_FILE)
		write(1, "BAD_FILE\n", 9);
	// else if (error == EMPTY_ARG)
	// 	write(1, "EMPTY_ARG\n", 10);
	// else if (error == TOO_MANY_ARGUMENT)
	// 	write(1, "TOO_MANY_ARGUMENT\n", 18);
	// else if (error == BAD_PARAM)
	// 	write(1, "BAD_PARAM\n", 10);
	// else if (error == BAD_INPUT)
	// 	write(1, "BAD_INPUT\n", 10);
	// else if (error == BAD_HEREDOC)
	// 	write(1, "BAD_HEREDOC\n", 12);
	// else if (error == BAD_REDIRECT)
	// 	write(1, "BAD_REDIRECT\n", 13);
	// else if (error == BAD_APPEND)
	// 	write(1, "BAD_APPEND\n", 11);
	else
	{
		error_char = strerror(cmd_errno);
		write(1, error_char, ft_strlen(error_char));
	}
}

void	ms_pipe_test_printer(t_pipes *full_line)
{
	int			is_done;
	t_params	*tp_params;

	is_done = 0;
	if (full_line->error != NO_ERROR)
	{
		write(1, "Error found: ", 13);
		ms_test_printer_find_error(full_line->error, 0);
		return ;
	}
	while (is_done != 1)
	{
		if (full_line->command == NULL)
			write(1, "command = NULL\n", 15);
		else
		{
			write(1, "command = not NULL\n", 19);
			write(1, &(char){full_line->command->builtins + '0'}, 1);
			ms_pipes_test_printer_find_cmd(full_line->command->builtins);
			write(1, "\n", 1);
			write(1, full_line->command->cmd, ft_strlen(full_line->command->cmd));
			write(1, "\n", 1);
			write(1, &(char){full_line->command->has_option + '0'}, 1);
			write(1, "\n", 1);
			write(1, &(char){full_line->command->error + '0'}, 1);
			write(1, "\n", 1);
			ms_pipes_test_printer_find_error(full_line->command->error, full_line->command->cmd_errno);
			write(1, "\n", 1);
			write(1, "params:", 7);
			if (full_line->command->params)
			{
				write(1, "\n", 1);
				tp_params = full_line->command->params;
				while (tp_params != NULL)
				{
					write(1, "		quote level: ", 15);
					write(1, &(char){tp_params->quote_level + '0'}, 1);
					write(1, "\n", 1);
					write(1, "		type: ", 8);
					if (tp_params->type == 0)
						write(1, "symbol", 6);
					else
						write(1, "STRING", 6);
					write(1, "\n", 1);
					write(1, "		text: |", 9);
					// if (tp_params->type == 1)
					write(1, tp_params->text, ft_strlen(tp_params->text));
					// else
						// write(1, "NULL", 4);
					write(1, "|\n", 2);
					write(1, "		symbol: ", 10);
					ms_pipes_test_printer_find_symbol(tp_params->symbol);
					write(1, "\n", 1);
					write(1, "		________________________\n", 27);
					tp_params = tp_params->next;
				}
			}
			else
				write(1, " NULL\n", 6);
			write(1, "________________________\n", 25);
		}
		if (full_line->right == NULL)
		{
			write(1, "right = NULL\n", 13);
			is_done = 1;
		}
		else
		{
			write(1, "right = pipe\n", 13);
			full_line = full_line->right;
		}
	}
}

void	ms_test_in_file(int fd)
{
	char	*buffer;
	int		len_read;

	buffer = ft_calloc(sizeof(char),  100);
	if (!buffer)
		return ;
	len_read = read(fd, buffer, 99);
	if (!buffer)
		return ;
	write(1, "		found: ", 9);
	write(1, "|", 1);
	write(1, buffer, len_read);
	write(1, "|\n", 2);
	free(buffer);
}

void	ms_test_out_file(int fd)
{
	write(fd, "test1\n", 6);
	write(fd, "test2\n", 6);
}


void	ms_cmd_test_printer(t_cmd *full_line, char **envp)
{
	t_cmd	*cmd;
	int		i;
	// char	*heredoc;

	cmd = full_line;
	(void)envp;
	// heredoc = NULL;
	while (cmd != NULL)
	{

		// heredoc = ms_launch_heredoc(cmd, envp);
		// ms_launch_heredoc(cmd, envp);
		write(1, "____________________________\n\n", 29);
		write(1, "	fd_in: ", 8);
		ft_putnbr_fd(cmd->fd_in, 1);
		write(1, "\n", 1);
		if (cmd->fd_in > 0)
		{
			ms_test_in_file(cmd->fd_in);
			close(cmd->fd_in);
		}
		write(1, "	fd_out: ", 9);
		ft_putnbr_fd(cmd->fd_out, 1);
		write(1, "\n", 1);
		if (cmd->fd_out > 1)
		{

			ms_test_out_file(cmd->fd_out);
			close(cmd->fd_out);
		}
		write(1, "	error", 6);
		ms_pipes_test_printer_find_error(cmd->error_id, 0);
		write(1, "\n", 1);
		write(1, "	line: ", 7);
		// ft_putnbr_fd((long int)cmd->args, 1);
		write(1, " ", 1);
		i = -1;
		while (cmd->args[++i])
		{
			write(1, " |", 2);
			write(1, cmd->args[i], ft_strlen(cmd->args[i]));
			write(1, "|", 1);
		}
		write(1, "\n", 1);
		i = -1;
		int	ii;
		while (cmd->args[++i])
		{
			ii = -1;
			write(1, " |", 2);
			while(cmd->args[i][++ii])
			{
				write(1, "(", 1);
				write(1, &cmd->args[i][ii], 1);
				write(1, ",", 1);
				ft_putnbr(cmd->args[i][ii]);
				write(1, ")", 1);
			}
			write(1, "|", 1);
		}
		write(1, "\n", 1);
		write(1, "	pid: ", 6);
		cmd->pid = 0;
		ft_putnbr_fd(cmd->pid, 1);
		write(1, "\n", 1);
		if (cmd->next == NULL)
			write(1, "____________________________\n\n", 29);

		// heredoc = ms_remove_heredoc(heredoc);
		cmd = cmd->next;
	}
}
