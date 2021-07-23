#include "./push_swap.h"

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
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		steps--;
	}
	while (steps < 0)
	{
		shift_up_all_nums(&vars->stack_a);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		steps++;
	}
}
