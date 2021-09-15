/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_with_given_numbers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:53:07 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 19:07:02 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
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

int	is_curr_arg_int(char *arg)
{
	int			i;
	int			sign;
	long int	num;
	long int	s_num;

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

	i = -1;
	while (argv[++i])
	{
		splitted_arg = ft_split(argv[i], ' ');
		if (splitted_arg[0] == NULL)
			print_error_and_exit();
		j = -1;
		while (splitted_arg[++j] != NULL)
		{
			if (is_curr_arg_int(splitted_arg[j]) == false)
				print_error_and_exit();
			num = ft_atoi(splitted_arg[j]);
			stack_a->add_new_element(stack_a, num);
		}
		free_array(&splitted_arg);
	}
}
