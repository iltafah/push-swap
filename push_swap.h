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
# include "./get_next_line/get_next_line.h"

typedef struct	ps_vars
{
	t_int_vec	stack_a;
	t_int_vec	stack_b;
	int			a_best_move;
	int			b_best_move;
	int			total_moves;
}				ps_vars;

enum 		e_bool {false, true};
enum 		e_found {not_found = -1, found = 1};
enum 		e_sort {unsorted, sorted};
enum 		e_int_boundaries {min_int = -2147483648, max_int = 2147483647};

void		sort_stack_a(ps_vars *vars);
int			get_min_num(t_int_vec stack);
int			get_max_num(t_int_vec stack);
void		swap_and_sort(ps_vars *vars);
void		push_from_a_to_b(ps_vars *vars);
void		find_best_movements(ps_vars *vars);
int			find_num(t_int_vec given_stack, int num);
int			get_index(t_int_vec given_stack, int num);
void		swap_top_two_nums(t_int_vec *given_stack);
void		shift_up_all_nums(t_int_vec *given_stack);
void		shift_down_all_nums(t_int_vec *given_stack);
void		retrieve_nums_from_b_in_perfect_spot(ps_vars *vars);
t_int_vec	get_longest_inc_subseq_numbers(t_int_vec given_stack);
int			find_nearest_path(t_int_vec given_stack, int num_index);
int			is_it_sorted_circularly(t_int_vec given_stack, int num);
void		push_from_to(t_int_vec *from_stack, t_int_vec *to_stack);

void	free_array(char ***array);
int		is_curr_arg_int(char *arg);
void	fill_stack_with_numbers(t_int_vec *stack_a, char **argv);
void	check_duplication(t_int_vec given_stack);


void	print_stack(t_int_vec stack);


#endif
