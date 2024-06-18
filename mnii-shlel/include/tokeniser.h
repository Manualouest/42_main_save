
#ifndef TOKENISER_H
# define TOKENISER_H

# include <mnii_shlel.h>

// ms_tokeniser_main.c
void		ms_free_cmd(t_cmd *cmd);
t_cmd		*ms_tokeniser_main(char *line, char **envp);

// ms_first_setup.c
int			ms_nb_params(char *line, int index, int *line_index);
int			ms_get_cut_len(char *line, int main_index, int main_index_save,
				int *cut_len);
char		**ms_cut_text(char *line);
void		ms_misc_params_setup(t_cmd *cmd);
void		ms_base_setup(t_cmd *cmd, char *line);

// ms_setup_utils.c
int			ms_go_to_pipe(char *line, int *main_index);
int			ms_is_there_pipe(char *line, int index);
int			ms_change_quote_level(char *line, int index, int old_quote_level);
char		*ms_tripple_join(char *first, char *second, char *third);

// ms_second_setup.c
int			ms_has_dollar(char *arg);
char		*ms_setup_env(char *tp_env, char **arg, int env_start,
				int env_len);
void		ms_do_env(char **arg, char **envp);
void		ms_remove_quotes(t_cmd *cmd, char **arg);
void		ms_setup_round_two(t_cmd *cmd, char **envp);

// ms_redirect_append_setup.c
void		ms_redirect_append_setup(t_cmd *cmd);




#endif