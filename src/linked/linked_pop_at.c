/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_pop_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:44:37 by vivan-de          #+#    #+#             */
/*   Updated: 2022/12/10 13:36:46 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			validate_args(t_linked **lst);
void		__linked_del_node(t_linked **list, t_node *node,
				t_linked_del_node_fn fn);

static int	pop_in_extremes(t_linked **lst, t_byte i, t_linked_del_node_fn fn)
{
	if (i == 0)
	{
		linked_pop_first(lst, fn);
		return (1);
	}
	else if (i == (*lst)->size - 1)
	{
		linked_pop_last(lst, fn);
		return (1);
	}
	return (0);
}

static void	pop_thought_tail(t_linked **list, t_byte i, t_linked_del_node_fn fn)
{
	t_node	*current_node;
	t_node	*prev;
	t_node	*next;

	current_node = (*list)->tail;
	while (i-- > 0)
	{
		if (current_node)
			current_node = current_node->prev;
	}
	if (current_node && (*list)->size > 2)
	{
		prev = current_node->prev;
		next = current_node->next;
		__linked_del_node(list, current_node, fn);
		prev->next = next;
		next->prev = prev;
	}
}

static void	pop_thought_head(t_linked **list, t_byte i, t_linked_del_node_fn fn)
{
	t_node	*current_node;
	t_node	*prev;
	t_node	*next;

	current_node = (*list)->head;
	while (i-- > 0)
	{
		if (current_node)
			current_node = current_node->next;
	}
	if (current_node && (*list)->size > 2)
	{
		prev = current_node->prev;
		next = current_node->next;
		__linked_del_node(list, current_node, fn);
		prev->next = next;
		next->prev = prev;
	}
}

void	linked_pop_at(t_linked **lst, t_byte i, t_linked_del_node_fn fn)
{
	if (!validate_args(lst))
		return ;
	if (i > (*lst)->size - 1 || i < 0)
		return ;
	if (pop_in_extremes(lst, i, fn))
		return ;
	if (i > (*lst)->size / 2)
		pop_thought_tail(lst, i, fn);
	else
		pop_thought_head(lst, i, fn);
}
