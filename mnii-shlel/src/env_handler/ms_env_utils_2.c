/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:50:26 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/24 17:39:00 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static char	*str_to_envstr_dup(char *info, int sep);

t_env_handler	*env_find(t_env_handler *env, char *name)
{
	if (!env)
		return (NULL);
	if (strcmp(env->info.name, name) != 0)
		return (env_find(env->next, name));
	return (env);
}

t_env_handler	*env_replace(t_env_handler **env, t_env_handler *new,
							t_env_handler *old)
{
	t_env_handler	*tmp;

	tmp = (*env);
	if (old == NULL || new == NULL)
		return (NULL);
	new->next = old->next;
	while (tmp && tmp->next != old)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	tmp->next = new;
	return (tmp);
}

t_env_str	ms_string_to_env(char *info, int sep)
{
	t_env_str	ret;
	char		*work;

	work = str_to_envstr_dup(info, sep);
	work[sep] = 0;
	ret.name = work;
	ret.content = &work[sep + 1];
	return (ret);
}

static char	*str_to_envstr_dup(char *info, int sep)
{
	size_t	i;
	char	*dup;

	i = ft_strlen(info) + 1;
	dup = NULL;
	if (info[sep] == 0)
		return (ft_strdup(info));
	dup = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(dup, info, sep + 1);
	ft_strlcpy(&dup[sep + 1], &info[sep], i - sep);
	return (dup);
}
