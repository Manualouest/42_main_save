/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:29:17 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/01 17:29:17 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

int	builtin_env(char **envp);
int	builtin_export(int argc, char **argv, char ***envp);
int	builtin_export_noargs(char **envp);
int	builtin_pwd(void);
int	builtin_unset(int argc, char **argv, char ***envp);
int	builtin_exit(int argc, char **argv, char **envp);
int	builtin_echo(char **argv);
int	builtin_cd(int argc, char **argv, char **envp);

#endif
