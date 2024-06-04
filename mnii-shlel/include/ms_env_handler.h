/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:08:02 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/24 17:39:16 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ENV_HANDLER_H
# define MS_ENV_HANDLER_H

typedef int t_bool;

/**
 * @attention The string for name and content must be the same!
 * @example The string of name must be "name\0content\0" and therefore
 * content is just name[strlen(name) + 1]
 */
typedef struct s_env_str
{
	char	*name;
	char	*content;
}			t_env_str;

typedef struct s_env_handler
{
	t_env_str				info;
	struct s_env_handler	*next;
}							t_env_handler;

t_env_handler	*setup_env_struct(char **envp);

t_env_handler	*env_new(t_env_str content);
void			envadd_back(t_env_handler **env, t_env_handler *new);
void			envclear(t_env_handler **env, void (*del)(void *));
void			envdelone(t_env_handler *env, void (*del)(void *));
void			enviter(t_env_handler *env, void (*f)(t_env_handler *));

t_env_str		ms_string_to_env(char *info, int sep);
t_env_handler	*env_find(t_env_handler *env, char *name);
t_env_handler	*env_replace(t_env_handler **env, t_env_handler *new,
							  t_env_handler *old);

#endif
