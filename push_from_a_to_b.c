#include "./push_swap.h"

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

void	push_from_a_to_b(ps_vars *vars)
{
	t_int_vec	lngst_inc_subseq;
	t_int_vec	stack_a_copy;
	 
	stack_a_copy = get_stack_copy(vars->stack_a);
	shift_min_to_top(stack_a_copy);
	lngst_inc_subseq = get_longest_inc_subseq_numbers(stack_a_copy);
	stack_a_copy.free(&stack_a_copy);
	while (vars->stack_a.used_size != lngst_inc_subseq.used_size)
	{
		if (find_num(lngst_inc_subseq, vars->stack_a.elements[0]) == not_found)
		{
			push_from_to(&vars->stack_a, &vars->stack_b);
			ft_putstr_fd("pb\n", STDOUT_FILENO);
		}
		else
		{
			shift_up_all_nums(&vars->stack_a);
			ft_putstr_fd("ra\n", STDOUT_FILENO);	
		}
	}
}
