/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_pop_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:44:37 by vivan-de          #+#    #+#             */
/*   Updated: 2022/12/10 11:05:35 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		validate_args(t_linked **list);
void	__linked_del_node(t_linked **list, t_node *node,
			t_linked_del_node_fn fn);

void	linked_pop_first(t_linked **list, t_linked_del_node_fn fn)
{
	t_node	*current_node;
	t_node	*next_node;

	if (!validate_args(list))
		return ;
	current_node = (*list)->head;
	if (!current_node)
		return ;
	next_node = current_node->next;
	__linked_del_node(list, current_node, fn);
	if ((*list)->size > 1 && next_node)
	{
		(*list)->head = next_node;
		(*list)->tail->next = next_node;
		(*list)->head->prev = (*list)->tail;
	}
}
