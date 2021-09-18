/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hash_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:26:31 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/17 16:20:43 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hash_table.h"

void	free_hash_table(t_map **map)
{
	int		i;
	t_item	*curr_item_node;
	t_item	*next_item_node;

	i = 0;
	while (i < MAP_SIZE)
	{
		if ((*map)[i].is_occupied == true)
		{
			curr_item_node = (*map)[i].item;
			while (curr_item_node != NULL)
			{
				next_item_node = curr_item_node->next;
				free(curr_item_node);
				curr_item_node = next_item_node;
			}
		}
		i++;
	}
	free(*map);
	*map = NULL;
}
