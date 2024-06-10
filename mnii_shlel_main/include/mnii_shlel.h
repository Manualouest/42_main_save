/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnii_shlel.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:32:41 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/27 11:44:42 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNII_SHLEL_H
# define MNII_SHLEL_H

# include <libft.h>
# include <get_next_line_bonus.h>

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <string.h>
# include <curses.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/types.h>
# include <dirent.h>
# include <signal.h>
# include <errno.h>
# include <termios.h>

# include <tokeniser_struct.h>
# include <tokeniser.h>
# include <parsing.h>
# include <ms_env_handler.h>

# include <ms_env_handler.h>
# include <ms_error.h>
# include <ms_execution.h>

extern int g_signal;

# define PROMPT_CONST "\033[1;31mmnii \033[1;35mshlel:"
# define PROMPT_USER " \033[1;36m\n$\033[0;0m  "
# define HEREDOC_PROMPT "\033[1;36mheredco > \033[0;0m"


void	builtin_env(t_env_handler *env);
int		builtin_export(t_env_handler *env, t_env_str *params);
void	builtin_pwd(void);
int		builtin_unset(t_env_handler *env, char **names);
void	builtin_exit(int exit_no);
void	ms_echo(char *params[]);
void	ms_cd(char *param, t_env_handler *env);

void	ms_sig_handler(int sig);

#endif