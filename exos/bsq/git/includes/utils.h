/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:13:15 by mscheman          #+#    #+#             */
/*   Updated: 2023/09/05 14:13:17 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

int		get_min(int a, int b, int c);
void	free_work_map(char **work_map, int l_size);
void	find_largest_square(char **map, int l_size, int c_size);
void	ft_map_printer(char **map, char *charset, int l_line, int c_line);
char	**ft_readmap(char *filename);
char	**ft_find_params_only(char *filename);
char	*ft_get_params(char *map, int nb_line);
char	*ft_itostr(int nb);
int		ft_count_lines(char *file);
int		ft_check_linenb_param(char *map, int nb_line, int last_pos);
int		ft_get_line_len(char *map, int nb_line);
int		ft_find_start_index(char *map);
int		ft_atoi(char *str);

typedef struct s_coord
{
	int	pos;
	int	x;
	int	y;
}	t_coord;

#endif
