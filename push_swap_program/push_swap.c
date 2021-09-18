/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 21:27:01 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/18 12:39:42 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_ps_vars(t_ps_vars *vars)
{
	vars->total_moves = 0;
	vars->a_best_move = 0;
	vars->b_best_move = 0;
	initialize_vec_of_int(&vars->stack_a);
	initialize_vec_of_int(&vars->stack_b);
}

int	main(int argc, char **argv)
{
	t_ps_vars		vars;

	if (argc > 1)
	{
		initialize_ps_vars(&vars);
		fill_stack_with_numbers(&vars.stack_a, argv + 1);
		check_duplication(vars.stack_a);
		if (vars.stack_a.used_size <= 6)
			sort_six_nums_and_less(&vars);
		else
		{
			push_from_a_to_b(&vars);
			retrieve_nums_from_b_in_perfect_spot(&vars);
			sort_stack_a(&vars.stack_a);
		}
		vars.stack_a.free(&vars.stack_a);
		vars.stack_b.free(&vars.stack_b);
	}
	return (0);
}
