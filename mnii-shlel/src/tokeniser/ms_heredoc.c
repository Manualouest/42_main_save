/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:43:44 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/01 19:49:52 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

static char	*ms_gen_filename(void)
{
	char	*name;
	int		fd;
	int		len;

	name = ft_calloc(sizeof(char), 2);
	name[0] = '0';
	len = 0;
	fd = access(name, F_OK);
	while (fd != -1 && len < 255)
	{
		if (len == 0 && name[len] + 1 > '9')
		{
			len = ft_strlen(name) + 1;
			free(name);
			name = ft_calloc(sizeof(char), (len + 1));
			while (--len >= 0)
				name[len] = '0';
		}
		if (++name[len] > '9' && --len >= 0)
		{
			name[len]++;
			while (name[++len])
				name[len] = '0';
			len --;
		}
		fd = access(name, F_OK);
	}
	if (fd != -1)
	{
		free(name);
		return (NULL);
	}
	return (name);
}

char	*ms_heredoc(char *limiter, t_cmd *cmd, int fake)
{
	int		fd;
	char	*filename;
	char	*input;

	input = readline(HEREDOC_PROMPT);
	filename = ms_gen_filename();
	fd = open(filename, S_IRWXU | O_RDWR | O_APPEND | O_CREAT);
	if (fd == -1)
		return (NULL);
	while (input && (ft_strlen(limiter) != ft_strlen(input)
			|| (ft_strncmp(input, limiter, ft_strlen(input)) != 0)))
	{
		if (!fake)
		{
			write(fd, input, ft_strlen(input));
			write(fd, "\n", 1);
		}
		input = readline(HEREDOC_PROMPT);
	}
	if (cmd->fd_in == 0)
		cmd->fd_in = fd;
	if (cmd->fd_in != 0 || fake)
		close(fd);
	free(input);
	return (filename);
}


char	*ms_launch_heredoc(t_cmd *cmd)
{
	char	*filename;
	int		i;

	i = -1;
	filename = NULL;
	while (cmd->args[++i])
	{
		if (!ft_strncmp(cmd->args[i], "<<", 2))
		{
			if (filename)
				ms_remove_heredoc(-1, filename);
			if (cmd->args[i + 1] || !cmd->args[i + 2])
			{
				filename = ms_heredoc(cmd->args[i + 1], cmd, 0);
				ms_move_args_front(&cmd->args, i + 1);
				ms_move_args_front(&cmd->args, i);
			}
			else if (cmd->args[i + 1])
				filename = ms_heredoc(cmd->args[i + 1], cmd, 1);
			else
				return (NULL);
		}
	}
	return (filename);
}

void	ms_remove_heredoc(int fd, char *filename)
{
	if (fd != -1)
		close(fd);
	if (filename)
		unlink(filename);
	free(filename);
	filename = NULL;
}