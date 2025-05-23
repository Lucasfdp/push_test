/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_simple_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:14:08 by luferna3          #+#    #+#             */
/*   Updated: 2025/05/06 06:24:31 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*extracting_array(t_stack **stack_a)
{
	int		*array;
	int		i;
	int		count;
	t_stack	*temp;

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

void	sorting_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

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

void	assigning_index(t_stack **stack_a, int *array)
{
	int		i;
	int		size;
	t_stack	*temp;

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

int	find_max_bits(t_stack **stack_a)
{
	int		max;
	int		bits;
	t_stack	*temp;

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

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	bit_pos;
	int	max_bits;
	int	i;

	bit_pos = 0;
	max_bits = find_max_bits(stack_a);
	while (bit_pos < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*stack_a)->index >> bit_pos & 1))
				rotate(stack_a, 'a', 1);
			else
				push(stack_a, stack_b, 'b', 1);
			i++;
		}
		while (*stack_b)
			push(stack_b, stack_a, 'a', 1);
		bit_pos++;
	}
}
