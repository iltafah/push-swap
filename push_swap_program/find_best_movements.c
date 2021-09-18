/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:23:11 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/18 13:19:11 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	absolute_value(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	calc_total_moves(int a_moves, int b_moves)
{
	if (a_moves * b_moves > 0)
	{
		if (absolute_value(a_moves) > absolute_value(b_moves))
			return (absolute_value(a_moves));
		else
			return (absolute_value(b_moves));
	}
	return (absolute_value(a_moves) + absolute_value(b_moves));
}

int	find_a_movements(t_int_vec stack_a, int num)
{
	int		i;
	int		min_num;
	int		max_num;
	int		last_index;
	int		min_num_index;

	i = 0;
	min_num = get_min_num(stack_a);
	max_num = get_max_num(stack_a);
	last_index = stack_a.last_index;
	if (num > max_num || num < min_num)
	{
		min_num_index = get_index(stack_a, min_num);
		return (find_nearest_path(stack_a, min_num_index));
	}
	else if (num < stack_a.elements[0] && num > stack_a.elements[last_index])
		return (0);
	while (i < last_index)
	{
		if (num > stack_a.elements[i] && num < stack_a.elements[i + 1])
			return (find_nearest_path(stack_a, i + 1));
		i++;
	}
	return (0);
}

int	find_b_movements(t_int_vec stack_b, int num_index)
{
	return (find_nearest_path(stack_b, num_index));
}

void	find_best_movements(t_ps_vars *vars)
{
	int		index;
	int		curr_num;
	int		curr_a_moves;
	int		curr_b_moves;
	int		curr_total_moves;

	index = 1;
	curr_num = vars->stack_b.elements[0];
	vars->a_best_move = find_a_movements(vars->stack_a, curr_num);
	vars->b_best_move = find_b_movements(vars->stack_b, 0);
	vars->total_moves = calc_total_moves(vars->a_best_move, vars->b_best_move);
	while (index < vars->stack_b.used_size)
	{
		curr_num = vars->stack_b.elements[index];
		curr_a_moves = find_a_movements(vars->stack_a, curr_num);
		curr_b_moves = find_b_movements(vars->stack_b, index);
		curr_total_moves = calc_total_moves(curr_a_moves, curr_b_moves);
		if (curr_total_moves < vars->total_moves)
		{
			vars->a_best_move = curr_a_moves;
			vars->b_best_move = curr_b_moves;
			vars->total_moves = curr_total_moves;
		}
		index++;
	}
}
