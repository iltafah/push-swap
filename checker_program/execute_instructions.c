/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:30:24 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 19:10:18 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_hashtable(t_map **map_add)
{
	int		i;
	
	i = 0;
	(*map_add) = malloc(sizeof(t_map) * map_size);
	while (i < map_size)
	{
		(*map_add)->item = NULL;
		(*map_add)->is_occupied = false;
		i++;
	}
}

t_item	*create_item(char *key, t_func_ptr *value)
{
	t_item *item;

	item = malloc(sizeof(t_item));
	item->key = ft_strdup(key);
	item->value = value;
	item->next = NULL;
	return (item);
}

int		hash_func(char *key)
{
	int	i;
	int	hashed_key;

	i = 0;
	hashed_key = 0;
	while (key[i] != '\0')
	{
		hashed_key += (key[i] * i);
		i++;
	}
	return (hashed_key);
}

void	insert_value(t_map *map, char *key, t_func_ptr *value)
{
	int		index;
	t_item	*curr_item;

	index = hash_func(key) % map_size;
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

t_func_ptr	*get_value(t_map *map, char *key)
{
	int		index;
	t_item	*curr_item;

	index = hash_func(key) % map_size;
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

void	execute_instructions(t_map *map, t_ps_vars *vars, char *instruction)
{
	t_func_ptr	*func_to_exec;

	func_to_exec = get_value(map, instruction);
	if (func_to_exec == NULL)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
	if (func_to_exec->args == stack_a)
		func_to_exec->proto.first(&vars->stack_a);
	else if (func_to_exec->args == stack_b)
		func_to_exec->proto.first(&vars->stack_b);
	else if (func_to_exec->args == stack_a_b)
		func_to_exec->proto.second(&vars->stack_a, &vars->stack_b);
	else if (func_to_exec->args == stack_b_a)
		func_to_exec->proto.second(&vars->stack_b, &vars->stack_a);
}
