/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:52:06 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/17 12:52:58 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# define MAP_SIZE 11
# include "../../vector_of_int/vectors.h"
# include "../../libft/libft.h"

enum e_bool {false, true};
typedef enum e_type {first, second}	t_type;
typedef enum e_args {stack_a, stack_b, stack_a_b, stack_b_a}	t_args;

typedef struct s_map		t_map;
typedef struct s_item		t_item;
typedef union u_proto		t_proto;
typedef struct s_func_ptr	t_func_ptr;

union u_proto
{
	void	(*first)(t_int_vec *);
	void	(*second)(t_int_vec *, t_int_vec *);
};

struct s_func_ptr
{
	t_proto	proto;
	t_args	args;
};

struct s_item
{
	char		*key;
	t_func_ptr	*value;
	t_item		*next;
};

struct s_map
{
	t_item		*item;
	int			is_occupied;		
};

int			hash_func(char *key);
t_func_ptr	*get_value(t_map *map, char *key);
void		initialize_hashtable(t_map **map_add);
void		insert_value(t_map *map, char *key, t_func_ptr *value);

#endif
