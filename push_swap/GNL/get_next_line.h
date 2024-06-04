/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:13 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/24 20:06:52 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_len_str_n_gnl(const char *s, int buflen, int chc);
char	*ft_get_until_n(char *str, int free_chc);
char	*ft_strlcat_gnl(char *dest, char *src, int free_chc);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
char	*ft_free_readd(char *str, char *new_str);
char	*add_a_read(int fd, char *current_line, int *read_chk);

#endif