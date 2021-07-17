NAME = push_swap
LIB = libft

FLAGS = #-Wall -Wextra -Werror

SRC = ./push_swap.c \
./vectors/vector_of_int.c \
./find_median.c \
./get_max_num.c \
./get_min_num.c

OBJ = $(SRC:.c=.o)

all: $(NAME) 
	
$(NAME): $(OBJ)
	make -sC ./libft
	gcc -o $@ $^  ./libft/libft.a

%.o : %.c
	gcc $(FLAGS) -o $@ -c $^

clean :
		rm -f $(OBJ)
		make fclean -sC ./libft

fclean : clean
		rm -f $(NAME)

re : fclean all