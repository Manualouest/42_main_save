/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:26:09 by glaurich          #+#    #+#             */
/*   Updated: 2023/09/02 11:26:10 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*parsing_arg_nbr(char *ret, char *str);
int		init_dico(char *filename);
void	*ft_make_input(char *input, char *filename);

char *initfile(char *filename, int argc, char **argv)
{
	if (argc == 2)
	{
		filename = "numbers.dict";
	}
	else
	{
		filename = argv[1];
	}
	return filename;
}
char *initnbr(char *supernbr, int argc, char **argv)
{
	if (argc == 2)
	{
		supernbr = parsing_arg_nbr(supernbr, argv[1]);
	}
	else
	{
		supernbr = parsing_arg_nbr(supernbr, argv[2]);
	}
	return supernbr;
}

int	main(int argc, char **argv)
{
	char	*supernbr;
	char	*filename;

	supernbr = NULL;
	if ((argc == 2 || argc == 3))
	{
		filename = initfile(filename, argc, argv);
		supernbr = initnbr(supernbr, argc, argv);
		if (init_dico(filename) == 0)
			ft_make_input(supernbr,filename);
		else
			write(1, "Dict Error\n", 11);
		free(supernbr);
		
	}
	else
		write(1, "Error\n", 6);
	return 0;
}


