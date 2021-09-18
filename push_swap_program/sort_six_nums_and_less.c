/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_nums_and_less.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:23:09 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/18 13:10:49 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_six_nums_and_less(t_ps_vars *vars)
{
	while (vars->stack_a.used_size > 3)
	{
		push_from_to(&vars->stack_a, &vars->stack_b);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
	swap_and_sort(&vars->stack_a);
	retrieve_nums_from_b_in_perfect_spot(vars);
	sort_stack_a(&vars->stack_a);
}
