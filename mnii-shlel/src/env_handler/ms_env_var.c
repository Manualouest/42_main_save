/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:07:29 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/24 17:39:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static t_env_str	extract_env_name(char *var);
static void			print_env(t_env_handler *env);

t_env_handler	*setup_env_struct(char **envp)
{
	int				i;
	t_env_str		tmp;
	t_env_handler	*lst;

	i = 0;
	while (envp[i])
	{
		tmp = extract_env_name(envp[i]);
		if (i == 0)
			lst = env_new(tmp);
		else
			envadd_back(&lst, env_new(tmp));
		i++;
	}
	return (lst);
}

static t_env_str	extract_env_name(char *var)
{
	int			i;
	t_env_str	ret;
	char		*work;

	i = -1;
	work = strdup(var);
	while (work[++i])
	{
		if (work[i] != '=')
			continue ;
		work[i] = 0;
		break ;
	}
	ret.name = work;
	ret.content = &work[i + 1];
	return (ret);
}

void	builtin_env(t_env_handler *env)
{
	enviter(env, print_env);
}

static void	print_env(t_env_handler *env)
{
	printf("%s=%s\n", env->info.name, env->info.content);
}
