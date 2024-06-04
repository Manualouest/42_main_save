/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:08:56 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/24 17:38:49 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static void	export_no_args(t_env_handler *env);
static void	unset_delete(t_env_handler *env, t_env_handler *del);

void	builtin_pwd(void)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (path == NULL)
	{
		i++;
		path = getcwd(NULL, i);
	}
	printf("%s\n", path);
	free(path);
}

int	builtin_export(t_env_handler *env, t_env_str *params)
{
	int				i;
	t_env_handler	*tmp;
	t_env_handler	*dup;

	i = -1;
	if (params == NULL && env != NULL)
	{
		enviter(env, export_no_args);
		return (EXIT_SUCCESS);
	}
	if (!env || !params || !params[0].name)
		return (EXIT_FAILURE);
	while (params[++i].name)
	{
		dup = env_find(env, params[i].name);
		tmp = env_new((t_env_str){params[i].name, params[i].content});
		if (!dup)
			envadd_back(&env, tmp);
		else
		{
			env_replace(&env, tmp, dup);
			envdelone(dup, free);
		}
	}
	return (EXIT_SUCCESS);
}

static void	export_no_args(t_env_handler *env)
{
	printf("declare -x %s=\"%s\"\n", env->info.name, env->info.content);
}

int	builtin_unset(t_env_handler *env, char **names)
{
	int				i;
	t_bool			success;
	t_env_handler	*old;

	i = 0;
	old = NULL;
	success = true;
	if (!names || !*names)
		return (EXIT_FAILURE);
	while (names[i])
	{
		old = env_find(env, names[i]);
		if (!old)
			success = false;
		else
		{
			unset_delete(env, old);
			envdelone(old, free);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	unset_delete(t_env_handler *env, t_env_handler *del)
{
	t_env_handler	*tmp;

	tmp = env;
	while (tmp->next != del)
		tmp = tmp->next;
	tmp->next = del->next;
}
