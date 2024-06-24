/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:57:30 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/24 14:19:42 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

static char	*ms_get_name(int fd)
{
	char	*name;

	name = ft_calloc(sizeof(char), 11);
	read(fd, name, 10);
	return (name);
}

static char	*ms_gen_filename(void)
{
	char	*name;
	int		fd;
	int		rd_num;

	rd_num = open("/dev/urandom", O_RDONLY);
	if (rd_num == -1)
		return (NULL);
	name = ms_get_name(rd_num);
	fd = access(name, F_OK);
	while (fd != -1)
	{
		free(name);
		name = ms_get_name(rd_num);
		fd = access(name, F_OK);
	}
	close(rd_num);
	return (name);
}

int	ms_cleanup_delimiter(char **old_delimiter)
{
	char	*new_deimiter;
	int		index;

	index = -1;
	while()
}

void	ms_heredoc_loop_innit(t_cmd *cmd, char *delimiter, char *filename,
			char **envp)
{
	char	*input;
	int		do_expand;
	
	do_expand = ms_cleanup_delimiter(&delimiter);
	input = readline(HEREDOC_PROMPT);
	while(input && !(ft_strlen(input) == ft_strlen(delimiter)
			&& !ft_strncmp(input, delimiter, ft_strlen(delimiter))))
	{
		// input = ms_do_heredoc_env(input, envp);
		write(cmd->fd_in, input, ft_strlen(input));
		write(cmd->fd_in, "\n", 1);
		free(input);
		input = readline(HEREDOC_PROMPT);
	}
	if (!input)
	{
		close(cmd->fd_in);
		unlink(filename);
		free(filename);
		ms_handle_errors(cmd, 0, MS_FAIL_HEREDOC, NULL);
		cmd->fd_in = -1;
		return ;
	}
	free(input);
	close(cmd->fd_in);
	cmd->fd_in = open(filename, O_RDONLY);
	(void)envp;
}

char	*ms_do_heredoc(t_cmd *cmd, char *delimiter, char **envp)
{
	char	*filename;
	int		fd;

	filename = ms_gen_filename();
	if (!filename)
		return (NULL);
	fd = open(filename, O_CREAT | O_RDWR, S_IRWXU);
	if (fd == -1)
	{
		free(filename);
		return (NULL);
	}
	if (cmd->fd_in > 0)
		close(cmd->fd_in);
	cmd->fd_in = fd;
	ms_heredoc_loop_innit(cmd, delimiter, filename, envp);
	if (cmd->fd_in == -1)
	{
		free(filename);
		return(NULL);
	}
	return (filename);
}

void	ms_fake_heredoc(t_cmd *cmd, char *delimiter)
{
	char	*input;
	
	input = readline(HEREDOC_PROMPT);
	while(input && !(ft_strlen(input) == ft_strlen(delimiter)
			&& !ft_strncmp(input, delimiter, ft_strlen(delimiter))))
	{
		free(input);
		input = readline(HEREDOC_PROMPT);
	}
	if (!input)
		ms_handle_errors(cmd, 0, MS_FAIL_HEREDOC, NULL);
	else
		free(input);
}

void	ms_launch_heredoc(t_cmd *cmd, char ***args, char **envp, int *index)
{
	// int		i;
	char	*filename;

	filename = NULL;
	if (!ft_strncmp(args[0][*index], "<<", 2) && ft_strlen(args[0][*index]) == 2)
	{
		if (args[0][*index + 1] && args[0][*index + 1][0] != '>'
			&& args[0][*index + 1][0] != '<')
		{
			if (args[0][*index + 2] == 0 && 0 == 1)
				filename = ms_do_heredoc(cmd, args[0][*index + 1], envp);
			else
				ms_fake_heredoc(cmd, args[0][*index + 1]);
			
			int i = -1;
			printf("before: ");
			while (args[0][++i])
				printf("|%s|, ", args[0][i]);
			printf("\n");

			args[0] = ms_remove_filename(args[0], *index);
			
			i = -1;
			printf("after: ");
			while (args[0][++i])
				printf("|%s|, ", args[0][i]);
			printf("\n");

			*index = -1;
		}
		else
			ms_handle_errors(cmd, BAD_FILE, MS_SYNTAX_ERROR, args[0][*index + 1]);
	}
	if (filename)
	{
		unlink(filename);
		free(filename);
	}
}

void	*ms_remove_heredoc(char *filename)
{
	if (!filename)
		return (NULL);
	unlink(filename);
	free(filename);
	return (NULL);
}
