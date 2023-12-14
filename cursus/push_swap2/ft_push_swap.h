/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:49:57 by mbirou            #+#    #+#             */
/*   Updated: 2023/12/02 11:16:19 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	ft_putnbr(int n);

int	s(int **stack);
int	s_check(int *stack);
int	p(int **a, int *len_a, int **b, int *len_b);
int	p_check(int *a, int len_a, int *b, int len_b);
int r(int **stack, int len_stack);
int	r_check(int * stack, int len_stack);
int rr(int **stack, int len_stack);
int	rr_check(int * stack, int len_stack);