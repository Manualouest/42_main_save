/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:28:23 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/21 19:50:03 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

// clear; valgrind --show-leak-kinds=all --leak-check=full --suppressions=ms.supp ./minishell
void	ms_cmd_test_printer(t_cmd *full_line);

int g_signal = 0;

static char *setup_prompt(char *dir);
static char	*read_term(void);

void	error_log(char *msg)
{
	write(STDERR_FILENO, "\033[1;31m", 7);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\033[0m", 4);
}

int	main(int argc, char *argv[], char *envp[])
{
    (void)argc, (void)argv;

	char			**ms_env;
	char			*input;
	t_cmd			*cmd;

	signal(SIGINT, ms_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	input = NULL;
	ms_env = tab_clone(envp);
	while (1)
	{
		input = read_term();
		if (!input)
			break ;
		cmd = ms_tokeniser_main(input, ms_env);
		if (cmd)
		{
			// ms_cmd_test_printer(cmd);
			if (cmd->error_id == NO_ERROR)
				ms_exec(cmd, &ms_env, cmd->next != NULL);
			ms_free_cmd(cmd);
		}
		else
			ms_handle_errors(NULL, -1, MS_FAIL_STRUCT, NULL);
		free(input);
	}
	free_tab((void **)ms_env);
	rl_clear_history();
	return 0;
}

static char *read_term(void)
{
	char	*prompt;
	char	*path;
	char	*input;

	path = getcwd(NULL, 0);
	prompt = setup_prompt(path);
	free(path);
	input = readline(prompt);
	free(prompt);
	add_history(input);
	return (input);
}

static char *setup_prompt(char *dir)
{
	size_t	malloc_size;
	char	*work;

	if (dir == NULL)
		dir = ft_strdup("whree tf are u???");
	malloc_size = ft_strlen(PROMPT_CONST) + ft_strlen(PROMPT_USER);
	malloc_size += ft_strlen(dir) + ft_strlen("\001\033[1;32m\002") + 1;
	work = malloc(sizeof(char) * malloc_size);
	ft_strlcpy(work, PROMPT_CONST, ft_strlen(PROMPT_CONST) + 1);
	ft_strlcat(work, " \001\033[1;32m\002", malloc_size);
	ft_strlcat(work, dir, malloc_size);
	ft_strlcat(work, PROMPT_USER, malloc_size);
	return (work);
}