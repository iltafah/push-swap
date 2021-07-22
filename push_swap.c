/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 21:27:01 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/13 17:57:19 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int		is_curr_str_int(char *str)
{
	int	i;
	int	sign;
	long int num;
	long int s_num;

	i = 0;
	num = 0;
	sign = 1;
	s_num = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		num = (num * 10) + (str[i] - '0');
		s_num = num * sign;
		if (ft_isdigit(str[i]) == false || s_num < min_int || s_num > max_int)
			return (false);
		i++;
	}
	return (true);
}

void	check_arguments_content(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (is_curr_str_int(argv[i]) == false)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(0);
		}
		i++;
	}
	return ;
}

void	fill_stack_with_numbers(t_int_vec *stack_a, char **argv)
{
	int	i;
	int	num;

	i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		stack_a->add_new_element(stack_a, num);
		i++;
	}
}

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

int		find_num(t_int_vec given_stack, int num)
{
	int		i;

	i = 0;
	while (i < given_stack.used_size)
	{
		if (given_stack.elements[i] == num)
			return (found);
		i++;
	}
	return (not_found);
}

void	print_stack(t_int_vec stack)
{
	int		i;

	i = 0;
	while (i < stack.used_size)
	{
		printf(" %d ", stack.elements[i]);
		i++;
	}
	printf("\n");
}

int		get_index(t_int_vec given_stack, int num)
{
	int		i;

	i = 0;
	while (i < given_stack.used_size)
	{
		if (given_stack.elements[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int		is_it_sorted_circularly(t_int_vec given_stack, int num)
{
	int		prev_num;
	int		traversed;
	int		curr_index;
	int		starting_index;

	traversed = 0;
	prev_num = num;
	starting_index = get_index(given_stack, num);
	curr_index = starting_index + 1;
	if (curr_index > given_stack.last_index)
		curr_index = 0;
	while (traversed < given_stack.used_size - 1)
	{
		if (prev_num > given_stack.elements[curr_index])
			return (unsorted);
		prev_num = given_stack.elements[curr_index];
		curr_index++;
		if (curr_index == given_stack.used_size)
			curr_index = 0;
		traversed++;
	}
	return (sorted);
}

int		find_nearest_path(t_int_vec given_stack, int num_index)
{
	int		up_steps;
	int		down_steps;

	up_steps = num_index;
	down_steps = given_stack.used_size - num_index;
	if (up_steps < down_steps)
		return (up_steps * -1);
	return (down_steps);
}

void	fill_table_with_given_num(int *tab, int size, int num)
{
	int		i;

	i = 0;
	while (i < size)
	{
		tab[i] = num;
		i++;
	}
	return ;
}

int		get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);	
}

void	shift_min_to_top(t_int_vec given_stack)
{
	int		i;
	int		steps;
	int		min_num;
	int		min_num_index;

	i = 0;
	min_num = get_min_num(given_stack);
	min_num_index = get_index(given_stack, min_num);
	steps = find_nearest_path(given_stack, min_num_index);
	if (steps > 0)
	{
		while (steps > 0)
		{
			shift_down_all_nums(&given_stack);
			steps--;
		}
	}
	else if (steps < 0)
	{
		while (steps < 0)
		{
			shift_up_all_nums(&given_stack);
			steps++;
		}
	}
}

t_int_vec	get_stack_copy(t_int_vec given_stack)
{
	int			i;
	t_int_vec	stack_copy;

	i = 0;
	initialize_vec_of_int(&stack_copy);
	while (i < given_stack.used_size)
	{
		stack_copy.add_new_element(&stack_copy, given_stack.elements[i]);
		i++;
	}
	return (stack_copy);
}

int	*get_longest_inc_subseq_order(t_int_vec given_stack, int *max_order_num)
{
	int			i;
	int			j;
	int			*order_table;

	i = 1;
	order_table = malloc(sizeof(int) * given_stack.used_size);
	fill_table_with_given_num(order_table, given_stack.used_size, 1);
	while (i < given_stack.used_size)
	{
		j = 0;
		while (j < i)
		{
			if (given_stack.elements[i] > given_stack.elements[j])
			{
				order_table[i] = get_max(order_table[i], (order_table[j] + 1));
				if (order_table[i] > (*max_order_num))
					(*max_order_num) = order_table[i];
			}
			j++;
		}
		i++;
	}
	return (order_table);
}

t_int_vec	get_longest_inc_subseq_numbers(t_int_vec given_stack)
{
	int			i;
	int			j;
	int			*order_table;
	int			max_order_num;
	t_int_vec	lis_table;

	i = 1;
	max_order_num = 1;
	order_table = get_longest_inc_subseq_order(given_stack, &max_order_num);
	initialize_vec_of_int(&lis_table);
	i = given_stack.last_index;
	while (i >= 0)
	{
		if (max_order_num == order_table[i])
		{
			lis_table.push_element(&lis_table, given_stack.elements[i]);
			max_order_num--;
		}
		i--;
	}
	free(order_table);
	return (lis_table);
}

void	push_from_a_to_b(ps_vars *vars)
{
	int			i;
	int			to_traverse;
	t_int_vec	lngst_inc_subseq;
	t_int_vec	stack_a_copy;
	 
	i = 0;
	stack_a_copy = get_stack_copy(vars->stack_a);
	shift_min_to_top(stack_a_copy);
	lngst_inc_subseq = get_longest_inc_subseq_numbers(stack_a_copy);
	stack_a_copy.free(&stack_a_copy);
	to_traverse = vars->stack_a.used_size;
	while (i < to_traverse)
	{
		if (find_num(lngst_inc_subseq, vars->stack_a.elements[0]) == not_found)
		{
			push_from_to(&vars->stack_a, &vars->stack_b);
			printf("pb\n");
		}
		else
		{
			shift_up_all_nums(&vars->stack_a);
			printf("ra\n");	
		}
		i++;
	}
}

int		find_a_movements(t_int_vec stack_a, int num)
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
	if (num > max_num)
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
}

int		find_b_movements(t_int_vec stack_b, int num_index)
{
	return (find_nearest_path(stack_b, num_index));
}

int		absolute_value(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int		calc_total_moves(int a_moves, int b_moves)
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

void	find_best_movements(ps_vars *vars)
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

void	retrieve_best_num(ps_vars *vars)
{
	while (vars->a_best_move != 0 || vars->b_best_move != 0)
	{
		if (vars->a_best_move > 0 && vars->b_best_move > 0)
		{
			shift_down_all_nums(&vars->stack_a);
			shift_down_all_nums(&vars->stack_b);
			vars->a_best_move--;
			vars->b_best_move--;
			printf("rrr\n");
		}
		else if (vars->a_best_move < 0 && vars->b_best_move < 0)
		{
			shift_up_all_nums(&vars->stack_a);
			shift_up_all_nums(&vars->stack_b);
			vars->a_best_move++;
			vars->b_best_move++;
			printf("rr\n");
		}
		else if (vars->a_best_move > 0)
		{
			shift_down_all_nums(&vars->stack_a);
			printf("rra\n");
			vars->a_best_move--;
		}
		else if (vars->a_best_move < 0)
		{
			shift_up_all_nums(&vars->stack_a);
			printf("ra\n");
			vars->a_best_move++;
		}
		else if (vars->b_best_move > 0)
		{
			shift_down_all_nums(&vars->stack_b);
			printf("rrb\n");
			vars->b_best_move--;
		}
		else if (vars->b_best_move < 0)
		{
			shift_up_all_nums(&vars->stack_b);
			printf("rb\n");
			vars->b_best_move++;
		}
	}
	push_from_to(&vars->stack_b, &vars->stack_a);
	printf("pa\n");
}

void	retrieve_nums_from_b_in_perfect_spot(ps_vars *vars)
{
	while (vars->stack_b.used_size > 0)
	{
		// print_stack(vars->stack_a);
		// print_stack(vars->stack_b);
		find_best_movements(vars);
		retrieve_best_num(vars);
	}
}



void	sort_stack_a(ps_vars *vars)
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
		printf("rra\n");
		steps--;
	}
	while (steps < 0)
	{
		shift_up_all_nums(&vars->stack_a);
		printf("ra\n");
		steps++;
	}
}

