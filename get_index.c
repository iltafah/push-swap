#include "./push_swap.h"

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
