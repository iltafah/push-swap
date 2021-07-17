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

int		find_nearest_num(t_int_vec given_stack, int option, float num)
{
	int		upper_index;
	int		lower_index;

	upper_index = 0;
	lower_index = given_stack.last_index;
	if (option == greater)
	{
		while (upper_index <= lower_index)
		{
			if (given_stack.elements[upper_index] > num)
				return (upper_index);
			else if (given_stack.elements[lower_index] > num)
				return (lower_index);
			upper_index++;
			lower_index--;
		}
	}
	else if (option == lower)
	{
		while (upper_index <= lower_index)
		{
			if (given_stack.elements[upper_index] < num)
				return (upper_index);
			else if (given_stack.elements[lower_index] < num)
				return (lower_index);
			upper_index++;
			lower_index--;
		}
	}
	return (0);
}

int		find_num(t_int_vec given_stack, int num)
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

int		find_prec_num(t_int_vec given_stack, int num)
{
	int		i;
	int		prec_num_index;

	i = 0;
	prec_num_index = find_num(given_stack, get_min_num(given_stack));
	while (i < given_stack.used_size)
	{
		if (num > given_stack.elements[i] && given_stack.elements[i] > given_stack.elements[prec_num_index])
			prec_num_index = i;
		i++;
	}
	return (prec_num_index);
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

void	split_stack_a(ps_vars *vars)
{
	int	to_stop;
	int	up_steps;
	int	down_steps;
	int	index;

	to_stop = (vars->stack_a.used_size / 2) + (vars->stack_a.used_size % 2);
	if (to_stop < 3)
		to_stop = 3;
	while (vars->stack_a.used_size > to_stop)
	{
		index = find_nearest_num(vars->stack_a, lower, vars->median);
		up_steps = index;
		down_steps = vars->stack_a.used_size - index;
		if (up_steps < down_steps)
		{
			while (up_steps--)
			{
				shift_up_all_nums(&vars->stack_a);
				printf("ra\n");
			}
		}
		else
		{
			while (down_steps--)
			{
				shift_down_all_nums(&vars->stack_a);
				printf("rra\n");
			}
		}
		push_from_to(&vars->stack_a, &vars->stack_b);
		printf("pb\n");
	}
}



int		is_it_sorted_circularly(t_int_vec given_stack, int option, int num)
{
	int		prev_num;
	int		traversed;
	int		curr_index;
	int		starting_index;

	traversed = 0;
	prev_num = num;
	starting_index = find_num(given_stack, num);
	curr_index = starting_index + 1;								//bug
	if (curr_index > given_stack.last_index)
		curr_index = 0;
	while (traversed < given_stack.used_size - 1)
	{
		if ((prev_num > given_stack.elements[curr_index] && option == ascending)
			|| (prev_num < given_stack.elements[curr_index] && option == descending))
			return (unsorted);
		prev_num = given_stack.elements[curr_index];
		curr_index++;
		if (curr_index == given_stack.used_size)
			curr_index = 0;
		traversed++;
	}
	return (sorted);
}

void	swap_in_both_stacks(ps_vars *vars, int a_min_value, int a_max_value, int b_min_value, int b_max_value)
{
	int		swap_a;
	int		swap_b;

	swap_a = false;
	swap_b = false;
	if (vars->stack_a.used_size > 0 && vars->stack_a.elements[0] > vars->stack_a.elements[1] && !(vars->stack_a.elements[0] == a_max_value && vars->stack_a.elements[1] == a_min_value))
		swap_a = true;
	if (vars->stack_b.used_size > 0 && vars->stack_b.elements[0] < vars->stack_b.elements[1] && !(vars->stack_b.elements[0] == b_min_value && vars->stack_b.elements[1] == b_max_value))
		swap_b = true;
	
	if (swap_a == true && swap_b == true)
	{
		swap_top_two_nums(&vars->stack_a);
		swap_top_two_nums(&vars->stack_b);
		printf("ss\n");
	}
	else if (swap_a == true)
	{
		swap_top_two_nums(&vars->stack_a);
		printf("sa\n");
	}
	else if (swap_b == true)
	{
		swap_top_two_nums(&vars->stack_b);
		printf("sb\n");
	}
}

void	shift_in_both_stacks(ps_vars *vars, int a_min_value, int b_max_value)
{
	int		is_a_sorted;
	int		is_b_sorted;
	int		shift_a;
	int		shift_b;

	shift_a = false;
	shift_b = false;
	is_a_sorted = is_it_sorted_circularly(vars->stack_a, ascending, a_min_value);
	is_b_sorted = is_it_sorted_circularly(vars->stack_b, descending, b_max_value);
	if (is_a_sorted == false)
		shift_a = true;
	if (is_b_sorted == false)
		shift_b = true;
	if (shift_a == true && shift_b == true)
	{
		shift_up_all_nums(&vars->stack_a);
		shift_up_all_nums(&vars->stack_b);
		printf("rr\n");
	}
	else if (shift_a == true)
	{
		shift_up_all_nums(&vars->stack_a);
		printf("ra\n");
	}
	else if (shift_b == true)
	{
		shift_up_all_nums(&vars->stack_b);
		printf("rb\n");
	}
}

int		find_nearest_path(t_int_vec given_stack, int num)
{
	int	up;
	int	down;
	int	num_index;
	int	curr_index;

	up = 0;
	down = 0;
	num_index = find_num(given_stack, num);
	curr_index = num_index;
	while (curr_index > 0)
	{
		if (curr_index == given_stack.last_index + 1)
			break ;
		down++;
		curr_index++;
	}
	curr_index = num_index;
	while (curr_index > 0)
	{
		curr_index--;
		up--;
	}
	if ((up * -1) > (down))
		return (down);
	return (up);
}

int		*get_sorted_array(t_int_vec given_stack)
{
	int		i;
	int		j;
	int		keep;
	int		*sorted_array;

	i = 0;
	sorted_array = malloc(sizeof(int) * given_stack.used_size);
	while (i < given_stack.last_index)
	{
		j = i + 1;
		while (j <= given_stack.last_index)
		{
			if (given_stack.elements[i] > given_stack.elements[j])
			{
				keep = given_stack.elements[i];
				given_stack.elements[i] = given_stack.elements[j];
				given_stack.elements[j] = keep;
				sorted_array[i] = given_stack.elements[i];
			}
			j++;
		}
		i++;
	}
	sorted_array[i] = given_stack.elements[i];
	return (sorted_array);
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

int		find_following_num(t_int_vec given_stack, int num, int *found)
{
	int		i;
	int		curr_num;
	int		min_num;
	int		max_num;
	int		following_num;

	i = 0;
	*found = false;
	min_num = get_min_num(given_stack);
	max_num = get_max_num(given_stack);
	following_num = max_num;
	while (i < given_stack.used_size)
	{
		curr_num = given_stack.elements[i];
		if (curr_num > num && curr_num <= following_num)
		{
			following_num = curr_num;
			*found = true;
		}
		i++;
	}
	if (following_num == max_num && *found == false)
		following_num = min_num;
	return (following_num);
}

void	sort_both_stacks_circularly(ps_vars *vars)
{
	int		i = 0;
	int		curr_num;
	int		following_num;
	int		steps;
	int		is_found;
	int		is_a_sorted_circly;
	int		*stack_a_sorted;
	int		a_min_num;
	int		temp;

	a_min_num = get_min_num(vars->stack_a);
	is_a_sorted_circly = is_it_sorted_circularly(vars->stack_a, ascending, a_min_num);
	// stack_a_sorted = get_sorted_array(vars->stack_a);
	// print_stack(vars->stack_a);
	// for (int i = 0; i < vars->stack_a.used_size; i++)
	// 	printf("curr num = %d ---- following num = %d ---- is_found = %d\n", vars->stack_a.elements[i], find_following_num(vars->stack_a, vars->stack_a.elements[i], &is_found), is_found);
	print_stack(vars->stack_a);

	while (is_a_sorted_circly == false)
	{
		curr_num = vars->stack_a.elements[0];
		following_num = find_following_num(vars->stack_a, curr_num, &is_found);
		// if (is_found == true)
		// {
			// printf("following num : %d\n", following_num);
			steps = find_nearest_path(vars->stack_a, following_num);
			if (steps > 0)
			{
				temp = steps;
				while (temp > 0)
				{
					shift_down_all_nums(&vars->stack_a);
					printf("rra\n");
					temp--;
				}
				while (steps > 0)
				{
					swap_top_two_nums(&vars->stack_a);
					printf("sa\n");
					shift_up_all_nums(&vars->stack_a);
					printf("ra\n");
					steps--;
				}
			}
			else if (steps < 0)
			{
				temp = steps;
				while (temp < -1)
				{
					shift_up_all_nums(&vars->stack_a);
					printf("ra\n");
					temp++;
				}
				while (steps < -2)
				{
					swap_top_two_nums(&vars->stack_a);
					printf("sa\n");					
					shift_down_all_nums(&vars->stack_a);
					printf("rra\n");
					steps++;
				}
				swap_top_two_nums(&vars->stack_a);
				printf("sa\n");
			}
		else
		{
			shift_up_all_nums(&vars->stack_a);
			printf("ra\n");
		}
		is_a_sorted_circly = is_it_sorted_circularly(vars->stack_a, ascending, a_min_num);

		// i++;
		// if (i == 4)
		// 	exit(0);
	}
}

void	sort_both_stacks(ps_vars *vars)
{
	int	a_min_value;
	int b_max_value;
	int	a;
	int	b;

	a_min_value = get_min_num(vars->stack_a);
	b_max_value = get_max_num(vars->stack_b);
	a = find_nearest_path(vars->stack_a, a_min_value);
	b = find_nearest_path(vars->stack_b, b_max_value);
	if (a == 0 && b == 0)
		return ;
	
	if (a > 0)
	{
		while (a-- > 0)
		{
			shift_down_all_nums(&vars->stack_a);
			printf("rra\n");
		}
	}
	else if (a < 0)
	{
		while (a++ < 0)
		{
			shift_up_all_nums(&vars->stack_a);
			printf("ra\n");
		}
	}
	
	if (b > 0)
	{
		while (b-- > 0)
		{
			shift_down_all_nums(&vars->stack_b);
			printf("rrb\n");
		}
	}
	else if (b < 0)
	{
		while (b++ < 0)
		{
			shift_up_all_nums(&vars->stack_b);
			printf("rb\n");
		}
	}
}

void	pop_from_b_push_to_a(ps_vars *vars)
{
	while (vars->stack_b.used_size > 0)
	{
		push_from_to(&vars->stack_b, &vars->stack_a);
		printf("pa\n");
	}
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

// int		*get_sorted_table(int *tab, int size)
// {
// 	int	i;
// 	int j;
// 	int	keep;
// 	int	*sorted_table;

// 	i = 0;
// 	sorted_table = malloc(sizeof(int) * size);
// 	ft_memcpy(sorted_table, tab, sizeof(int) * size);
// 	while (i < (size - 1))
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (sorted_table[i] > sorted_table[j])
// 			{
// 				keep = sorted_table[i];
// 				sorted_table[i] = sorted_table[j];
// 				sorted_table[j] = keep;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (sorted_table);
// }

t_int_vec	get_longest_inc_subseq(int *tab, int size)
{
	int			i;
	int			j;
	int			*tmp;
	int			max_tmp_num;
	t_int_vec	lis_table;

	i = 1;
	max_tmp_num = 1;
	initialize_vec_of_int(&lis_table);
	tmp = malloc(sizeof(int) * size);
	fill_table_with_given_num(tmp, size, 1);
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] > tab[j])
			{
				tmp[i] = get_max(tmp[i], (tmp[j] + 1));
				if (tmp[i] > max_tmp_num)
					max_tmp_num = tmp[i];
			}
			j++;
		}
		i++;
		for (int x = 0; x < size; x++)
			printf(" %d", tab[x]);
		printf("\n");
		for (int x = 0; x < size; x++)
			printf(" %d", tmp[x]);
		printf("\n========================\n");
	}
	
	int		curr_value;
	
	i = size;
	curr_value = max_tmp_num;
	while (i >= 0)
	{
		if (curr_value == tmp[i])
		{
			lis_table.push_element(&lis_table, tab[i]);
			curr_value--;
		}
		i--;
	}
	return (lis_table);
}

