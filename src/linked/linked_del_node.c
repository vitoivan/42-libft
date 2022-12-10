/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_del_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:44:37 by vivan-de          #+#    #+#             */
/*   Updated: 2022/12/10 01:12:44 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	use_del_fn(t_node *node, t_linked_del_node_fn fn)
{
	if (fn)
		fn(node->content);
}

void	linked_del_node(t_linked **list, t_node *node, t_linked_del_node_fn fn)
{
	if (!node || !list)
		return ;
	if (!*list)
		return ;
	use_del_fn(node, fn);
	free(node);
	(*list)->size--;
	if ((*list)->size == 0)
	{
		(*list)->head = NULL;
		(*list)->tail = NULL;
	}
}
