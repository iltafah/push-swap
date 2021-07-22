/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 21:27:25 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/10 18:27:51 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# include "./vectors/vectors.h"
typedef struct	ps_vars
{
	t_int_vec	stack_a;
	t_int_vec	stack_b;
	int			a_best_move;
	int			b_best_move;
	int			total_moves;
}				ps_vars;

enum e_bool {false, true};
enum e_found {not_found = -1, found = 1};
enum e_state {descending, ascending};
enum e_sort {unsorted, sorted};
enum e_value {lower, greater};
enum e_int_boundaries {min_int = -2147483648, max_int = 2147483647};

float	find_median(t_int_vec stack);
int		get_min_num(t_int_vec stack);
int		get_max_num(t_int_vec stack);

#endif
//amez gisse