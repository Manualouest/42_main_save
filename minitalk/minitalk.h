/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:53:46 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/20 20:55:30 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct bit_info
{
	int				bits;
	int				caracter;
	char			*string;
	int				is_start;
}					t_bit_info;

int		ft_has_letter(char *str);
int		ft_atoi(const char *nptr);
int		ft_send_error(int check1, int check2);
void	ft_putnbr(int n);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char s2);

#endif