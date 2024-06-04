
#ifndef TOKENISER_H
# define TOKENISER_H

# include <mnii_shlel.h>

// ms_tokeniser_main.c
t_pipes	*ms_tokeniser_main(char *line);

// ms_tokeniser_cmd.c
void	ms_init_cmd(t_command *command, char *line, int *i);
char	*ms_get_next_item(char *line, int *main_index);

// ms_tokeniser_params.c
void	ms_fill_params(t_command *cmd, t_params *params, char *line, int *i);

// ms_tokeniser_utils.c
void	ms_head_to_next_pipe(char *line, int *main_index);
int		ms_is_line_done(char *line, int i, char *item);
int		ms_am_i_at_the_next_pipe(char *line, int i);
int		ms_is_symbol(char c);

// ms_tokeniser_free.c
void	ms_pipes_free_main(t_pipes *pipes);

// ms_tokeniser_env_modifs.c
void	ms_make_env_easier(t_params *main_params);

#endif