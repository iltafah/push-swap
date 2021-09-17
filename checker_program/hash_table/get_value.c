/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:35:49 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/16 19:16:12 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hash_table.h"

t_func_ptr	*get_value(t_map *map, char *key)
{
	int		index;
	t_item	*curr_item;

	index = hash_func(key) % MAP_SIZE;
	if (map[index].is_occupied == false)
		return (NULL);
	curr_item = map[index].item;
	while (curr_item != NULL)
	{
		if (ft_strcmp(curr_item->key, key) == 0)
			return (curr_item->value);
		curr_item = curr_item->next;
	}
	return (NULL);
}
