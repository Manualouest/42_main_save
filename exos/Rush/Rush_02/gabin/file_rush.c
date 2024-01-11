/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_rush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:55:06 by glaurich          #+#    #+#             */
/*   Updated: 2023/09/03 16:55:07 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_lenfile(char *filename)
{
	char	a[1000000];
	int		f;
	int		n;

	f = open(filename, O_RDONLY);
	n = read(f, a, 1000000);
	close(f);
	return (n);
}

char	*ft_readfile(int n, char *filename)
{
	char	*file;
	int		f;

	file = malloc((n + 1) * sizeof(char));
	f = open(filename, O_RDONLY);
	read(f, file, n);
	close(f);
	return (file);
}
