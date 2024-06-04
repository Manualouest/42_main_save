/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:30:44 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/18 18:30:44 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

t_cmd	*cmd_new(char **content)
{
	t_cmd	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	node->args = content;
	node->next = 0;
	return (node);
}

void	cmd_add_back(t_cmd **cmd, t_cmd *new)
{
	if ((*cmd) == NULL)
	{
		(*cmd) = new;
		return ;
	}
	if (new == NULL)
		return ;
	if ((*cmd)->next == NULL)
	{
		(*cmd)->next = new;
		return ;
	}
	cmd_add_back(&(*cmd)->next, new);
}

void	cmd_clear(t_cmd **cmd, void (*del)(void **))
{
	if (!cmd || !(*cmd) || !del)
		return ;
	if ((*cmd)->next)
		cmd_clear((&(*cmd)->next), del);
	del((void **)(*cmd)->args);
	free(*cmd);
	*cmd = NULL;
}

void	cmd_iter(t_cmd *cmd, void (*f)(t_cmd *))
{
	if (!cmd)
		return ;
	f(cmd);
	cmd_iter(cmd->next, f);
}

char	**ms_format_envp(t_env_handler *env)
{
	t_env_handler	*tmp;
	size_t			size;
	char			**tab;
	int				i;

	tmp = env;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tab = ft_calloc(i + 1, sizeof(char *));
	tmp = env;
	while (tmp)
	{
		size = ft_strlen(tmp->info.name) + ft_strlen(tmp->info.content) + 2;
		tab[i - 1] = ft_calloc(size, sizeof(char));
		ft_strlcpy(tab[i - 1], tmp->info.name, ft_strlen(tmp->info.name) + 1);
		ft_strlcat(tab[i - 1], "=", ft_strlen(tab[i - 1]) + 2);
		ft_strlcat(tab[i - 1], tmp->info.content, size);
		tmp = tmp->next;
		i--;
	}
	return (tab);
}
