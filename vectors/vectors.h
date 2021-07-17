#ifndef VECTOR_H
# define VECTOR_H
# include "stdlib.h"

/*
** ************************************************************************** **
								  int vector
** ************************************************************************** **
*/

typedef struct s_int_vec t_int_vec;

struct s_int_vec
{
	int		*elements;
	int		size;
	int		used_size;
	int		last_index;
	void	(*add_new_element)(t_int_vec *, int);
	void	(*add_new_element_at_index)(t_int_vec *, int , int);
	void	(*replace_element_at_index)(t_int_vec *, int , int);
	void	(*delete_element_at_index)(t_int_vec *, int);
	void	(*push_element)(t_int_vec *, int);
	void	(*pop_element)(t_int_vec *, int *);
	void	(*free)(t_int_vec *);
};


/*
** ************************************************************************** **
*/

char	*ft_strdup(const char *s1);
void    initialize_vec_of_int(t_int_vec *vec);
void    realloc_int_vector(t_int_vec *vec, int new_size);
void	add_new_int(t_int_vec *vec, int num);
void	delete_int_at_index(t_int_vec *vec, int index);
void    add_new_int_at_index(t_int_vec *vec, int num, int index);
void    replace_int_at_index(t_int_vec *vec, int num, int index);
void	int_vector_free(t_int_vec *vec);
void	push_int(t_int_vec *vec, int num);
void	pop_int(t_int_vec *vec, int *num_addr);

#endif