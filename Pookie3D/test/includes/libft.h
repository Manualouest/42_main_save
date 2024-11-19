/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:38 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/14 17:11:38 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ft_printf.h>
# include <get_next_line.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*=================== MANDATORY PART ===================*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *str, int value, size_t num);
void				*ft_bzero(void *str, size_t num);
void				*ft_memcpy(void *dest, const void *src, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strstr(const char *big, const char *little);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
char				**ft_split(char const *s, char sep);
int					ft_count_word(char const *s, char sep);
void				ft_free_2d_array(void *array, size_t size);
int					ft_atoi_base(char *base, char *to_convert);
int					ft_abs(int to_check);
size_t				ft_array_len(void *array);
char				*ft_unsplit(char **tab_to_unsplit, char sep);
char				*join_and_free(char *s1, char *s2, int f_s1, int f_s2);
void				ft_multi_free(int n_to_free, ...);
char				*ft_multi_join(int n_to_free, char *join_to, ...);
int					ft_strcmp(char *s1, char *s2);
int					try_close(int fd);
void				try_free(void *ptr);
int					ft_strcmp(char *s1, char *s2);

/*=================== BONUS PART ===================*/
/*=========BONUS STRUCT=========*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*=========BONUS PROTOTYPE=========*/
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
