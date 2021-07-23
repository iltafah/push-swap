#include "./push_swap.h"

void	swap_and_sort(ps_vars *vars)
{
	int		min_num;
	int		is_sorted_circularly;

	min_num = get_min_num(vars->stack_a);
	is_sorted_circularly = is_it_sorted_circularly(vars->stack_a, min_num);
	while (is_sorted_circularly == false)
	{
		swap_top_two_nums(&vars->stack_a);
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		is_sorted_circularly = is_it_sorted_circularly(vars->stack_a, min_num);
		if (is_sorted_circularly == true)
			break ;
		shift_up_all_nums(&vars->stack_a);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}
	sort_stack_a(vars);
}
