/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:52:16 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/12/14 01:34:30 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIBFT/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	if (lst->next == NULL)
		return (lst);
	return (ft_lstlast(lst->next));
}
