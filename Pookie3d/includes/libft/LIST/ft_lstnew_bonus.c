/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:30:33 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/12/14 01:34:08 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIBFT/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}
