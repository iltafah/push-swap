/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:55 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/16 19:40:19 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hash_table.h"

t_item	*create_item(char *key, t_func_ptr *value)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->key = key;
	item->value = value;
	item->next = NULL;
	return (item);
}

void	insert_value(t_map *map, char *key, t_func_ptr *value)
{
	int		index;
	t_item	*curr_item;

	index = hash_func(key) % MAP_SIZE;
	if (map[index].is_occupied == false)
	{
		map[index].item = create_item(key, value);
		map[index].is_occupied = true;
		return ;
	}
	curr_item = map[index].item;
	while (curr_item->next != NULL)
		curr_item = curr_item->next;
	curr_item->next = create_item(key, value);
}
