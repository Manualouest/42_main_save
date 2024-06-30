/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:07:08 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/27 21:37:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENISER_H
# define TOKENISER_H

# include <mnii_shlel.h>


void		ms_test_in_file(int fd);





// ms_tokeniser_main.c
void		*ms_free_cmd(t_cmd *cmd);
t_cmd		*ms_tokeniser_main(char *line, char **envp);

// ms_first_setup.c
int			ms_nb_params(char *line, int index, int *line_index);
int			ms_get_cut_len(char *line, int main_index, int main_index_save,
				int *cut_len);
char		**ms_cut_text(char *line);
void		ms_base_setup(t_cmd *cmd, char *line);

// ms_setup_utils.c
int			ms_go_to_pipe(char *line, int *main_index);
int			ms_is_there_pipe(char *line, int index);
int			ms_change_quote_level(char *line, int index, int old_quote_level);
char		*ms_tripple_join(char *first, char *second, char *third,
				int frees);
char		**ms_remove_empty_chars(char **args);

// ms_env_checking.c
int			ms_has_dollar(char *arg);

// ms_second_setup.c
void		ms_remove_hiders(t_cmd *cmd, int arg_i);
void		ms_setup_round_two(t_cmd *cmd, char **envp);

// ms_in_out_file_setup.c
void		ms_in_out_files_setup(t_cmd *cmd, char **envp);

// ms_file_setup_utils.c
int			ms_is_file_real(char *filename);
char		**ms_remove_filename(char **args, int elem_index);
int			ms_opens(t_cmd *cmd, char *filename, int is_created, int kind);
void		ms_handle_errors(t_cmd *cmd, int error_id, char *error,
				char *token);
char		*ms_clean_filename(char	*old_name);

// ms_string_cleaning.c
void		ms_separate_symbols_base(t_cmd *cmd);
void		ms_quote_hider(t_cmd *cmd, char **arg);
void		ms_hide_quotes(t_cmd *cmd);
void		ms_remove_hiders(t_cmd *cmd, int arg_i);

// ms_heredoc_main.c
int			ms_should_expand_heredoc(char **delimiter);
void		ms_launch_heredoc(t_cmd *cmd, char ***args,	int *i, char **envp);
// void		*ms_remove_heredoc(char *filename);

#endif