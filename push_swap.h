/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 21:27:25 by iltafah           #+#    #+#             */
/*   Updated: 2021/09/18 12:39:15 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# include "./vector_of_int/vectors.h"
# include "./checker_program/hash_table/hash_table.h"
# include "./checker_program/get_next_line/get_next_line.h"

typedef struct s_ps_vars
{
	t_int_vec	stack_a;
	t_int_vec	stack_b;
	int			a_best_move;
	int			b_best_move;
	int			total_moves;
}				t_ps_vars;

enum			e_found {not_found = -1, found = 1};
enum			e_sort {unsorted, sorted};
enum			e_int_boundaries {min_int = -2147483648, max_int = 2147483647};

void			free_array(char ***array);
int				is_curr_arg_int(char *arg);
void			print_stack(t_int_vec stack);
int				get_min_num(t_int_vec stack);
int				get_max_num(t_int_vec stack);
void			sort_stack_a(t_int_vec *stack_a);
void			swap_and_sort(t_int_vec *stack_a);
t_func_ptr		*get_value(t_map *map, char *key);
void			push_from_a_to_b(t_ps_vars *vars);
void			find_best_movements(t_ps_vars *vars);
void			initialize_hashtable(t_map **map_add);
void			sort_six_nums_and_less(t_ps_vars *vars);
void			check_duplication(t_int_vec given_stack);
int				find_num(t_int_vec given_stack, int num);
int				get_index(t_int_vec given_stack, int num);
void			swap_top_two_nums(t_int_vec *given_stack);
void			shift_up_all_nums(t_int_vec *given_stack);
void			shift_down_all_nums(t_int_vec *given_stack);
void			retrieve_nums_from_b_in_perfect_spot(t_ps_vars *vars);
t_int_vec		get_longest_inc_subseq_numbers(t_int_vec given_stack);
void			insert_value(t_map *map, char *key, t_func_ptr *value);
int				find_nearest_path(t_int_vec given_stack, int num_index);
int				is_it_sorted_circularly(t_int_vec given_stack, int num);
void			fill_stack_with_numbers(t_int_vec *stack_a, char **argv);
void			push_from_to(t_int_vec *from_stack, t_int_vec *to_stack);
void			fill_stack_with_numbers(t_int_vec *stack_a, char **argv);
void			swap_both_stacks(t_int_vec *stack_a, t_int_vec *stack_b);
void			shift_up_both_stacks(t_int_vec *stack_a, t_int_vec *stack_b);
void			shift_down_both_stacks(t_int_vec *stack_a, t_int_vec *stack_b);

#endif
