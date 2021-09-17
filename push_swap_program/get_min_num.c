/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:23:45 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 09:53:36 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_num(t_int_vec stack)
{
	int		i;
	int		min;

	i = 0;
	min = stack.elements[0];
	while (i < stack.used_size)
	{
		if (min > stack.elements[i])
			min = stack.elements[i];
		i++;
	}
	return (min);
}
