/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:20:51 by vivan-de          #+#    #+#             */
/*   Updated: 2022/12/10 08:17:37 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_H
# define LINKED_H

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_linked
{
	t_node			*head;
	t_node			*tail;
	unsigned int	size;
}					t_linked;

typedef void		(*t_linked_del_node_fn)(void *content);
typedef void		(*t_linked_foreach_fn)(void *content);
typedef void		*(*t_linked_map_fn)(void *content);
typedef int			(*t_linked_filter_fn)(void *content);

t_linked			*linked_new_list(void);
t_node				*linked_new_node(void *content);
void				linked_add_back(t_linked **list, t_node *node);
void				linked_add_front(t_linked **list, t_node *node);
void				linked_del_node(t_linked **list, t_node *node,
						t_linked_del_node_fn fn);
void				linked_kill_list(t_linked **list, t_linked_del_node_fn fn);
t_linked			*linked_map(t_linked **list, t_linked_map_fn fn);
void				linked_foreach(t_linked **list, t_linked_foreach_fn fn);
t_linked			*linked_filter(t_linked **list, t_linked_filter_fn fn);

#endif