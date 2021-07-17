#include "./push_swap.h"

int		get_max_num(t_int_vec stack)
{
	int		i;
	int		max;

	i = 0;
	max = stack.elements[0];
	while (i < stack.used_size)
	{
		if (max < stack.elements[i])
			max = stack.elements[i];
		i++;
	}
	return (max);
}
