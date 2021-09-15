/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:24:18 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 09:53:47 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack_a(t_ps_vars *vars)
{
	int		steps;
	int		min_num;
	int		min_num_index;

	min_num = get_min_num(vars->stack_a);
	min_num_index = get_index(vars->stack_a, min_num);
	steps = find_nearest_path(vars->stack_a, min_num_index);
	while (steps > 0)
	{
		shift_down_all_nums(&vars->stack_a);
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		steps--;
	}
	while (steps < 0)
	{
		shift_up_all_nums(&vars->stack_a);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		steps++;
	}
}
