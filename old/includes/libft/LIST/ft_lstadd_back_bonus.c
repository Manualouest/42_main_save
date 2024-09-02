/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:53:52 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/12/14 01:33:51 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIBFT/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	if (new == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		(*lst)->next = new;
		return ;
	}
	ft_lstadd_back(&(*lst)->next, new);
}
