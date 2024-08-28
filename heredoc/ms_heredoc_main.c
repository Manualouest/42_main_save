/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:57:30 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/27 19:40:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

static char	*ms_gen_filename(void)
{
	char	*name;
	int		fd;
	int		rd_num;

	rd_num = open("/dev/urandom", O_RDONLY);
	if (rd_num == -1)
		return (NULL);
	name = ft_calloc(sizeof(char), 11);
	read(rd_num, name, 10);
	fd = access(name, F_OK);
	while (fd != -1)
	{
		free(name);
		name = ft_calloc(sizeof(char), 11);
		read(rd_num, name, 10);
		fd = access(name, F_OK);
	}
	close(rd_num);
	return (name);
}

void	ms_heredoc_loop_innit(t_cmd *cmd, char *delimiter, char *filename,
			char **envp)
{
	char	*input;
	int		do_expand;

	(void)filename;
	do_expand = ms_should_expand_heredoc(&delimiter);
	input = readline(HEREDOC_PROMPT);
	while (input && !(ft_strlen(input) == ft_strlen(delimiter)
			&& !ft_strncmp(input, delimiter, ft_strlen(delimiter))))
	{
		if (do_expand)
			ms_do_heredoc_env(&input, envp);
		write(cmd->fd_in, input, ft_strlen(input));
		write(cmd->fd_in, "\n", 1);
		free(input);
		input = readline(HEREDOC_PROMPT);
	}
	free(delimiter);
	if (!input)
	{
		close(cmd->fd_in);
		ms_handle_errors(cmd, 0, MS_FAIL_HEREDOC, NULL);
		cmd->fd_in = -1;
		return ;
	}
	free(input);
}

void	ms_do_heredoc(t_cmd *cmd, char *delimiter, char **envp)
{
	char	*filename;
	int		fd;

	filename = ms_gen_filename();
	if (!filename)
		return (ms_handle_errors(cmd, -1, MS_FILE_HEREDOC, NULL));
	fd = open(filename, O_CREAT | O_RDWR, S_IRWXU);
	if (fd == -1)
	{
		free(filename);
		return (ms_handle_errors(cmd, -1, MS_FILE_HEREDOC, NULL));
	}
	if (cmd->fd_in > 0)
		close(cmd->fd_in);
	cmd->fd_in = fd;
	ms_heredoc_loop_innit(cmd, delimiter, filename, envp);
	if (cmd->fd_in != -1)
	{
		close(cmd->fd_in);
		cmd->fd_in = open(filename, O_RDONLY);
	}
	unlink(filename);
	free(filename);
	if (cmd->fd_in == -1 && cmd->error_id <= NO_ERROR)
		ms_handle_errors(cmd, -1, MS_FILE_HEREDOC, NULL);
}

void	ms_launch_heredoc(t_cmd *cmd, char ***args, int *i, char **envp)
{
	if (args[0][*i + 1] && cmd->error_id != BAD_FILE)
	{
		if (args[0][*i + 1][0] != '>' && args[0][*i + 1][0] != '<')
		{
			ms_do_heredoc(cmd, ft_strdup(args[0][*i + 1]), envp);
			args[0] = ms_remove_filename(args[0], *i);
			*i = *i - 1;
		}
		else
			ms_handle_errors(cmd, BAD_FILE, MS_SYNTAX_ERROR, args[0][*i + 1]);
	}
	else
		ms_handle_errors(cmd, BAD_FILE, MS_SYNTAX_ERROR, NULL);
}
