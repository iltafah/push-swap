/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:23:26 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 09:53:31 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_num(t_int_vec given_stack, int num)
{
	int		i;

	i = 0;
	while (i < given_stack.used_size)
	{
		if (given_stack.elements[i] == num)
			return (found);
		i++;
	}
	return (not_found);
}
