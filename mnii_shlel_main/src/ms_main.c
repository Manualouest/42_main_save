/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:28:23 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/27 12:18:51 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

int g_signal = 0;

static char *setup_prompt(char *dir);
static char	*read_term(void);

void	free_tab(void **tab)
{
	int i;

	i = 0;
	if (!tab || !tab[i])
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	error_log(char *msg)
{
	write(STDERR_FILENO, "\033[1;31m", 7);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\033[0m", 4);
}

int	main(int argc, char *argv[], char *envp[])
{
    (void)argc, (void)argv;

	t_env_handler	*env;
	char			*input;
	t_cmd			*cmd;

	signal(SIGINT, ms_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	input = NULL;
	env = setup_env_struct(envp);
	while (1)
	{
		input = read_term();
		if (!input)
			break ;
		cmd = ms_tokeniser_main(input, envp);
		ms_exec(cmd, envp, env_find(env, "PATH"));
		ms_free_cmd(cmd);
		free(input);
		g_signal = 0;
	}
	builtin_export(env, NULL);
	envclear(&env, free);
	rl_clear_history();
	return 0;
}

static char *read_term(void)
{
	char	*prompt;
	char	*path;
	char	*input;

	path = getcwd(NULL, 64);
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
	malloc_size += ft_strlen(dir) + ft_strlen("\033[1;32m") + 1;
	work = malloc(sizeof(char) * malloc_size);
	ft_strlcpy(work, PROMPT_CONST, ft_strlen(PROMPT_CONST) + 1);
	ft_strlcat(work, " \033[1;32m", malloc_size);
	ft_strlcat(work, dir, malloc_size);
	ft_strlcat(work, PROMPT_USER, malloc_size);
	return (work);
}