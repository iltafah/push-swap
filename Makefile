NAME = push_swap

CHECKER = checker

LIB = libft


FLAGS = #-Wall -Wextra -Werror

PS_SRC = ./common_functions/find_num.c \
./common_functions/swap_and_sort.c \
./common_functions/check_duplication.c \
./common_functions/get_index.c \
./common_functions/instructions_funcs_first_set.c \
./common_functions/instructions_funcs_second_set.c \
./common_functions/get_max_num.c \
./common_functions/push_from_a_to_b.c \
./common_functions/sort_stack_a.c \
./common_functions/get_longest_inc_subseq_numbers.c \
./common_functions/find_best_movements.c \
./common_functions/fill_stack_with_given_numbers.c \
./common_functions/is_it_sorted_circularly.c \
./common_functions/find_nearest_path.c \
./common_functions/retrieve_best_num.c \
./common_functions/get_min_num.c \
./vector_of_int/add_new_int_at_index.c \
./vector_of_int/add_new_int.c \
./vector_of_int/delete_int_at_index.c \
./vector_of_int/initialize_vec_of_int.c \
./vector_of_int/pop_int.c \
./vector_of_int/push_int.c \
./vector_of_int/realloc_int_vector.c \
./vector_of_int/replace_int_at_index.c \
./push_swap.c

CH_SRC = ./common_functions/find_num.c \
./common_functions/get_index.c \
./common_functions/get_max_num.c \
./common_functions/sort_stack_a.c \
./common_functions/swap_and_sort.c \
./common_functions/push_from_a_to_b.c \
./common_functions/check_duplication.c \
./common_functions/find_nearest_path.c \
./common_functions/retrieve_best_num.c \
./common_functions/instructions_funcs_first_set.c \
./common_functions/instructions_funcs_second_set.c \
./common_functions/find_best_movements.c \
./common_functions/is_it_sorted_circularly.c \
./common_functions/fill_stack_with_given_numbers.c \
./common_functions/get_longest_inc_subseq_numbers.c \
./common_functions/get_min_num.c \
./get_next_line/get_next_line.c \
./get_next_line/get_next_line_utils.c \
./vector_of_int/pop_int.c \
./vector_of_int/push_int.c \
./vector_of_int/add_new_int.c \
./vector_of_int/realloc_int_vector.c \
./vector_of_int/delete_int_at_index.c \
./vector_of_int/add_new_int_at_index.c \
./vector_of_int/replace_int_at_index.c \
./vector_of_int/initialize_vec_of_int.c \
./checker_program/execute_instructions.c \
./checker_program/checker.c

PS_OBJ = $(PS_SRC:.c=.o)

CH_OBJ = $(CH_SRC:.c=.o)

all: $(NAME) 
	
$(NAME): $(PS_OBJ)
	make -sC ./libft
	gcc -o $@ $^ ./libft/libft.a

$(CHECKER): $(CH_OBJ)
	make -sC ./libft
	gcc -o $@ $^ ./libft/libft.a

%.o : %.c
	gcc $(FLAGS) -o $@ -c $^

clean:
	rm -f $(PS_OBJ) $(CH_OBJ)
	make fclean -sC ./libft

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all