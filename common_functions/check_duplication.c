/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplication.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:59:54 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 10:00:11 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
