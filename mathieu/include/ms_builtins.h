/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:29:17 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/10 18:04:41 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

int		builtin_cd(int argc, char **argv, char ***envp);
int		builtin_echo(t_cmd *cmd);
int		builtin_env(t_cmd *cmd, char **envp);
int		builtin_pwd(t_cmd *cmd);
int		builtin_exit(t_cmd *cmd, int argc, char **argv, char **envp);
int		builtin_unset(char **argv, char ***envp);
int		builtin_export(t_cmd *cmd, char ***envp);
char	*envp_find_similar(char **envp, char *name);
void	export_format_str(char *str);
int		builtin_export_noargs(t_cmd *cmd, char **envp);

#endif
