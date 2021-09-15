/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:23:48 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 09:53:38 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_from_to(t_int_vec *from_stack, t_int_vec *to_stack)
{
	int		poped_num;

	if (from_stack->used_size > 0)
	{
		from_stack->pop_element(from_stack, &poped_num);
		to_stack->push_element(to_stack, poped_num);
	}
}

void	swap_top_two_nums(t_int_vec *given_stack)
{
	int		keep;

	if (given_stack->used_size > 1)
	{
		keep = given_stack->elements[0];
		given_stack->elements[0] = given_stack->elements[1];
		given_stack->elements[1] = keep;
	}
}

void	shift_up_all_nums(t_int_vec *given_stack)
{
	int		keep;

	if (given_stack->used_size > 1)
	{
		keep = given_stack->elements[0];
		given_stack->delete_element_at_index(given_stack, 0);
		given_stack->add_new_element(given_stack, keep);
	}
}

void	shift_down_all_nums(t_int_vec *given_stack)
{
	int		keep;
	int		last_index;

	if (given_stack->used_size > 1)
	{
		last_index = given_stack->last_index;
		keep = given_stack->elements[last_index];
		given_stack->delete_element_at_index(given_stack, last_index);
		given_stack->push_element(given_stack, keep);
	}
}
