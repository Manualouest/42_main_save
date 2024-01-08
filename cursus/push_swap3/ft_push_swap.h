/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:49:57 by mbirou            #+#    #+#             */
/*   Updated: 2023/12/12 22:42:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_stack;

void	debug_printer(t_stack *stk);
void	ft_putnbr_fd(int n, int fd);

int		sa(t_stack **top);
int		sb(t_stack **top);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		ra(t_stack **stk);
int		rb(t_stack **stk);
int		rra(t_stack **stk);
int		rrb(t_stack **stk);

int		ft_atoi(const char *nptr);
void	ft_putnbr(int n);
int		stack_maker(char **args, t_stack **a, int nb_args);
int		ft_has_letter(char *str);
int		ft_has_no_double(char **args, int nb_args);
int		ft_argv_convert(char ***args, char **argv);
char	**ft_split(char const *s, char c, int *nb_subs);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**stack_maker_utils(char **args, int *nb_args);
void	ft_mega_clearer(t_stack *a, t_stack *b, char **argv);

int		ft_len_str_n(const char *s, int chc);
char	*ft_strlcat(char *dest, char *src, int free_chc);
void	*ft_calloc(size_t nmemb, size_t size);

t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);

void	algo(t_stack **a, t_stack **b);
int		find_index_min(t_stack *stk);
int		is_sorted(t_stack *a);
int		is_s_useful(t_stack *stk);

#endif