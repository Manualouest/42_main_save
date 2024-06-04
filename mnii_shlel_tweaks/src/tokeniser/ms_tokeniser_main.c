/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokeniser_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:06:19 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/27 17:30:46 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

void	ms_check_pipes_and_quotes(t_pipes	*main);

int	ms_check_for_pipes(char *line)
{
	int	i;
	int	nb_pipes;
	int	quote_level;

	i = -1;
	nb_pipes = 0;
	quote_level = 0;
	while (line[++i])
	{
		if (quote_level == 0 && line[i] == "'"[0])
			quote_level = 1;
		else if (quote_level == 1 && line[i] == "'"[0])
			quote_level = 0;
		else if (quote_level == 0 && line[i] == '"')
			quote_level = 2;
		else if (quote_level == 2 && line[i] == '"')
			quote_level = 0;
		if (quote_level == 0 && line[i] == '|')
			nb_pipes ++;
	}
	return (nb_pipes);
}

void	ms_setup_right_pipe(t_pipes *pipe, int nb_pipes)
{
	if (nb_pipes > 1)
		pipe->right = malloc(sizeof(*pipe));
	else
		pipe->right = NULL;
}

void	ms_init_pipes(t_pipes *main, int nb_pipes)
{
	t_pipes	*temp_pipe;
	t_pipes	*start;
	int		is_first;

	is_first = 1;
	main->right = NULL;
	if (nb_pipes != 0)
	{
		while (nb_pipes > 0)
		{
			if (is_first == 1)
				temp_pipe = malloc(sizeof(*temp_pipe));
			temp_pipe->command = malloc(sizeof(*temp_pipe->command));
			ms_setup_right_pipe(temp_pipe, nb_pipes);
			if (is_first == 1)
			{
				is_first = 0;
				start = temp_pipe;
			}
			temp_pipe->error = NO_ERROR;
			temp_pipe = temp_pipe->right;
			nb_pipes --;
		}
		main->right = start;
	}
}

void	ms_fill_pipes_main(t_pipes *pipes, char *line, char **envp)
{
	int			i;

	i = 0;
	while (pipes != NULL)
	{
		pipes->id = 0;
		pipes->infile = 0;
		pipes->outfile = 0;
		ms_init_cmd(pipes->command, line, &i);
		ms_fill_params(pipes->command, pipes->command->params, line, &i);
		ms_cut_spaces(pipes->command, pipes->command->params);
		ms_make_env_easier(pipes->command->params, envp);
		// trim_redirect_spaces(pipes->command);
		if (ms_am_i_at_the_next_pipe(line, i) == 0)
			ms_head_to_next_pipe(line, &i);
		pipes = pipes->right;
	}
}

t_cmd	*ms_tokeniser_main(char *line, char **envp)
{
	t_pipes	*main;
	t_cmd	*cmd;
	int		nb_pipes;

	main = malloc(sizeof(*main));
	main->command = malloc(sizeof(*main->command));
	main->error = NO_ERROR;
	main->right = NULL;
	nb_pipes = ms_check_for_pipes(line);
	ms_init_pipes(main, nb_pipes);
	ms_fill_pipes_main(main, line, envp);
	ms_parsing_main(main);
	cmd = malloc(sizeof(*cmd));
	ms_translate_to_cmd(cmd, main);
	ms_pipes_free_main(main);
	return (cmd);
}
