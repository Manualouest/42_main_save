/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:13 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/09 01:51:04 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_H
# define EXTRAS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*gnl(int fd);
int		gnl_len_str_n(const char *s, int buflen, int chc);
char	*gnl_get_until_n(char *str, int free_chc);
char	*gnl_strlcat(char *dest, char *src, int free_chc);
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_free_readd(char *str, char *new_str);
char	**ft_split(char const *s, char c, int *nb_subs);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);

#endif