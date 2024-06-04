/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:03:14 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/27 15:25:55 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <string.h>

# include <mnii_shlel.h>

void	ms_parsing_main(t_pipes *main);
void	ms_cd_pre_parsing(t_command *command);
void	ms_unset_pre_parsing(t_command *command);
void	ms_exit_pre_parsing(t_command *command);

char	*ms_create_proper_file_path(t_command *command);

void	ms_redirect_handler(t_cmd *cmd);

#endif