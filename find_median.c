#include "./push_swap.h"

int		is_it_balanced(t_int_vec stack, int mid)
{
	int		i;
	int		balance;

	i = 0;
	balance = 0;
	while (i < stack.used_size)
	{
		if (stack.elements[i] > mid)
			balance++;
		else if (stack.elements[i] < mid)
			balance--;
		i++;
	}
	if (balance > 0)
		return (1);
	else if (balance < 0)
		return (-1);
	return (0);
}





float	find_median(t_int_vec stack)
{
	int		i;
	int		min;
	float	mid;
	int		max;
	int		is_balanced;

	i = -1;
	min = get_min_num(stack);
	max = get_max_num(stack);
	while (++i < stack.used_size)
	{
		if (stack.elements[i] > min && stack.elements[i] < max)
		{
			is_balanced = is_it_balanced(stack, stack.elements[i]);
			if (is_balanced == 1)
				min = stack.elements[i];
			else if (is_balanced == -1)
				max = stack.elements[i];
			else
				mid = stack.elements[i];
		}
	}
	if (stack.used_size % 2 == 0)
		mid = (min + max) / 2.0;
	return (mid);
}
