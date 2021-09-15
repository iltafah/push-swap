/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_sorted_circularly.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:23:52 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 09:53:40 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_it_sorted_circularly(t_int_vec given_stack, int num)
{
	int		prev_num;
	int		traversed;
	int		curr_index;
	int		starting_index;

	traversed = 0;
	prev_num = num;
	starting_index = get_index(given_stack, num);
	curr_index = starting_index + 1;
	if (curr_index > given_stack.last_index)
		curr_index = 0;
	while (traversed < given_stack.used_size - 1)
	{
		if (prev_num > given_stack.elements[curr_index])
			return (unsorted);
		prev_num = given_stack.elements[curr_index];
		curr_index++;
		if (curr_index == given_stack.used_size)
			curr_index = 0;
		traversed++;
	}
	return (sorted);
}
