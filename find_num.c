#include "./push_swap.h"

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
