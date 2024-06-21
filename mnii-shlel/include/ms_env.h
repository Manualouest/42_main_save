/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:48:06 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/21 20:15:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ENV_H
# define MS_ENV_H

int		tablen(char **tab);
char	**tab_append(char **tab, char *add, int pos);
void	tab_replace(char **tab, char *old, char *new);
char	**tab_clone(char **tab);
char	*envp_find(char **envp, char *name);
void	free_tab(void **tab);

#endif
