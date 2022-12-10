/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:08:13 by vivan-de          #+#    #+#             */
/*   Updated: 2022/12/10 11:52:54 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	validate_args(t_linked **list)
{
	if (!list)
		return (0);
	if (!*list)
		return (0);
	if (!(*list)->size)
		return (0);
	return (1);
}
