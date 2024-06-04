#ifndef MNII_SHLEL_H
# define MNII_SHLEL_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <string.h>
# include <curses.h>
# include <stdio.h>
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

# define HEREDOC_PROMPT "\033[1;36mheredco > \033[0;0m"

extern int g_signal;

# include <libft.h>
# include <get_next_line_bonus.h>
# include <ft_printf.h>

# include <tokeniser_struct.h>
# include <tokeniser.h>
# include <parsing.h>
# include <ms_env_handler.h>

#endif