/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_hashtable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:04 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/16 19:40:29 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hash_table.h"

void	initialize_hashtable(t_map **map_add)
{
	int		i;

	i = 0;
	(*map_add) = malloc(sizeof(t_map) * MAP_SIZE);
	while (i < MAP_SIZE)
	{
		(*map_add)[i].item = NULL;
		(*map_add)[i].is_occupied = false;
		i++;
	}
}
