/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:18:56 by victor            #+#    #+#             */
/*   Updated: 2022/12/09 20:03:30 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	if (s == NULL)
		return (0);
	while (s[n])
		n++;
	return ((size_t)n);
}