int		get_num(t_int_vec vec, int num)
{
	int		i;

	i = 0;
	while (i < vec.used_size)
	{
		if (vec.elements[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

void	push_from_a_to_b(ps_vars *vars)
{
	int			i;
	t_int_vec	longest_inc_subseq;

	// int	steps = find_nearest_path(vars->stack_a, get_min_num(vars->stack_a));
	// if (steps > 0)
	// {
	// 	while (steps > 0)
	// 	{
	// 		steps--;
	// 	}
	// }
	
	 
	longest_inc_subseq = get_longest_inc_subseq(vars->stack_a.elements, vars->stack_a.used_size);
	
	for(int x = 0; x < longest_inc_subseq.used_size; x++)
		printf(" %d", longest_inc_subseq.elements[x]);
	printf("\n");
	// i = 0;
	// while (i < vars->stack_a.used_size)
	// {
	// 	if (get_num(longest_inc_subseq, vars->stack_a.elements[i]) == -1)
	// 	{
	// 		push_from_to(&vars->stack_a, &vars->stack_b);
	// 		printf("pb\n");
	// 	}
	// 	else
	// 	{
	// 		printf("<%d>\n", vars->stack_a.elements[i]);
	// 	}
	// 	shift_up_all_nums(&vars->stack_a);
	// 	printf("sa\n");
	// 	i++;
	// }
	// printf("Stack A\n");
	// print_stack(vars->stack_a);
	// printf("Stack B\n");
	// print_stack(vars->stack_b);
}




int		main(int argc, char **argv)
{
	ps_vars		vars;

	if (argc > 1)
	{
		initialize_vec_of_int(&vars.stack_a);
		initialize_vec_of_int(&vars.stack_b);
		check_arguments_content(argv + 1);
		fill_stack_with_numbers(&vars.stack_a, argv + 1);

		push_from_a_to_b(&vars);

	}
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
	
	return (0);
}
