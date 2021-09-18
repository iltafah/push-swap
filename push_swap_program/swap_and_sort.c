/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:24:21 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/18 12:36:39 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_and_sort(t_int_vec *stack_a)
{
	int		min_num;
	int		is_sorted_circularly;

	min_num = get_min_num(*stack_a);
	is_sorted_circularly = is_it_sorted_circularly(*stack_a, min_num);
	while (is_sorted_circularly == false)
	{
		swap_top_two_nums(stack_a);
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		is_sorted_circularly = is_it_sorted_circularly(*stack_a, min_num);
		if (is_sorted_circularly == true)
			break ;
		shift_up_all_nums(stack_a);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}
}
