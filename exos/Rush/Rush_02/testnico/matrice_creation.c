/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:56:04 by nberduck          #+#    #+#             */
/*   Updated: 2023/09/03 08:27:29 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct lignes{
	char *nl;
	char *strl;
};

char *ft_set_val(char *str,int s, int e)
{
	int	i;
	int	j;
	char *tab;
	tab = (char *)malloc((e-s+2) * sizeof(struct lignes));
	if(tab != NULL)
	{
		i = s;
		j = 0;
		while (i <= e)
		{
			tab[j] = str[i];
			i++;
			j++;
		}
		tab[i] = '\0';
	}
	else
		return (NULL);
	return (tab);
}

void ft_struct_creation(int nb, char *str)
{
	//////////
	//char *tab;
	//tab = (char *)malloc(nb * sizeof(struct lignes));
	//////////
	struct lignes *l;//struct pour stocker les lignes
	int	i;//pour se balader dans str
	int	j;//permet de prendre les caracteres a partir de l emplacemet j
	int	s;//permet d ecrire a partir du debut de ligne
	int	v;//se balader dans ligne
	int	n;//var pour des condi
	int	m;//stock le debut de la chaine que l on souhaite
	int	a;//coute le nb de la ligne actuelle
	char *line;//une ligne
	l = malloc((nb-1)*sizeof(struct lignes));

	j = 0;
	a = -1;
	i = 0;
	while (str[i])
	{
		//Trouves la ligne
		if (str[i] == '\n')
		{
			//Met la ligne dans la var line
			a++;
			s = 0;
			line = (char *)malloc((i - j + 2) * sizeof(char));
			while (j <= i)
				line[s++] = str[j++];
			line[s] = '\0';
			v = 0;
			n = 0;
			//Trouve les differentes chaines dans line
			while (line[v])
			{
				while (line[v] == ' ' && n == 0)
					v++;
				if ((line[v] >= '0' && line[v] <= '9'))
				{
					if (n == 0)
						m = v;
					n = 1;
				}
				if ((line[v] == ' ' || line[v] == ':') && n == 1)
				{
					//Met le chiffre trouve dans la struct(de 'm' a 'v')
					l[a].nl = ft_set_val(line, m, v-1);
					n = 2;
					printf("%s,\n", l[a].nl);
					v++;
					//Skip les espaces et ':' en brut
					while (line[v] == ' ')
						v++;
					if (line[v] == ':')
					{
						v++;
						while (line[v] == ' ')
							v++;
					}
					m = v;
				}
				if (line[v] == '\n' && n == 2)
				{
					//Met l ecriture trouve dans la struct
					l[a].strl = ft_set_val(line, m, v);
					printf("%s", l[a].strl);
				}
				v++;
			}
			free(line);
			j = i + 1;
		}
		i++;
	}
	nb--;
	free(l);
	while(nb >= 0)
	{
		free(l[nb].strl);
		free(l[nb].nl);
		nb--;
	}
}

int	ft_head(char *str,int n)
{
	ft_struct_creation(n,str);
	return (0);
}
