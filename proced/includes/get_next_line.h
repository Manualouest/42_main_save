/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:10:11 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:11:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>

char	*get_next_line(int fd);
char	*gnl_loop(char *storage, int fd);
int		is_new_line(char *buff);
char	*dup_to_new_line(char *storage);
char	*ft_strcat(char *s1, char *s2, char *array);

#endif
