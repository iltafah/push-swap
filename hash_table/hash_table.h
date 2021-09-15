/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:52:06 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/15 17:38:34 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

#include "../vector_of_int/vectors.h"

typedef enum {first, second} t_type;
typedef enum {stack_a, stack_b, stack_a_b, stack_b_a} t_args;

typedef struct s_map t_map;
typedef struct s_item t_item;
typedef	union u_proto t_proto;
typedef	struct s_func_ptr t_func_ptr;

union u_proto
{
	void	(*first)(t_int_vec *);
	void	(*second)(t_int_vec *, t_int_vec *);
};

struct s_func_ptr
{
	t_proto	proto;
	t_type	type;
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

# define map_size 11

#endif
