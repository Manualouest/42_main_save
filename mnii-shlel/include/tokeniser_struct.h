/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:07:16 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/27 16:28:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENISER_STRUCT_H
# define TOKENISER_STRUCT_H

# define MS_TOO_MUCH_ARG "too much arguments when executing minishell"
# define MS_FAIL_STRUCT "failed to create malloc minishell's struct"
# define MS_NO_END_QUOTE "there's a quote unclosed"
# define MS_SYNTAX_ERROR "syntax error near unexpected token"
# define MS_MALLOC_ERROR "failed to use malloc()"
# define MS_AMBIGOUS_REDIR "ambiguous redirect"
# define MS_PIPE_ERROR "failed to create a pipe"
# define MS_FORK_ERROR "failed to use fork()"
# define MS_NO_CMD "command not found"
# define MS_DUP_ERROR "failed to use dup2()"
# define MS_NOT_VALID_ID "not a valid identifier"
# define MS_TOO_MANY_ARGS "too many arguments"
# define MS_NUM_ARG_REQUIRED "numeric argument required"
# define MS_FAIL_HEREDOC "here-document delimited by end-of-file"
# define MS_FILE_HEREDOC "failed to create temporary file for heredoc"

typedef enum e_type
{
	SYMBOL,
	STRING
}	t_type;

typedef enum e_builtins
{
	NO_CMD,
	ECHO_BLT,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
}	t_builtins;

typedef enum e_symbols
{
	NO_SYMBOL,
	QUOTE,
	DOUBLE_QUOTE,
	INPUT,
	HEREDOC,
	REDIRECT,
	APPEND,
	DOLLAR
}	t_symbols;

typedef enum e_cmd_errors
{
	NO_ERROR,
	BAD_PIPE,
	BAD_QUOTE,
	BAD_FILE,
	BAD_HEREDOC
}	t_cmd_errors;

typedef struct s_pipes
{
	struct s_command	*command;
	struct s_pipes		*right;
	int					id;
	int					infile;
	int					outfile;
	t_cmd_errors		error;
}						t_pipes;

typedef struct s_command
{
	t_builtins		builtins;
	char			*cmd;
	int				has_option;
	struct s_params	*params;
	t_cmd_errors	error;
	int				cmd_errno;
}					t_command;

typedef struct s_params
{
	t_type			type;
	char			*text;
	t_symbols		symbol;
	int				quote_level;
	struct s_params	*next;
}				t_params;

typedef struct s_cmd
{
	int				fd_in;
	int				fd_out;
	t_cmd_errors	error_id;
	char			**args;
	pid_t			pid;
	struct s_cmd	*next;
	struct s_cmd	*first;
}					t_cmd;

#endif