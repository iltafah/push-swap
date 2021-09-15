/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:23:20 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 09:53:28 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_nearest_path(t_int_vec given_stack, int num_index)
{
	int		up_steps;
	int		down_steps;

	up_steps = num_index;
	down_steps = given_stack.used_size - num_index;
	if (up_steps < down_steps)
		return (up_steps * -1);
	return (down_steps);
}
