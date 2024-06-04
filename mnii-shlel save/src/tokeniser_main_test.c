/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser_main_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:08:02 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/17 19:06:47 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

void	ms_pipe_test_printer(t_pipes *full_line);

int	main()
{
	
	char	*a;
	char	*path;
	int		size;
	t_pipes	*full_line;

	size = 2147483647;
	path = malloc(sizeof(char) * size);
	path = getcwd(path, size);
	if (!path)
	{
		write(1, "path is too long\n", 17);
		exit(0);
	}
	write(1, "~", 1);
	write(1, path, ft_strlen(path));
	
	a = readline(" what_da_shell $ ");
	
	// a = malloc(sizeof(char) * 5);
	// a[0] = 'e';
	// a[1] = 'c';
	// a[2] = 'h';
	// a[3] = 'o';
	// a[4] = 0;

	if (a && a != NULL)
	{
		full_line = ms_tokeniser_main(a);
		ms_pipe_test_printer(full_line);
		ms_pipes_free_main(full_line);
	}
	free(path);
	free(a);
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
	else if (cmd == BAD_CMD)
		write(1, ": BAD_CMD", 9);
	else if (cmd == BAD_PIPE)
		write(1, ": BAD_PIPE", 10);
	else if (cmd == BAD_QUOTE)
		write(1, ": BAD_QUOTE", 11);
	else if (cmd == EMPTY_ARG)
		write(1, ": EMPTY_ARG", 11);
	else if (cmd == TOO_MANY_ARGUMENT)
		write(1, ": TOO_MANY_ARGUMENT", 19);
	else if (cmd == BAD_PARAM)
		write(1, ": BAD_PARAM", 11);
	else if (cmd == BAD_INPUT)
		write(1, ": BAD_INPUT", 11);
	else if (cmd == BAD_HEREDOC)
		write(1, ": BAD_HEREDOC", 13);
	else if (cmd == BAD_REDIRECT)
		write(1, ": BAD_REDIRECT", 14);
	else if (cmd == BAD_APPEND)
		write(1, ": BAD_APPEND", 12);
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
	else if (error == BAD_CMD)
		write(1, "BAD_CMD\n", 8);
	else if (error == BAD_PIPE)
		write(1, "BAD_PIPE\n", 9);
	else if (error == BAD_QUOTE)
		write(1, "BAD_QUOTE\n", 10);
	else if (error == EMPTY_ARG)
		write(1, "EMPTY_ARG\n", 10);
	else if (error == TOO_MANY_ARGUMENT)
		write(1, "TOO_MANY_ARGUMENT\n", 18);
	else if (error == BAD_PARAM)
		write(1, "BAD_PARAM\n", 10);
	else if (error == BAD_INPUT)
		write(1, "BAD_INPUT\n", 10);
	else if (error == BAD_HEREDOC)
		write(1, "BAD_HEREDOC\n", 12);
	else if (error == BAD_REDIRECT)
		write(1, "BAD_REDIRECT\n", 13);
	else if (error == BAD_APPEND)
		write(1, "BAD_APPEND\n", 11);
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
					if (tp_params->type == 1)
						write(1, tp_params->text, ft_strlen(tp_params->text));
					else
						write(1, "NULL", 4);
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
