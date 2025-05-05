#include "push_swap.h"

int    *extracting_array(t_stack **stack_a)
{
    int *array;
    int i;
    int count;
    t_stack *temp;

    i = 0;
    count = 0;
    count = ft_lstsize_ps(*stack_a);
    array = (int *)malloc(sizeof(int) * count);
    temp = (*stack_a);
    while (temp)
    {
        array[i] = temp -> value;
        i++;
        temp = temp -> next;
    }
    return (array);
}

void    sorting_array(int *array, int size)
{
    int i;
    int j;
    int temp;

    i = 1;
    j = 0;
    temp = 0;
    while (i < size)
    {
        j = i;
        while (j > 0)
        {
            if (array[j] < array[j - 1])
            {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
            j--;
        }
        i++;
    }
}

void    assigning_index(t_stack **stack_a, int *array)
{
    int i;
    int size;
    t_stack *temp;

    i = 0;
    size = ft_lstsize_ps(*stack_a);
    while (i < size)
    {
        temp = *stack_a;
        while (temp)
        {
            if (array[i] == temp->value)
            {    
                temp->index = i;
                break ;
            }
            else
                temp = temp->next;
        }
        i++;
    }
}

int find_max_bits(t_stack **stack_a)
{
    int max;
    int bits;
    t_stack *temp;

    max = 0;
    bits = 0;
    temp = *stack_a;
    while (temp)
    {
        if (temp->index > max)
            max = temp->index;
        temp = temp->next;
    }
    while (max)
    {
        max /= 2;
        bits++;
    }
    return (bits);
}

void optimize_push_direction(t_stack **stack_a, t_stack **stack_b, int bit_pos)
{
    t_stack *temp;
    int pos_from_top;
    int pos_from_bottom;

    temp = *stack_a;
    pos_from_top = 0;
    pos_from_bottom = 0;
    while (temp)
    {
        if (((temp->index >> bit_pos) & 1) == 1)
            break;
        temp = temp->next;
        pos_from_top++;
    }
    if (!temp)
        return ;
    pos_from_bottom = ft_lstsize_ps(*stack_a) - pos_from_top;
    if (pos_from_top <= pos_from_bottom)
    {
        for (int i = 0; i < pos_from_top; i++)
            rotate(stack_a, 'a', 1);
    }
    else
    {
        for (int i = 0; i < pos_from_bottom; i++)
            reverse_rotate(stack_a, 'a', 1);
    }
    push(stack_a, stack_b, 'b', 1);
}


void    radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
    int bit_pos;
    int max_bits;
    int i;

    bit_pos = 0;
    max_bits = find_max_bits(stack_a);
    while (bit_pos < max_bits)
    {
        i = 0;
        while (i < size)
        {
            if (((*stack_a)->index >> bit_pos & 1))
                rotate(stack_a, 'a', 0);
            else
                push(stack_a, stack_b, 'b', 0);
            // optimize_push_direction(stack_a, stack_b, bit_pos);
            i++;
        }
        while (*stack_b)
            push(stack_b, stack_a, 'a', 1);
        bit_pos++;
    }
}

// void radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
// {
//     int bit_pos;
//     int max_bits;
//     int i;

//     bit_pos = 0;
//     max_bits = find_max_bits(stack_a);

//     while (bit_pos < max_bits)
//     {
//         i = 0;
//         while (i < size)
//         {
//             optimize_push_direction(stack_a, stack_b, bit_pos);
//             i++;
//         }

//         // After each pass, move all elements from stack_b to stack_a
//         // Just push elements back directly without rotations
//         while (*stack_b)
//         {
//             push(stack_b, stack_a, 'a', 1);  // Simply push from stack_b to stack_a
//         }

//         bit_pos++;
//     }
// }


void	push_chunk_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_start, int chunk_end)
{
	t_stack *a = *stack_a;
	int i = 0;
	int size = ft_lstsize_ps(*stack_a);

	while (i < size)
	{
		if (a->index >= chunk_start && a->index <= chunk_end)
		{
			push(stack_a, stack_b, 'b', 1);
			// Optional optimization: rotate B if index < middle of range
			if ((*stack_b)->index < (chunk_start + chunk_end) / 2)
				rotate(stack_b, 'b', 1);
		}
		else
			rotate(stack_a, 'a', 1);
		a = *stack_a;
		i++;
	}
}