void	swap_and_sort(ps_vars *vars)
{
	int		min_num;
	int		is_sorted_circularly;

	min_num = get_min_num(vars->stack_a);
	is_sorted_circularly = is_it_sorted_circularly(vars->stack_a, min_num);
	while (is_sorted_circularly == false)
	{
		swap_top_two_nums(&vars->stack_a);
		printf("sa\n");
		is_sorted_circularly = is_it_sorted_circularly(vars->stack_a, min_num);
		if (is_sorted_circularly == true)
			break ;
		shift_up_all_nums(&vars->stack_a);
		printf("ra\n");
	}
	sort_stack_a(vars);
}

int		main(int argc, char **argv)
{
	ps_vars		vars;

	if (argc > 1)
	{
		vars.total_moves = 0;
		vars.a_best_move = 0;
		vars.b_best_move = 0;
		initialize_vec_of_int(&vars.stack_a);
		initialize_vec_of_int(&vars.stack_b);
		check_arguments_content(argv + 1);
		fill_stack_with_numbers(&vars.stack_a, argv + 1);

		if (vars.stack_a.used_size <= 3)
			swap_and_sort(&vars);
		else
		{
			push_from_a_to_b(&vars);
			retrieve_nums_from_b_in_perfect_spot(&vars);
			sort_stack_a(&vars);
		}
	}
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
	
	return (0);
}
