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

int	builtin_env(char **envp);
int	builtin_export(int argc, char **argv, char ***envp);
int	builtin_export_noargs(char **envp);
int	builtin_pwd(void);
int	builtin_unset(char **argv, char ***envp);
int	builtin_exit(t_cmd *cmd, int argc, char **argv, char **envp);
int	builtin_echo(char **argv);
int	builtin_cd(int argc, char **argv, char ***envp);

#endif
