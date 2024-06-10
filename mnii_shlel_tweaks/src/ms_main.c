/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:28:23 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/10 18:06:09 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

// clear; valgrind --show-leak-kinds=all --leak-check=full --suppressions=ms.supp ./minishell

int g_signal = 0;

static char *setup_prompt(char *dir);
static char	*read_term(void);

// void	free_tab(void **tab)
// {
// 	int i;

// 	i = 0;
// 	if (!tab || !tab[i])
// 		return ;
// 	while (tab[i])
// 		free(tab[i++]);
// 	free(tab);
// }

void	error_log(char *msg)
{
	write(STDERR_FILENO, "\033[1;31m", 7);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\033[0m", 4);
}

void	exec_launcher(t_cmd *cmd, char ***ms_env)
{
	t_cmd	*cpy_cmd;

	cpy_cmd = cmd;
	while (cpy_cmd)
	{
		if (strncmp(cpy_cmd->args[0], "cd", 2) == 0)
			builtin_cd(tablen(cpy_cmd->args), cpy_cmd->args, *ms_env);
		if (strncmp(cpy_cmd->args[0], "echo", 4) == 0)
			builtin_echo(cpy_cmd->args);
		if (strncmp(cpy_cmd->args[0], "env", 4) == 0)
			builtin_env(*ms_env);
		if (strncmp(cpy_cmd->args[0], "pwd", 3) == 0)
			builtin_pwd();
		if (strncmp(cpy_cmd->args[0], "exit", 4) == 0)
			builtin_exit(cmd, tablen(cpy_cmd->args), cpy_cmd->args, *ms_env);
		if (strncmp(cpy_cmd->args[0], "unset", 5) == 0)
			builtin_unset(tablen(cpy_cmd->args), cpy_cmd->args, ms_env);
		if (strncmp(cpy_cmd->args[0], "export", 5) == 0)
			builtin_export(tablen(cpy_cmd->args), cpy_cmd->args, ms_env);
		cpy_cmd = cpy_cmd->next;
	}
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
		cmd = ms_tokeniser_main(input, envp);
		exec_launcher(cmd, &ms_env);
		ms_free_cmd(cmd);
		free(input);
		g_signal = 0;
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
	malloc_size += ft_strlen(dir) + ft_strlen("\001\033[1;32m\002") + 1;
	work = malloc(sizeof(char) * malloc_size);
	ft_strlcpy(work, PROMPT_CONST, ft_strlen(PROMPT_CONST) + 1);
	ft_strlcat(work, " \001\033[1;32m\002", malloc_size);
	ft_strlcat(work, dir, malloc_size);
	ft_strlcat(work, PROMPT_USER, malloc_size);
	return (work);
}