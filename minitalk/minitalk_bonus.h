/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:53:46 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/04 13:51:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct bit_info
{
	int				bits;
	int				car;
	char			*str;
	int				is_start;
}					t_bit_info;

int		ft_has_letter(char *str);
int		ft_atoi(const char *nptr);
int		ft_send_error(int check1, int check2);
void	ft_putnbr(int n);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char s2);

#endif