/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_rush2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:52:31 by glaurich          #+#    #+#             */
/*   Updated: 2023/09/03 16:52:33 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		is_dico_well_parsed(char *str);
char	**get_base_lines(char **ret);
char	**ft_tabint_creation(char **tabint, int size, char *str);
int		are_base_lines_in_dict(char **ret, char **dict, int size_dict);
void	maloc_free_dico(char **dico, int size_dict);
int		ft_lenfile(char *filename);
char	*ft_readfile(int n, char *filename);

int	is_dico_correct(char *dicoline, int size_dict)
{
	char	**base_lines_of_dict;
	char	**dico;

	dico = NULL;
	dico = ft_tabint_creation(dico, size_dict, dicoline);
	base_lines_of_dict = NULL;
	if (is_dico_well_parsed(dicoline) == 1)
	{
		maloc_free_dico(dico, size_dict);
		return (1);
	}
	base_lines_of_dict = malloc(32 * sizeof(char *));
	base_lines_of_dict = get_base_lines(base_lines_of_dict);
	if (are_base_lines_in_dict(base_lines_of_dict, dico, size_dict) == -1)
	{
		maloc_free_dico(base_lines_of_dict, 32);
		maloc_free_dico(dico, size_dict);
		free(dicoline);
		return (1);
	}
	maloc_free_dico(base_lines_of_dict, 32);
	maloc_free_dico(dico, size_dict);
	free(dicoline);
	return (0);
}

int	init_dico(char *filename)
{
	int		n;
	int		i;
	char	*file;

	n = ft_lenfile(filename);
	file = ft_readfile(n,filename);
	file[n] = '\0';
	i = 0;
	n = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			n++;
		i++;
	}
	if (is_dico_correct(file, n) == 0)
		return (0);
	else
		return (1);
}
