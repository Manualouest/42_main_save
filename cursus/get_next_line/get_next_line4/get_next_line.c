/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:16 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/18 15:16:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strlcat(char *dest, char *src);
void		*ft_calloc(size_t nmemb, size_t size);
static char	*ft_get_until_n(char *str, int tt_read);
//static int	check_for_end(char *str);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*reading;
	char		*tp_read;
	int			start_chk;
	int			tt_read;
	int			tp_nbytes;

	start_chk = 1;
	tt_read = 0;
	
	if (fd < 1)
		return (NULL);

	reading = ft_calloc(BUFFER_SIZE, 1);
	
	if (save != 0)
	{
		tt_read += ft_strlen_ncheck(save, 0, 0) + 1;
		reading = ft_strlcat(reading, save);
	}
	
	while(start_chk == 1 || ft_strlen_ncheck(reading, tt_read, 1) == -1)
	{
		tp_read = ft_calloc(BUFFER_SIZE, 1);
		tp_nbytes = read(fd, tp_read, BUFFER_SIZE);
		if (tp_nbytes < 1)
		{
			free(tp_read);
			if (start_chk == 1)
			{
				free(save);
				free(reading);
				return (NULL);
			}
			break;
		}
		tt_read += tp_nbytes;
		reading = ft_strlcat(reading, tp_read);
		free(tp_read);
		start_chk = 0;
		if (tp_nbytes < BUFFER_SIZE)
			return(reading);
	}

	if (save)
		free(save);
	if (ft_strlen_ncheck(reading, tt_read, 0) > ft_strlen_ncheck(reading, tt_read, 1) + 1)
		save = ft_strlcat(NULL, &reading[ft_strlen_ncheck(reading, tt_read, 1) + 1]);
	
	// if (save && check_for_end(save) == 0)
	// 	free(save);

	reading = ft_get_until_n(reading, tt_read);
	
	return(reading);
}
/*
static int	check_for_end(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while(str[i] != 0 && str[i] != '\n')
		i ++;
	if ((str[i - 1] == '\n' && str[i] == 0) || (str[i] == '\n' && str[i + 1] == 0))
		return (1);
	return (0);
}
*/
static char	*ft_get_until_n(char *str, int tt_read)
{
	char	*new_str;
	int		nlen;
	int		i;

	i = 0;
	nlen = ft_strlen_ncheck(str, tt_read, 1);
	if (nlen == -1)
		return str;
	new_str = malloc(nlen + 2);
	while (i < nlen)
	{
		new_str[i] = str[i];
		i ++;
	}
	if (str[i] == '\n')
	{
		new_str[i] = str[i];
		i ++;
	}
	new_str[i] = 0;
	free(str);
	return (new_str);
}

char	*ft_strlcat(char *dest, char *src)
{
	int		i;
	int		len;
	char	*tp;

	i = 0;
	len = ft_strlen_ncheck(dest, 0, 0) + ft_strlen_ncheck(src, 0, 0);
	tp = (char *)ft_calloc(len, 1);
	if (dest)
	{
		while (dest[i] != 0)
		{
			tp[i] = dest[i];
			i ++;
		}
		free(dest);
	}
	len = 0;
	while (src[len] != 0)
	{
		tp[i] = src[len];
		i++;
		len ++;
	}
	tp[i] = 0;
	return (tp);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		array = malloc(1);
		((char *)array)[0] = 0;
		if (!array)
			return (NULL);
		return (array);
	}
	if ((nmemb >= 2147483647 || size >= 2147483647
			|| (nmemb * size > 2147483647)))
		return (0);
	array = malloc((size * nmemb) + 1);
	((char *)array)[size * nmemb] = 0;
	if (!array)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)array)[i] = 0;
		i ++;
	}
	return (array);
}


/*
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*test;
	static char	*save;

	fd = open("tests.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	close(fd);
	free(save);
	return (0);
}
*/
