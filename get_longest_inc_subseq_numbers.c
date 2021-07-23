#include "./push_swap.h"

int		get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);	
}

void	fill_table_with_given_num(int *tab, int size, int num)
{
	int		i;

	i = 0;
	while (i < size)
	{
		tab[i] = num;
		i++;
	}
	return ;
}

int	*get_longest_inc_subseq_order(t_int_vec given_stack, int *max_order_num)
{
	int			i;
	int			j;
	int			*order_table;

	i = 1;
	order_table = malloc(sizeof(int) * given_stack.used_size);
	fill_table_with_given_num(order_table, given_stack.used_size, 1);
	while (i < given_stack.used_size)
	{
		j = 0;
		while (j < i)
		{
			if (given_stack.elements[i] > given_stack.elements[j])
			{
				order_table[i] = get_max(order_table[i], (order_table[j] + 1));
				if (order_table[i] > (*max_order_num))
					(*max_order_num) = order_table[i];
			}
			j++;
		}
		i++;
	}
	return (order_table);
}

t_int_vec	get_longest_inc_subseq_numbers(t_int_vec given_stack)
{
	int			i;
	int			j;
	int			*order_table;
	int			max_order_num;
	t_int_vec	lis_table;

	i = 1;
	max_order_num = 1;
	order_table = get_longest_inc_subseq_order(given_stack, &max_order_num);
	initialize_vec_of_int(&lis_table);
	i = given_stack.last_index;
	while (i >= 0)
	{
		if (max_order_num == order_table[i])
		{
			lis_table.push_element(&lis_table, given_stack.elements[i]);
			max_order_num--;
		}
		i--;
	}
	free(order_table);
	return (lis_table);
}
