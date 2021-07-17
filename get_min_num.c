#include "./push_swap.h"

int		get_min_num(t_int_vec stack)
{
	int		i;
	int		min;

	i = 0;
	min = stack.elements[0];
	while (i < stack.used_size)
	{
		if (min > stack.elements[i])
			min = stack.elements[i];
		i++;
	}
	return (min);
}
