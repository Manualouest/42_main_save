/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:37:05 by mbirou            #+#    #+#             */
/*   Updated: 2023/12/13 10:18:50 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_len_str_n(const char *s, int buflen, int chc);
char	*ft_get_until_n(char *str, int free_chc);
char	*ft_strlcat(char *dest, char *src, int free_chc);
void	*ft_calloc(size_t nmemb, size_t size);
char	*redo(char *str, char *new_str);

#endif