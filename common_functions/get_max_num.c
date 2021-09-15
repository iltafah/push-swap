/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:23:41 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 09:53:35 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_num(t_int_vec stack)
{
	int		i;
	int		max;

	i = 0;
	max = stack.elements[0];
	while (i < stack.used_size)
	{
		if (max < stack.elements[i])
			max = stack.elements[i];
		i++;
	}
	return (max);
}
