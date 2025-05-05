#include "push_swap.h"

void    free_lst(t_stack *stack)
{
    t_stack *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

void    free_split(char **result, int count)
{
    int i;

    if (!result)
        return ;
    i = 0;
    while (i < count)
        free(result[i++]);
    free(result);
}

void    free_on_error(t_stack *stack_a, t_stack *stack_b, char **split, int count)
{
    if (stack_a)
        free_lst(stack_a);
    if (stack_b)
        free_lst(stack_b);
    if (split)
        free_split(split, count);
}