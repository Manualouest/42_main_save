#ifndef TOKENISER_STRUCT_H
# define TOKENISER_STRUCT_H

typedef enum e_type
{
	SYMBOL,
	STRING
}	t_type;

typedef enum e_cmd
{
	NO_CMD,
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
}	t_cmd;

typedef enum e_symbols
{
	NO_SYMBOL,
	QUOTE,
	DOUBLE_QUOTE,
	INPUT,// <
	HEREDOC,// <<
	REDIRECT,// >
	APPEND,// >>
	DOLLAR
}	t_symbols;

typedef enum e_cmd_errors
{
	NO_ERROR,
	BAD_CMD,
	BAD_PIPE,
	BAD_QUOTE,
	EMPTY_ARG,
	TOO_MANY_ARGUMENT,
	BAD_PARAM,
	BAD_INPUT,
	BAD_HEREDOC,
	BAD_REDIRECT,
	BAD_APPEND
}	t_cmd_errors;

typedef	struct	s_pipes
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
	t_cmd			builtins;
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

#endif