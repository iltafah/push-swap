/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_best_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:24:14 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 09:53:45 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	shift_both_stacks_simultaneously(t_ps_vars *vars)
{
	while (vars->a_best_move != 0 && vars->b_best_move != 0)
	{
		if (vars->a_best_move > 0 && vars->b_best_move > 0)
		{
			shift_down_all_nums(&vars->stack_a);
			shift_down_all_nums(&vars->stack_b);
			vars->a_best_move--;
			vars->b_best_move--;
			ft_putstr_fd("rrr\n", STDOUT_FILENO);
		}
		else if (vars->a_best_move < 0 && vars->b_best_move < 0)
		{
			shift_up_all_nums(&vars->stack_a);
			shift_up_all_nums(&vars->stack_b);
			vars->a_best_move++;
			vars->b_best_move++;
			ft_putstr_fd("rr\n", STDOUT_FILENO);
		}
	}
}

void	shift_stack_a_with_remaining_moves(t_ps_vars *vars)
{
	while (vars->a_best_move != 0)
	{
		if (vars->a_best_move > 0)
		{
			shift_down_all_nums(&vars->stack_a);
			ft_putstr_fd("rra\n", STDOUT_FILENO);
			vars->a_best_move--;
		}
		else if (vars->a_best_move < 0)
		{
			shift_up_all_nums(&vars->stack_a);
			ft_putstr_fd("ra\n", STDOUT_FILENO);
			vars->a_best_move++;
		}
	}
}

void	shift_stack_b_with_remaining_moves(t_ps_vars *vars)
{
	while (vars->b_best_move != 0)
	{
		if (vars->b_best_move > 0)
		{
			shift_down_all_nums(&vars->stack_b);
			ft_putstr_fd("rrb\n", STDOUT_FILENO);
			vars->b_best_move--;
		}
		else if (vars->b_best_move < 0)
		{
			shift_up_all_nums(&vars->stack_b);
			ft_putstr_fd("rb\n", STDOUT_FILENO);
			vars->b_best_move++;
		}
	}
}

void	retrieve_best_num(t_ps_vars *vars)
{
	if (vars->a_best_move * vars->b_best_move > 0)
		shift_both_stacks_simultaneously(vars);
	if (vars->a_best_move != 0)
		shift_stack_a_with_remaining_moves(vars);
	if (vars->b_best_move != 0)
		shift_stack_b_with_remaining_moves(vars);
	push_from_to(&vars->stack_b, &vars->stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	retrieve_nums_from_b_in_perfect_spot(t_ps_vars *vars)
{
	while (vars->stack_b.used_size > 0)
	{
		find_best_movements(vars);
		retrieve_best_num(vars);
	}
}
