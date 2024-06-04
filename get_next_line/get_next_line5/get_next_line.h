/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:13 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/18 19:10:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);
int		ft_len_str_n(const char *s, int buflen, int chc);
char	*ft_get_until_n(char *str, int free_chc);
char	*ft_strlcat(char *dest, char *src, int free_chc);
void	*ft_calloc(size_t nmemb, size_t size);