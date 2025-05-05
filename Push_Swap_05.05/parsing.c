#include "push_swap.h"

int    duplicate_num_check(t_stack *stack, int value)
{
    while (stack)
    {
        if (value == stack->value)
            return (1);
        stack = stack->next;
    }
    return (0);
}

int valid_num_check(char *num)
{
    int i;

    i = 0;
    if (num[i] == '-' || num[i] == '+')
        i++;
    if (!num[i])
        return (0);
    while (num[i])
    {
        if (num[i] < '0' || num[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*lstnode;

	if (!new || !lst)
		return ;
	lstnode = ft_lstlast_ps(*lst);
	if (!lstnode)
		*lst = new;
	else
		lstnode->next = new;
}

long long   ft_atoll(const char *str)
{
    long i = 0;
    long sign = 1;
    long result = 0;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0')
    {   
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

t_stack *parse_args(int argc, char **argv)
{
    t_stack *stack = NULL;
    int i = 1;
    long num;

    num = 0;
    while (i < argc)
    {
        if (!valid_num_check(argv[i]))
            return (free_lst(stack), NULL);
        num = ft_atoll(argv[i]);
        if (num < INT_MIN || num > INT_MAX || duplicate_num_check(stack, (int)num))
            return (free_lst(stack), NULL);
        ft_lstadd_back_ps(&stack, ft_lstnew_ps((int)num));
        i++;
    }
    return (stack);
}

t_stack *get_stack(int argc, char **argv)
{
    char    **args;
    t_stack *stack;
    int     i;

    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        if (!args)
            return (NULL);
        i = 0;
        while (args[i])
            i++;
        stack = parse_args(i, args);
        free_split(args, i);
        return (stack);
    }
    else
        return (parse_args(argc, argv));
}

// check for amount of digits for max int 