/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:32:12 by mscheman          #+#    #+#             */
/*   Updated: 2024/09/12 11:21:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif


# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_recalloc(char *src, size_t bytes, int iscalloc);
void	ft_freegnl(int fd);
char	*slurp(int fd);

#endif
