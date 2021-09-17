/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:22:51 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/17 12:52:34 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_stack_sorted(t_int_vec given_stack)
{
	int		i;
	int		curr_num;
	int		next_num;

	i = 0;
	while (i < given_stack.last_index)
	{
		curr_num = given_stack.elements[i];
		next_num = given_stack.elements[i + 1];
		if (curr_num > next_num)
			return (unsorted);
		i++;
	}
	return (sorted);
}

void	execute_instructions(t_map *map, t_ps_vars *vars, char *instruction)
{
	t_func_ptr	*func_to_exec;

	func_to_exec = get_value(map, instruction);
	if (func_to_exec == NULL)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
	if (func_to_exec->args == stack_a)
		func_to_exec->proto.first(&vars->stack_a);
	else if (func_to_exec->args == stack_b)
		func_to_exec->proto.first(&vars->stack_b);
	else if (func_to_exec->args == stack_a_b)
		func_to_exec->proto.second(&vars->stack_a, &vars->stack_b);
	else if (func_to_exec->args == stack_b_a)
		func_to_exec->proto.second(&vars->stack_b, &vars->stack_a);
}

void	fill_hashtable_with_appropriate_data(t_map *map)
{
	int					i;
	static char			*instructions[11] = {
		"sa", "sb", "ss",
		"ra", "rb", "rr",
		"rra", "rrb", "rrr",
		"pa", "pb"
		};
	static t_func_ptr	arr[11] = {
		{.args = stack_a,	.proto.first = swap_top_two_nums},
		{.args = stack_b,	.proto.first = swap_top_two_nums},
		{.args = stack_a_b,	.proto.second = swap_both_stacks},
		{.args = stack_a,	.proto.first = shift_up_all_nums},
		{.args = stack_b,	.proto.first = shift_up_all_nums},
		{.args = stack_a_b,	.proto.second = shift_up_both_stacks},
		{.args = stack_a,	.proto.first = shift_down_all_nums},
		{.args = stack_b,	.proto.first = shift_down_all_nums},
		{.args = stack_a_b,	.proto.second = shift_down_both_stacks},
		{.args = stack_b_a,	.proto.second = push_from_to},
		{.args = stack_a_b,	.proto.second = push_from_to}
		};

	i = -1;
	while (++i < 11)
		insert_value(map, instructions[i], &arr[i]);
}

void	process_given_instructions(t_ps_vars *vars)
{
	t_map	*map;
	int		ret_num;
	char	*line;

	line = NULL;
	initialize_hashtable(&map);
	fill_hashtable_with_appropriate_data(map);
	while (true)
	{
		ret_num = get_next_line(STDIN_FILENO, &line);
		if (ret_num != 1)
			break ;
		execute_instructions(map, vars, line);
		free(line);
	}
	if (is_stack_sorted(vars->stack_a) == false || vars->stack_b.used_size != 0)
	{
		ft_putstr_fd("KO\n", STDOUT_FILENO);
		exit(1);
	}
	ft_putstr_fd("OK\n", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_ps_vars		vars;

	if (argc > 1)
	{
		vars.total_moves = 0;
		vars.a_best_move = 0;
		vars.b_best_move = 0;
		initialize_vec_of_int(&vars.stack_a);
		initialize_vec_of_int(&vars.stack_b);
		fill_stack_with_numbers(&vars.stack_a, argv + 1);
		check_duplication(vars.stack_a);
		process_given_instructions(&vars);
		vars.stack_a.free(&vars.stack_a);
		vars.stack_b.free(&vars.stack_b);
	}
	return (0);
}
