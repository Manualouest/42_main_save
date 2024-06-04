/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:56:56 by mscheman          #+#    #+#             */
/*   Updated: 2024/04/26 13:56:47 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

t_env_handler	*env_new(t_env_str content)
{
	t_env_handler	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	node->info = content;
	node->next = 0;
	return (node);
}

void	envadd_back(t_env_handler **env, t_env_handler *new)
{
	if ((*env) == NULL)
	{
		(*env) = new;
		return ;
	}
	if (new == NULL)
		return ;
	if ((*env)->next == NULL)
	{
		(*env)->next = new;
		return ;
	}
	envadd_back(&(*env)->next, new);
}

void	envclear(t_env_handler **env, void (*del)(void *))
{
	if (!env || !(*env) || !del)
		return ;
	if ((*env)->next)
		envclear((&(*env)->next), del);
	del((*env)->info.name);
	free(*env);
	*env = NULL;
}

void	envdelone(t_env_handler *env, void (*del)(void *))
{
	if (!env || !del)
		return ;
	del(env->info.name);
	free(env);
	env = NULL;
}

void	enviter(t_env_handler *env, void (*f)(t_env_handler *))
{
	if (env == NULL)
		return ;
	f(env);
	if (env->next != NULL)
		enviter(env->next, f);
}
