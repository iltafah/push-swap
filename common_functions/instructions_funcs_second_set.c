/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_funcs_second_set.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:30:32 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 14:33:18 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_both_stacks(t_int_vec *stack_a, t_int_vec *stack_b)
{
	swap_top_two_nums(stack_a);
	swap_top_two_nums(stack_b);
}

void	shift_up_both_stacks(t_int_vec *stack_a, t_int_vec *stack_b)
{
	shift_up_all_nums(stack_a);
	shift_up_all_nums(stack_b);
}

void	shift_down_both_stacks(t_int_vec *stack_a, t_int_vec *stack_b)
{
	shift_down_all_nums(stack_a);
	shift_down_all_nums(stack_b);
}
