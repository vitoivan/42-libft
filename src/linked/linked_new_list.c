/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_new_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:41:35 by vivan-de          #+#    #+#             */
/*   Updated: 2022/12/09 21:18:56 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_linked	*linked_new_list(void)
{
	t_linked	*list;

	list = (t_linked *)malloc(sizeof(t_linked));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}
