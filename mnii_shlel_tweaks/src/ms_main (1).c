/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main (1).c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:28:23 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/10 17:08:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

int g_signal = 0;

static char *setup_prompt(void);
static char	*read_term(void);

void	error_log(char *msg)
{
	write(STDERR_FILENO, "\033[1;31m", 7);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "\033[0m", 4);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**ms_env;
	char	*input;
	char	**work;
//	t_cmd	cmd;

    (void)argc, (void)argv;
	signal(SIGINT, ms_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	ms_env = tab_clone(envp);
	while (1)
	{
		input = read_term();
		if (!input)
			break ;
		work = ft_split(input, ' ');
		if (strncmp(work[0], "cd", 2) == 0)
			builtin_cd(tablen(work), work, ms_env);
		if (strncmp(work[0], "echo", 4) == 0)
			builtin_echo(work);
		if (strncmp(work[0], "env", 4) == 0)
			builtin_env(ms_env);
		if (strncmp(work[0], "pwd", 3) == 0)
			builtin_pwd();
		if (strncmp(work[0], "exit", 4) == 0)
			builtin_exit(tablen(work), work, ms_env);
		if (strncmp(work[0], "unset", 5) == 0)
			builtin_unset(tablen(work), work, &ms_env);
		if (strncmp(work[0], "export", 5) == 0)
			builtin_export(tablen(work), work, &ms_env);
		free_tab((void **)work);
//		cmd = ms_tokeniser_main(input, ms_env);
//		ms_exec(cmd, ms_env, cmd->next != NULL);
//		ms_free_cmd(cmd);
		free(input);
		g_signal = 0;
	}
	rl_clear_history();
	free_tab((void **)ms_env);
	return 0;
}

static char *read_term(void)
{
	char	*prompt;
	char	*input;

	prompt = setup_prompt();
	input = readline(prompt);
	free(prompt);
	add_history(input);
	return (input);
}

static char *setup_prompt(void)
{
	size_t	malloc_size;
	char	*work;

	malloc_size = ft_strlen(PROMPT_CONST) + ft_strlen(PROMPT_USER) + 1;
	work = malloc(sizeof(char) * malloc_size);
	ft_strlcpy(work, PROMPT_CONST""PROMPT_USER, malloc_size);
	return (work);
}
