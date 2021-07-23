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
		if (vars.stack_a.used_size <= 3)
			swap_and_sort(&vars);
		else
		{
			push_from_a_to_b(&vars);
			retrieve_nums_from_b_in_perfect_spot(&vars);
			sort_stack_a(&vars);
		}
		vars.stack_a.free(&vars.stack_a);
		vars.stack_b.free(&vars.stack_b);
	}
	return (0);
}
