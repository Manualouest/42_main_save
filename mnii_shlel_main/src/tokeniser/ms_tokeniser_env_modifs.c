/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokeniser_env_modifs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:24:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/27 16:56:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

static char	*ms_get_env_content(t_params *prev, t_params *param)
{
	char	*tp_char;
	char	*param_replace;
	int		len;

	len = -1;
	while (param->text[++len] && param->text[len] != ' ')
		;
	tp_char = ft_substr(param->text, 0, len);
	if (len < (int)ft_strlen(param->text))
	{
		param_replace = ft_substr(param->text, len, ft_strlen(param->text));
		free(param->text);
		param->text = param_replace;
		return (tp_char);
	}
	free(param->text);
	prev->next = param->next;
	free(param);
	return (tp_char);
}

static void	ms_replace_env(t_params *param, t_params *next_param,
			t_env_handler	*env)
{
	char	*env_name;
	int		env_len;

	param->type = STRING;
	free(param->text);
	env_name = ms_get_env_content(param, next_param);
	if (env_name[0] != '?' && env_find(env, env_name))
		env_len = ft_strlen(env_find(env, env_name)->info.content) + 1;
	else if (env_name[0] != '?')
		env_len = 0;
	if (env_name[0] != '?' && env_len > 0)
	{
		param->text = malloc(sizeof(char) * env_len);
		ft_strlcpy(param->text, (env_find(env, env_name))->info.content,
			env_len);
	}
	else if (env_name[0] != '?')
		param->text = NULL;
	if (env_name[0] == '?')
		param->text = ft_itoa(g_signal);
	free(env_name);
	param->symbol = NO_SYMBOL;
}

void	ms_make_env_easier(t_params *main_params, char **envp)
{
	t_params		*copy_params;
	t_params		*tp_params;
	t_env_handler	*env;

	env = setup_env_struct(envp);
	copy_params = main_params;
	tp_params = NULL;
	while (copy_params != NULL)
	{
		if (copy_params->symbol == DOLLAR && copy_params->next
			&& copy_params->next->type == STRING
			&& copy_params->next->text)
			ms_replace_env(copy_params, copy_params->next, env);
		copy_params = copy_params->next;
	}
	envclear(&env, free);
}
