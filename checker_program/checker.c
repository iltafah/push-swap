/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:22:51 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 17:37:16 by iltafah          ###   ########.fr       */
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

void	process_given_instructions(t_ps_vars *vars)
{
	t_func_ptr	*func_ptr;
	t_map		*map;

	initialize_hashtable(&map);
	
	func_ptr = malloc(sizeof(t_func_ptr));
	func_ptr->type = first;
	func_ptr->args = stack_a;
	func_ptr->proto.first = swap_top_two_nums;
	insert_value(map, "sa", func_ptr);
	
	func_ptr = malloc(sizeof(t_func_ptr));
	func_ptr->type = first;
	func_ptr->args = stack_b;
	func_ptr->proto.first = swap_top_two_nums;
	insert_value(map, "sb", func_ptr);
	

	func_ptr = malloc(sizeof(t_func_ptr));
	func_ptr->type = first;
	func_ptr->args = stack_a;
	func_ptr->proto.first = shift_up_all_nums;
	insert_value(map, "ra", func_ptr);
	

	func_ptr = malloc(sizeof(t_func_ptr));
	func_ptr->type = first;
	func_ptr->args = stack_b;
	func_ptr->proto.first = shift_up_all_nums;
	insert_value(map, "rb", func_ptr);

	func_ptr = malloc(sizeof(t_func_ptr));
	func_ptr->type = first;
	func_ptr->args = stack_a;
	func_ptr->proto.first = shift_down_all_nums;
	insert_value(map, "rra", func_ptr);
	

	func_ptr = malloc(sizeof(t_func_ptr));
	func_ptr->type = first;
	func_ptr->args = stack_b;
	func_ptr->proto.first = shift_down_all_nums;
	insert_value(map, "rrb", func_ptr);
	
	func_ptr = malloc(sizeof(t_func_ptr));
	func_ptr->type = second;
	func_ptr->args = stack_a_b;
	func_ptr->proto.second = shift_up_both_stacks;
	insert_value(map, "rr", func_ptr);
	
	func_ptr = malloc(sizeof(t_func_ptr));
	func_ptr->type = second;
	func_ptr->args = stack_a_b;
	func_ptr->proto.second = shift_down_both_stacks;
	insert_value(map, "rrr", func_ptr);
	
	func_ptr = malloc(sizeof(t_func_ptr));
	func_ptr->type = second;
	func_ptr->args = stack_a_b;
	func_ptr->proto.second = push_from_to;
	insert_value(map, "pb", func_ptr);
	
	func_ptr = malloc(sizeof(t_func_ptr));
	func_ptr->type = second;
	func_ptr->args = stack_b_a;
	func_ptr->proto.second = push_from_to;
	insert_value(map, "pa", func_ptr);




	
	int		ret_num;
	char	*line;

	line = NULL;
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
