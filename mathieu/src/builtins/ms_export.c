/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:06:15 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/10 17:53:40 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static int	check_args(const char *input);
static bool	is_valid_char(const char *c);
static void	select_action(char ***envp, char *to_add);
static void	make_action(char ***envp, char *to_add, int mode);

int	builtin_export(t_cmd *cmd, char ***envp)
{
	int		i;
	int		ret;
	char	**args;

	i = 0;
	ret = 0;
	args = cmd->args;
	if (tablen(cmd->args) == 1)
	{
		builtin_export_noargs(cmd, *envp);
		return (EXIT_SUCCESS);
	}
	while (args[++i])
	{
		if (!ft_strncmp("_=", args[i], 2) || !ft_strncmp("_", args[i], 2))
			continue ;
		if (check_args(args[i]))
		{
			ret++;
			error_log("cannot export this variable", '\n');
			continue ;
		}
		select_action(envp, args[i]);
	}
	return (ret);
}

static int	check_args(const char *input)
{
	int	i;

	i = 1;
	if (!input[0])
		return (EXIT_FAILURE);
	if (input[0] != '_' && !ft_isalpha(input[0]))
		return (EXIT_FAILURE);
	while (input[i] && input[i] != '=')
	{
		if (!is_valid_char(&input[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static bool	is_valid_char(const char *c)
{
	if (ft_isalnum(*c) || (*c) == '_' || (*c) == '=')
		return (true);
	if ((*c) == '+' && c[1] == '=')
		return (true);
	return (false);
}

#define ENV_SET 0
#define ENV_CAT 1

static void	select_action(char ***envp, char *to_add)
{
	int		mode;
	char	*tmp;
	char	*similar;

	tmp = ft_strchr(to_add, '=');
	similar =  envp_find_similar(*envp, to_add);
	if (!tmp && similar)
		return ;
	if (tmp && tmp[-1] == '+'
		&& ft_strfind(similar, '=') != -1)
		mode = ENV_CAT;
	else
		mode = ENV_SET;
	make_action(envp, to_add, mode);
}

static void	make_action(char ***envp, char *to_add, int mode)
{
	char	*old;
	char	*tmp;
	char	*similar;

	similar = envp_find_similar(*envp, to_add);
	if (mode == ENV_CAT)
	{
		old = similar;
		tmp = &to_add[ft_strfind(to_add, '=') + 1];
		tab_replace(*envp, old, ft_strjoin(old, tmp));
		return ;
	}
	to_add = ft_strdup(to_add);
	if (ft_strfind(to_add, '=') == -1 && similar)
		return ;
	export_format_str(to_add);
	if (similar)
		tab_replace(*envp, similar, to_add);
	else
		(*envp) = tab_append(*envp, to_add, -1);
}