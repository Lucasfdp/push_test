#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
}   t_stack;

typedef struct s_data
{
    t_stack *a;
    t_stack *b;
}   t_data;

void    swap(t_stack **stack, char name, int print_op);
void    ss(t_stack **a, t_stack **b);
void    push(t_stack **src, t_stack **dest, char name, int print_op);
void    rotate(t_stack **stack, char name, int print_op);
void    rr(t_stack **a, t_stack **b);
void    reverse_rotate(t_stack **stack, char name, int print_op);
void    rrr(t_stack **a, t_stack **b);
t_stack	*ft_lstnew_ps(int content);
void	ft_lstadd_front_ps(t_stack **lst, t_stack *new);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
int     ft_lstsize_ps(t_stack *lst);
t_stack	*ft_lstlast_ps(t_stack *lst);
t_stack *parse_args(int argc, char **argv);
int	    ft_strlen_ps(char *str);
void    free_lst(t_stack *stack);
void    free_split(char **result, int count);
void    free_on_error(t_stack *stack_a, t_stack *stack_b, char **split, int count);
void    two_nums(t_stack **stack_a);
void    three_nums(t_stack **stack_a);
void    four_nums(t_stack **stack_a, t_stack **stack_b);
int     smallest_value(t_stack *stack_a);
void    five_nums(t_stack **stack_a, t_stack **stack_b);
void    six_nums(t_stack **stack_a, t_stack **stack_b);
int     *extracting_array(t_stack **stack_a);
void    sorting_array(int *array, int size);
void    assigning_index(t_stack **stack_a, int *array);
int     find_max_value(t_stack **stack_a);
void    radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
void    optimize_push_direction(t_stack **stack_a, t_stack **stack_b, int bit_pos);
t_stack *get_stack(int argc, char **argv);
void optimize_push_direction(t_stack **stack_a, t_stack **stack_b, int bit_pos);

#endif