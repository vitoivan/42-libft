/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:44:37 by vivan-de          #+#    #+#             */
/*   Updated: 2022/12/10 11:56:08 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		validate_args(t_linked **list);

void	linked_foreach(t_linked **list, t_linked_foreach_fn fn)
{
	t_node			*current_node;
	unsigned int	i;

	if (!validate_args(list))
		return ;
	current_node = (*list)->head;
	i = 0;
	while (i++ < (*list)->size)
	{
		fn(current_node->content, i - 1);
		current_node = current_node->next;
	}
}
