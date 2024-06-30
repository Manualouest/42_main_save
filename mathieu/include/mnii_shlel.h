/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnii_shlel.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:32:41 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/27 17:28:04 by mbirou           ###   ########.fr       */
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
# include <limits.h>
# include <stdint.h>

# include <tokeniser_struct.h>
# include <ms_env.h>
# include <tokeniser.h>
# include <parsing.h>

# include <ms_builtins.h>
# include <ms_execution.h>

extern int g_signal;

# define PROMPT_CONST "\001\033[1;31m\002mnii \001\033[1;35m\002shlel:"
# define PROMPT_USER " \001\033[1;36m\002$\001\033[0;0m\002  "
# define HEREDOC_PROMPT "\001\033[1;36m\002heredco > \001\033[0;0m\002"

void	error_log(char *msg, char last_char);
void	ms_sig_handler(int sig);

#endif
