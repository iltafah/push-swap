NAME = push_swap

CHECKER = checker

LIB = libft


FLAGS = #-Wall -Wextra -Werror

PS_SRC = ./find_num.c \
./swap_and_sort.c \
./get_index.c \
./instructions_funcs.c \
./get_max_num.c \
./push_from_a_to_b.c \
./sort_stack_a.c \
./get_longest_inc_subseq_numbers.c \
./find_best_movements.c \
./vectors/vector_of_int.c \
./is_it_sorted_circularly.c \
./find_nearest_path.c \
./retrieve_best_num.c \
./get_min_num.c \
./push_swap.c

CH_SRC = ./find_num.c \
./swap_and_sort.c \
./get_index.c \
./instructions_funcs.c \
./get_max_num.c \
./push_from_a_to_b.c \
./sort_stack_a.c \
./get_longest_inc_subseq_numbers.c \
./find_best_movements.c \
./vectors/vector_of_int.c \
./is_it_sorted_circularly.c \
./find_nearest_path.c \
./retrieve_best_num.c \
./get_min_num.c \
./get_next_line/get_next_line.c \
./get_next_line/get_next_line_utils.c \
./checker.c

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

fclean : clean
	rm -f $(NAME)

re : fclean all