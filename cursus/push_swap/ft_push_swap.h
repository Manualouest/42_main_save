/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:49:57 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/25 19:01:36 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "GNL/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_stack;

typedef struct indexa_vals
{
	int				min_move;
	int				best_index;
	int				index;
	int				indexb_help;
}					t_indexa_vals;


int		sa(t_stack **top, int chc);
int		sb(t_stack **top, int chc);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		fp(t_stack **a, t_stack **b);
int		ra(t_stack **stk, int *index);
int		rb(t_stack **stk, int *index);
int		rra(t_stack **stk, int *index);
int		rrb(t_stack **stk, int *index);
int		frr(t_stack **stk, int *place);
int		fr(t_stack **stk, int *place);
int		f_rr(t_stack **a, t_stack **b);
int		f_ss(t_stack **a, t_stack **b);
int		f_rrr(t_stack **a, t_stack **b);

int		ft_atoi(const char *nptr);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	**ft_split(char const *s, char c, int *nb_subs);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strlcat(char *dest, char *src, int free_chc);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_has_letter(char *str);
int		ft_has_no_double(char **args, int nb_args);

int		ft_stack_maker(char **args, t_stack **a, int nb_args);
char	**ft_stk_mk_util(char **args, int *nb_args);
void	ft_mega_clearer(t_stack *a, t_stack *b, char **argv);


t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);

void	ft_algo(t_stack **a, t_stack **b);
void	ft_do_move(t_stack **a, t_stack **b, int indexa, int indexb);
void	ft_sort_three(t_stack **a);
void	ft_empty_b(t_stack **a, t_stack **b);
void	ft_do_rrr(t_stack **a, t_stack **b, int *indexa, int *indexb);
void	ft_replace_stk(t_stack **stk, int index);

int		ft_is_sorted(t_stack *stk);
int		ft_is_rsorted(t_stack *stk);

int		ft_get_index_a(t_stack **sta, t_stack **stb, int *indexb);
int		ft_get_index_b(t_stack **sta, t_stack **stb);
int		ft_find_index_min(t_stack *stk);
int		ft_find_index_max(t_stack *stk);
int		ft_get_min(t_stack *stk);
int		ft_get_max(t_stack *stk);
int		ft_get_place(t_stack *stk, int num);



#endif