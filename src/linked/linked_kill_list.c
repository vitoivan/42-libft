/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_kill_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:44:37 by vivan-de          #+#    #+#             */
/*   Updated: 2022/12/10 08:41:07 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		__linked_del_node(t_linked **list, t_node *node,
				t_linked_del_node_fn fn);

static int	validate_args(t_linked **list)
{
	if (!list)
		return (0);
	if (!*list)
		return (0);
	return (1);
}

void	linked_kill_list(t_linked **list, t_linked_del_node_fn fn)
{
	t_node	*current_node;
	t_node	*next_node;

	if (!validate_args(list))
		return ;
	current_node = (*list)->head;
	if ((*list)->size)
	{
		(*list)->tail->next = NULL;
		(*list)->head->prev = NULL;
		while ((*list)->size)
		{
			next_node = current_node->next;
			__linked_del_node(list, current_node, fn);
			if (next_node)
			{
				current_node = next_node;
				if (next_node->next)
					next_node = next_node->next;
			}
		}
	}
	free(*list);
	*list = NULL;
}
