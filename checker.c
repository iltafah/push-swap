#include "./push_swap.h"


void	free_array(char ***array)
{
	int		i;
	char	**curr_case;

	i = 0;
	curr_case = *array;
	while (curr_case[i] != NULL)
	{
		free(curr_case[i]);
		curr_case[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}

int		is_curr_arg_int(char *arg)
{
	int	i;
	int	sign;
	long int num;
	long int s_num;

	i = 0;
	num = 0;
	sign = 1;
	s_num = 0;
	if (arg[i] == '-')
		sign = -1;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '\0')
	{
		num = (num * 10) + (arg[i] - '0');
		s_num = num * sign;
		if (ft_isdigit(arg[i]) == false || s_num < min_int || s_num > max_int)
			return (false);
		i++;
	}
	return (true);
}

void	fill_stack_with_numbers(t_int_vec *stack_a, char **argv)
{
	int		i;
	int		j;
	int		num;
	char	**splitted_arg;

	i = 0;
	while (argv[i])
	{
		splitted_arg = ft_split(argv[i], ' ');
		j = 0;
		while (splitted_arg[j] != NULL)
		{
			if (is_curr_arg_int(splitted_arg[j]) == false)
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				exit(1);
			}
			num = ft_atoi(splitted_arg[j]);
			stack_a->add_new_element(stack_a, num);
			j++;
		}
		i++;
		free_array(&splitted_arg);
	}
}

void	check_duplication(t_int_vec given_stack)
{
	int		i;
	int		j;
	int		curr_num;

	i = 0;
	while (i < given_stack.last_index)
	{
		j = i + 1;
		curr_num = given_stack.elements[i];
		while (j <= given_stack.last_index)
		{
			if (curr_num == given_stack.elements[j])
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int		is_stack_sorted(t_int_vec given_stack)
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

void	execute_instructions(ps_vars *vars, char *instruction)
{
	if (strcmp("sa", instruction) == 0)
		swap_top_two_nums(&vars->stack_a);
	else if (strcmp("sb", instruction) == 0)
		swap_top_two_nums(&vars->stack_b);
	else if (strcmp("ss", instruction) == 0)
	{
		swap_top_two_nums(&vars->stack_a);
		swap_top_two_nums(&vars->stack_b);
	}
	else if (strcmp("ra", instruction) == 0)
		shift_up_all_nums(&vars->stack_a);
	else if (strcmp("rb", instruction) == 0)
		shift_up_all_nums(&vars->stack_b);
	else if (strcmp("rr", instruction) == 0)
	{
		shift_up_all_nums(&vars->stack_a);
		shift_up_all_nums(&vars->stack_b);
	}
	else if (strcmp("rra", instruction) == 0)
		shift_down_all_nums(&vars->stack_a);
	else if (strcmp("rrb", instruction) == 0)
		shift_down_all_nums(&vars->stack_b);
	else if (strcmp("rrr", instruction) == 0)
	{
		shift_down_all_nums(&vars->stack_a);
		shift_down_all_nums(&vars->stack_b);
	}
	else if (strcmp("pa", instruction) == 0)
		push_from_to(&vars->stack_b, &vars->stack_a);
	else if (strcmp("pb", instruction) == 0)
		push_from_to(&vars->stack_a, &vars->stack_b);
	else
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
}

void	process_given_instructions(ps_vars *vars)
{
	int		ret_num;
	char	*line;

	line = NULL;
	while (true)
	{
		ret_num = get_next_line(STDIN_FILENO, &line);
		if (ret_num != 1)
			break ;
		execute_instructions(vars, line);
		free(line);
	}
	if (is_stack_sorted(vars->stack_a) == false || vars->stack_b.used_size != 0)
	{
		ft_putstr_fd("KO\n", STDOUT_FILENO);
		exit(1);
	}
	ft_putstr_fd("OK\n", STDOUT_FILENO);
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
		fill_stack_with_numbers(&vars.stack_a, argv + 1);
		check_duplication(vars.stack_a);
		process_given_instructions(&vars);
		vars.stack_a.free(&vars.stack_a);
		vars.stack_b.free(&vars.stack_b);
	}
	return (0);
}