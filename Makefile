NAME = push_swap

CHECKER = checker

LIB = libft

FLAGS = -Wall -Wextra -Werror

PS_SRC = push_swap_program/push_swap.c  \
push_swap_program/find_num.c             \
push_swap_program/get_index.c             \
push_swap_program/get_min_num.c            \
push_swap_program/get_max_num.c             \
push_swap_program/sort_stack_a.c             \
push_swap_program/swap_and_sort.c             \
push_swap_program/push_from_a_to_b.c           \
push_swap_program/find_nearest_path.c           \
push_swap_program/retrieve_best_num.c            \
push_swap_program/find_best_movements.c           \
push_swap_program/sort_six_nums_and_less.c         \
push_swap_program/is_it_sorted_circularly.c         \
push_swap_program/get_longest_inc_subseq_numbers.c

CH_SRC = checker_program/checker.c            \
checker_program/hash_table/get_value.c         \
checker_program/hash_table/hash_func.c          \
checker_program/hash_table/insert_value.c        \
checker_program/hash_table/free_hash_table.c      \
checker_program/get_next_line/get_next_line.c      \
checker_program/hash_table/initialize_hashtable.c   \
checker_program/get_next_line/get_next_line_utils.c

COMMON_FUNC = common_functions/check_duplication.c \
common_functions/instructions_funcs_first_set.c     \
common_functions/instructions_funcs_second_set.c     \
common_functions/fill_stack_with_given_numbers.c


INT_VECTOR_FUNC = vector_of_int/push_int.c \
vector_of_int/pop_int.c                     \
vector_of_int/add_new_int.c                  \
vector_of_int/realloc_int_vector.c            \
vector_of_int/delete_int_at_index.c            \
vector_of_int/add_new_int_at_index.c            \
vector_of_int/replace_int_at_index.c             \
vector_of_int/initialize_vec_of_int.c

HDRS = push_swap.h \
checker_program/hash_table/hash_table.h

OBJS_DIR = ./objs

PS_OBJS = $(addprefix $(OBJS_DIR)/, $(PS_SRC:.c=.o))

CH_OBJS = $(addprefix $(OBJS_DIR)/, $(CH_SRC:.c=.o))

COMMON_FUNC_OBJS = $(addprefix $(OBJS_DIR)/, $(COMMON_FUNC:.c=.o))

INT_VECTOR_FUNC_OBJS = $(addprefix $(OBJS_DIR)/, $(INT_VECTOR_FUNC:.c=.o))

all: $(NAME) $(CHECKER)

$(NAME): $(PS_OBJS) $(COMMON_FUNC_OBJS) $(INT_VECTOR_FUNC_OBJS)
	make -sC ./libft
	gcc -o $@ $^ ./libft/libft.a

$(CHECKER): $(CH_OBJS) $(COMMON_FUNC_OBJS) $(INT_VECTOR_FUNC_OBJS)
	make -sC ./libft
	gcc -o $@ $^ ./libft/libft.a

$(OBJS_DIR)/%.o : %.c $(HDRS)
	@mkdir -p $(dir $@)
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(PS_OBJS) $(CH_OBJS) $(COMMON_FUNC_OBJS) $(INT_VECTOR_FUNC_OBJS)
	rm -rf $(OBJS_DIR)
	make fclean -sC ./libft

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all