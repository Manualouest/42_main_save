/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:22:39 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/27 10:41:21 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

void	cd_rand_gen(t_map_editor *m_edit)
{
	int				i;
	int				ii;
	struct timeval	time;

	gettimeofday(&time, NULL);
	srand(time.tv_sec * 1000 + time.tv_usec / 1000);
	i = -1;
	while (++i < m_edit->m_height)
	{
		ii = -1;
		while (++ii < m_edit->m_width)
			m_edit->map[i][ii] = (rand() % 100 > 60) + '0';
	}
}

int	cd_get_near_count(t_map_editor *m_edit, int x, int y)
{
	int	i;
	int	ii;
	int	count;

	count = 0;
	i = y - 2;
	if (i < -1)
		i = -1;
	while (++i <= y + 1 && i < m_edit->m_height)
	{
		ii = x - 2;
		if (ii < -1)
			ii = -1;
		while (++ii <= x + 1 && ii < m_edit->m_width)
		{
			if (i == m_edit->origin_y && ii == m_edit->origin_y)
				continue ;
			if (!(i == y && ii == x))
				count += m_edit->map[i][ii] - '0';
		}
	}
	return (count);
}

void	cd_rand_turn(t_map_editor *m_edit)
{
	int	count;
	int	i;
	int	ii;

	i = -1;
	while (++i < m_edit->m_height)
	{
		ii = -1;
		while (++ii < m_edit->m_width)
		{
			count = cd_get_near_count(m_edit, ii, i);
			if (i == 0 || ii == 0 || i == m_edit->m_height - 1
				|| ii == m_edit->m_width - 1)
				count += 3;
			if (m_edit->map[i][ii] == '0' && count >= 5)
				m_edit->map[i][ii] = '1';
			if (m_edit->map[i][ii] == '1' && count < 3)
				m_edit->map[i][ii] = '0';
		}
	}
}

void	cd_clean_map(t_map_editor *m_edit)
{
	int	i;

	m_edit->map[m_edit->origin_y][m_edit->origin_x] = m_edit->dir;
	i = -1;
	while (++i < m_edit->m_height)
	{
		m_edit->map[i][0] = '1';
		m_edit->map[i][(int)m_edit->m_width - 1] = '1';
	}
	i = -1;
	while (++i < m_edit->m_width)
	{
		m_edit->map[0][i] = '1';
		m_edit->map[(int)m_edit->m_height - 1][i] = '1';
	}
}
