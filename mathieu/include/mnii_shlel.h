/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnii_shlel.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:32:41 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/28 15:09:12 by mscheman         ###   ########.fr       */
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
# include <ms_execution.h>
# include <ms_builtins.h>
# include <ms_env.h>

extern int g_signal;

# define RED "\033[1;31m"
# define PRP "\033[1;35m"
# define CYA "\033[1;36m"
# define WHT "\033[0;0m"

# define PROMPT_CONST RED"mnii"PRP"shlel"
# define PROMPT_USER CYA"$ "WHT
# define HEREDOC_PROMPT CYA"mheredco > "WHT

void	error_log(char *msg);
void	ms_sig_handler(int sig);

#endif
