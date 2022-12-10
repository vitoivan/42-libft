/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __linked_del_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:44:37 by vivan-de          #+#    #+#             */
/*   Updated: 2022/12/10 11:52:54 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	validate_args(t_linked **list, t_node *node)
{
	if (!node || !list)
		return (0);
	if (!*list)
		return (0);
	return (1);
}

static t_node	*get_the_last_one(t_node *node1, t_node *node2)
{
	if (node1)
		return (node1);
	if (node2)
		return (node2);
	return (NULL);
}

static void	del(t_node *node, t_linked_del_node_fn fn)
{
	if (fn)
		fn(node->content);
	free(node);
}

void	__linked_del_node(t_linked **list, t_node *node,
		t_linked_del_node_fn fn)
{
	t_node	*the_last_one;
	t_node	*prev_node;

	if (!validate_args(list, node))
		return ;
	the_last_one = node->next;
	prev_node = node->prev;
	del(node, fn);
	(*list)->size--;
	if ((*list)->size == 0)
	{
		(*list)->head = NULL;
		(*list)->tail = NULL;
	}
	else if ((*list)->size == 1)
	{
		the_last_one = get_the_last_one(the_last_one, prev_node);
		if (the_last_one)
		{
			(*list)->head = the_last_one;
			(*list)->tail = the_last_one;
			the_last_one->next = NULL;
			the_last_one->prev = NULL;
		}
	}
}
