// void optimize_push_direction(t_stack **stack_a, t_stack **stack_b, int bit_pos)
// {
// 	t_stack *temp;
// 	int pos_from_top;
// 	int pos_from_bottom;

// 	temp = *stack_a;
// 	pos_from_top = 0;
// 	pos_from_bottom = 0;
// 	while (temp)
// 	{
// 		if (((temp->index >> bit_pos) & 1) == 1)
// 			break;
// 		temp = temp->next;
// 		pos_from_top++;
// 	}
// 	if (!temp)
// 		return ;
// 	pos_from_bottom = ft_lstsize_ps(*stack_a) - pos_from_top;
// 	if (pos_from_top <= pos_from_bottom)
// 	{
// 		for (int i = 0; i < pos_from_top; i++)
// 			rotate(stack_a, 'a', 1);
// 	}
// 	else
// 	{
// 		for (int i = 0; i < pos_from_bottom; i++)
// 			reverse_rotate(stack_a, 'a', 1);
// 	}
// 	push(stack_a, stack_b, 'b', 1);
// }

// void	push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_start, int chunk_end)
// {
// 	t_stack *a = *stack_a;
// 	int i = 0;
// 	int size = ft_lstsize_ps(*stack_a);

// 	while (i < size)
// 	{
// 		if (a->index >= chunk_start && a->index <= chunk_end)
// 		{
// 			push(stack_a, stack_b, 'b', 1);
// 			// Optional optimization: rotate B if index < middle of range
// 			if ((*stack_b)->index < (chunk_start + chunk_end) / 2)
// 				rotate(stack_b, 'b', 1);
// 		}
// 		else
// 			rotate(stack_a, 'a', 1);
// 		a = *stack_a;
// 		i++;
// 	}
// }

// void	two_nums(t_stack **stack_a)
// {
// 	t_stack	*temp;

// 	temp = (*stack_a)->next;
// 	if (((*stack_a)->value) > (temp->value))
// 		swap(stack_a, 'a', 1);
// }

// char	**handle_nums(int ac, char *av[], char **args, int *count)
// {
// 	if (ac == 2)
// 	{
// 		args = ft_split(av[1], ' ');
// 		if (!args || !args[0])
// 			return (free_split(args, *count), NULL);
// 		while (args[*count])
// 			(*count)++;
// 	}
// 	else
// 	{
// 		args = av + 1;
// 		*count = ac - 1;
// 	}
// 	return (args);
// }