/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:48:36 by locharve          #+#    #+#             */
/*   Updated: 2023/08/26 20:13:35 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_var_repeated(int **tab, int var, int i)
{	
}

void	put_case(int **tab, int *var, int *i, int size)
{
	int	same;

	while(i[2] < size)
	{
		same = is_var_repeated(tab, var[i[2]], i[2] - 1);
		if (var[i[2]] < size)
		{
			while (same >= 0)
			{
				var[i[2]]++;
				same = is_var_repeated(tab, var[i[2]], i[2] - 1);
			}
			tab[i[0]][i[2]] = var[i[2]];
		}
		else
		{
			var[i[2]] = 1;
			i[2] = same - 1;
		}
		i[2]++;
	}
	return ; 
}

int	*check_all(int **tab, int **params, int *line, size)
{
	int	*vertical_line;
	int	*error;
	int	i;
	int	j;

	vertical_line = malloc(size * sizeof(int));
	p = malloc(2 * sizeof(int));

	// check_line horizontal : param g et d, line, size
	// check_line vertical : param h et b, line/ptr, size
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			vertical_line[j] = tab[i][j];
			j++;
		}
		check_line(params[0][i], params[1][i], vertical_line, size);
		i++;
	}
	free(vertical_line);
}

void	try_line(int **tab, int **params, int *var, int size)
{
	int	*ptr;
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	while (i[0] < size)
	{
		i[2] = i[1];
		put_case(tab, var, i, size);
		ptr = check_all(tab, params, tab[i[0]], size);
		if (ptr == NULL)
			i++;
		else
		{
			i[1] = i[2];
			//go_backwards(ptr, tab, i);
		}
	}
	return ;
}
